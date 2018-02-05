#include "pokemonserver.h"
#include "ui_pokemonserver.h"

PokemonServer::PokemonServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PokemonServer)
{
    ui->setupUi(this);
    this->setWindowTitle("PokemonServer");
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slotCreateTcpServer()));
    ui->lineEdit->setText(QString::number(6666));

//--------------------------创建数据库---------------------------------

    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");//采用QSQLITE数据库
    db.setDatabaseName("Pokemon0000.db");  //每次构建时因为表的重名会导致下面的数据库表显示创建失败，因此可以改变数据库名重新构建
    db.setHostName("localhost");//设置数据库主机名
    if(db.open())
    {
         qDebug()<<"连接成功";
    }

//-------------------------创建两张数据库表------------------------------

    QSqlQuery query(db);
    bool is_success1 = query.exec("create table userdata(ID varchar primary key,Password varchar, pet_number int, "
                                  "is_online int,win int,total_game int)");
    if(is_success1){
        qDebug() << "用户数据库表创建成功！";
    }
    else{
        qDebug() << "用户数据库表创建失败！";
    }
    bool is_success2 = query.exec("create table pokemondata(ID varchar,p_id varchar,type int,p_level int,"
                                  "exp int)");
    if(is_success2){
        qDebug() << "精灵数据库表创建成功！";
    }
    else{
        qDebug() << "精灵数据库表创建失败！";
    }

//------------------------设置定时显示-----------------------

    QTimer *time=new QTimer(this);
    time->setInterval(1000);
    connect(time,SIGNAL(timeout()),this,SLOT(showdatabase()));
    time->start();
}

PokemonServer::~PokemonServer()
{
    delete ui;
}

void PokemonServer::slotCreateTcpServer()
{
    //qDebug()<<"get signal";
    Pokemonserver = new QTcpServer(this);
    Pokemonsocket = new QTcpSocket(this);

    connect(Pokemonsocket,SIGNAL(readyRead()),this,SLOT(receivemsg()));
    connect(Pokemonsocket,SIGNAL(disconnected()),Pokemonsocket,SLOT(deleteLater()));
    Pokemonsocket -> connectToHost(QHostAddress::Any,6666);
    if(!Pokemonserver -> listen(QHostAddress::Any,6666))
    {
        qDebug()<< Pokemonserver -> errorString();
        close();
    }
    connect(Pokemonserver,SIGNAL(newConnection()),this,SLOT(newconnect()));//监听到新的用户连接请求时处理
    ui->pushButton->setEnabled(false);
}

void PokemonServer::showdatabase()
{
    static QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("select * from userdata;"));
    ui->tableView->setModel(model);

    static QSqlQueryModel *model1 = new QSqlQueryModel(ui->tableView);
    model1->setQuery(QString("select * from pokemondata;"));
    ui->tableView_2->setModel(model1);
}

void PokemonServer::newconnect()
{
    this->Pokemonsocket = Pokemonserver->nextPendingConnection();
    connect(Pokemonsocket,SIGNAL(readyRead()),this,SLOT(receivemsg()));
}

void PokemonServer::sendmsg(int i)                 //向用户发送信息的函数
{
    QByteArray array;
    switch(i)
    {
        case 1:                                 //发送用户信息
            this->str = "U"+ database.tempid +"#"+                     //包括用户名，精灵数，是否在线，获胜场次，总场次
                        QString::number(database.temppetmun,10)+"#"+   //以十进制转换
                        QString::number(database.temponline,10)+"#"+
                        QString::number(database.tempwin,10)+"#"+
                        QString::number(database.temptotalgame,10)+"#"+
                        QString::number(highpet,10)+"#";

            array.append(str);
            Pokemonsocket -> write(array);
            qDebug()<<str;
            break;

        case 2:                                  //发送精灵信息
            this->str = "P"+ database.tempid +"#"+
                     database.tempp_id +"#"+
                     QString::number(database.temptype,10)+"#"+   //以十进制转换
                     QString::number(database.temp_level,10)+"#"+
                     QString::number(database.tempexp,10)+"#";
            array.append(str);
            Pokemonsocket -> write(array);
            qDebug()<<str;
            break;

        case 3:                                 //用户名账号不匹配
            str="errorpassword";                //发送错误信息
            array.append(str);
            Pokemonsocket -> write(array);
            break;

        case 4:                               //发现重复的账号
            str="existthisid";              //发送错误信号
            array.append(str);
            Pokemonsocket -> write(array);
            break;

        case 5:                                //账号创建成功
            str="creatsucceed";              //发送成功信号
            array.append(str);
            Pokemonsocket -> write(array);
            break;

        case 6:                                 //没有找到id
            str="nothisid";              //发送未找到id信号
            array.append(str);
            Pokemonsocket -> write(array);
            break;
        case 7:
            str="quitsucceed";
            array.append(str);
            Pokemonsocket -> write(array);
            break;
        case 8:                                //发送在线用户的名字
            this->str=database.gettotal();
            array.append(str);
            Pokemonsocket -> write(array);
            qDebug()<<str;
            break;
        case 9:                                    //没有找到这个精灵
            str="nothispokemon";              //发送错误信号
            array.append(str);
            Pokemonsocket -> write(array);
            break;
        case 10:                              //无效的接收消息
            str="unusemsg";              //发送错误信号
            array.append(str);
            Pokemonsocket -> write(array);
            break;
      }
}

void PokemonServer::receivemsg()              //收到消息时的处理
{

        str =Pokemonsocket->readAll();
        qDebug()<<str;
        ui->lineEdit_2->setText(this->str);

//-----------------------------------------------------------------------
        if(this->str.at(0)=='C')    //如果是用户注册信息 creat
        {

            QString id,pass;
            int id_len = 0,pass_len = 0;

            for(int i=1;this->str.at(i)!='#';i++)
            {
                 id_len++;
            }
            for(int j=id_len+2;this->str.at(j)!='#';j++)
            {
                 pass_len++;
            }

            id= this->str.mid(1,id_len);
            pass = this->str.mid(id_len+2,pass_len);

            if(database.insert(id,pass) == false)
                {sendmsg(4);}         //如果id存在
            else
                {sendmsg(5);} //如果id不存在,创建成功
        }

//-----------------------------------------------------------------------
        else if(this->str.at(0)=='L')    //如果是用户登录信息login
        {
            QString id,pass;
            int id_len = 0,pass_len = 0;

            for(int i=1;this->str.at(i)!='#';i++)
            {                                           //截取ID
                id_len++;
            }
            for(int j=id_len+2;this->str.at(j)!='#';j++)
            {                                           //截取密码
                pass_len++;
            }

            id= this->str.mid(1,id_len);
            this->quitname=id;
            pass = this->str.mid(id_len+2,pass_len);

            database.checkuser(id);
            this->highpet=database.checkhighlevelpet(id);
            if( id == database.tempid)
            {
                if(database.temppassword == pass)//用户的账号和密码匹配，则用户成功登陆，设置用户状态为在线
                {

                    database.tempid=id;
                    database.temponline=1;

                    sendmsg(1);
                    database.update(database.tempid,database.temppassword,database.temppetmun,database.temponline,database.tempwin,database.temptotalgame);

                }
                else
                sendmsg(3);  //发送密码错误的消息
            }
            else
                sendmsg(6);  //没有这个账号
       }

//-----------------------------------------------------------------------
       else if(this->str.at(0)=='P')       //查询宠物信息的处理pokemon
       {
            QString id,pid;
            int id_len = 0,pid_len=0;

            for(int i=1;this->str.at(i)!='#';i++)
            {
                 id_len++;
            }
            for(int j=id_len+2;this->str.at(j)!='#';j++)
            {
                 pid_len++;
            }

            id= this->str.mid(1,id_len);
            pid=this->str.mid(id_len+2,pid_len);


            database.checkpokemon(id,pid);
            if( id == database.tempid)
            {
                if(database.tempp_id ==pid)//
                    sendmsg(2);
                else
                    sendmsg(9);
            }
            else
            {
                qDebug()<<"该精灵不存在！";
                sendmsg(9);
            }//发送错误的消息
       }

//-----------------------------------------------------------------------
       else if(this->str.at(0)=='U')       //查询用户信息的处理user
       {
             QString id;
             int id_len = 0;

             for(int i=1;this->str.at(i)!='#';i++)
             {
                  id_len++;
             }

             id= this->str.mid(1,id_len);

             database.checkuser(id);
             this->highpet=database.checkhighlevelpet(id);
             if( id == database.tempid)
             {
                     sendmsg(1);                //发送该用户的ID 精灵数，在线状态，获胜场次，总场次
             }
             else
                 sendmsg(6);  //发送密码错误的消息
       }

//-----------------------------------------------------------------------
       else if(this->str.at(0)=='E')     //用户的退出处理exit
       {
            QString id;
            id=quitname;
            database.checkuser(id);
            if( id == database.tempid)
            {
                 database.update(id,database.temppassword,database.temppetmun,0,database.tempwin,database.temptotalgame);
                 sendmsg(7);                     //将状态设置为0，表示用户下线并发送退出成功消息
            }
            else
                sendmsg(6);  //没有这个账号
       }

//-----------------------------------------------------------------------
       else if(this->str.at(0)=='G')      //查询总的在线用户gettotal
       {
            sendmsg(8);
       }

//-----------------------------------------------------------------------
       else if(this->str.at(0)=='A')       //升级赛的结果更新处理，关键字A，决斗赛的结果也由此模块处理更新内容
       {
            QString id,pid;
            int f2result,f2level,f2exp;
            int id_len = 0,pid_len =0,level_len=0,exp_len=0;
            for(int i=1;this->str.at(i)!='#';i++)
            {
                id_len++;
            }
            for(int j=id_len+2;this->str.at(j)!='#';j++)
            {
                pid_len++;
            }
            for(int k=id_len+pid_len+5;this->str.at(k)!='#';k++)
            {
                level_len++;
            }
            for(int m=id_len+pid_len+level_len+6;this->str.at(m)!='#';m++)
            {
                exp_len++;
            }
            id=str.mid(1,id_len);
            pid=str.mid(id_len+2,pid_len);
            f2result=str.mid(id_len+pid_len+3,1).toInt();
            f2level=str.mid(id_len+pid_len+5,level_len).toInt();
            f2exp=str.mid(id_len+pid_len+level_len+6,exp_len).toInt();
            database.checkuser(id);
            if(f2result==1)
            {
                database.tempwin++;
                database.temptotalgame++;
                database.update(id,database.temppassword,database.temppetmun,database.temponline,database.tempwin,database.temptotalgame);
            }
            else if(f2result==0)
            {
                database.temptotalgame++;
                database.update(id,database.temppassword,database.temppetmun,database.temponline,database.tempwin,database.temptotalgame);
            }
            database.checkpokemon(id,pid);
            database.updatapokemon(id,pid,database.temptype,f2level,f2exp);
       }

//-----------------------------------------------------------------------
        else if(this->str.at(0)=='B')        //决斗赛获胜的信息处理,
        {
            QString id,pid;                 //B000#1#1#1#0#1#1#  名字，精灵编号，结果，等级，经验，对手类型，对手等级
            int result,level,exp,addtype,addlevel;
            int id_len=0,level_len=0,addlevel_len=0,exp_len=0;
            for(int i=1;this->str.at(i)!='#';i++)
            {
                 id_len++;
            }

            for(int k=id_len+6;this->str.at(k)!='#';k++){
                level_len++;
            }

            for(int m=id_len+level_len+7;this->str.at(m)!='#';m++){
                exp_len++;
            }

            for(int j=id_len+level_len+exp_len+10;this->str.at(j)!='#';j++){
                addlevel_len++;
            }

            id=str.mid(1,id_len);
            pid=str.mid(id_len+2,1).toInt();
            result=str.mid(id_len+4,1).toInt();
            level=str.mid(id_len+6,level_len).toInt();
            exp=str.mid(id_len+level_len+7,exp_len).toInt();
            addtype=str.mid(id_len+level_len+exp_len+8,1).toInt();
            addlevel=str.mid(id_len+level_len+exp_len+10,addlevel_len).toInt();

            database.checkuser(id);
            if(database.temppetmun<6)
            {
                database.temppetmun++;
                database.tempwin++;
                database.temptotalgame++;
                database.update(id,database.temppassword,database.temppetmun,database.temponline,database.tempwin,database.temptotalgame);
                database.insertpet(id,database.temppetmun,addtype,addlevel);
            }
            else if(database.temppetmun==6)
            {
                database.tempwin++;
                database.temptotalgame++;
                database.update(id,database.temppassword,database.temppetmun,database.temponline,database.tempwin,database.temptotalgame);
            }
       }

//-----------------------------------------------------------------------
        else if(this->str.at(0)=='D')     //处理决斗赛失败的信息
        {
            QString id,pid;                 //B000#1#1#1#0#1#1#  名字，精灵编号，结果，等级，经验，对手类型，对手等级
            int result,level,exp,delpid;
            int id_len=0,level_len=0,exp_len=0;
            for(int i=1;this->str.at(i)!='#';i++)
            {
                 id_len++;
            }

            for(int k=id_len+6;this->str.at(k)!='#';k++){
                level_len++;
            }

            for(int m=id_len+level_len+7;this->str.at(m)!='#';m++){
                exp_len++;
            }
            id=str.mid(1,id_len);
            pid=str.mid(id_len+2,1).toInt();
            result=str.mid(id_len+4,1).toInt();
            level=str.mid(id_len+6,level_len).toInt();
            exp=str.mid(id_len+level_len+7,exp_len).toInt();
            delpid=str.mid(id_len+level_len+exp_len+8,1).toInt();
            database.checkuser(id);
            database.checkpokemon(id,pid);
            database.temppetmun--;
            database.temptotalgame++;
            database.updatapokemon(id,pid,database.temptype,level,exp);
            database.update(id,database.temppassword,database.temppetmun,database.temponline,database.tempwin,database.temptotalgame);
            database.deletepet(id,delpid,database.temppetmun+1);
            if(database.temppetmun==0)
            {
                database.insertpet(id,1,rand()%8+1,1);
            }
        }

//-----------------------------------------------------------------------
       else
            sendmsg(10);
}
void PokemonServer::paintEvent(QPaintEvent *)
{
    QPainter *painter=new QPainter(this);
    QPixmap pix;
    pix.load("C:/Users/Administrator/Desktop/PokemonGo/pokemon3/picture/8716b6a2a5985265.jpg");
    painter->setOpacity(0.8);
    painter->drawPixmap(0,0,this->width(),this->height(),pix);
}
