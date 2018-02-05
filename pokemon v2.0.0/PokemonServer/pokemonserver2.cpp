#include "pokemonserver2.h"
#include "ui_pokemonserver2.h"

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
    db.setDatabaseName("Pokemon.db");  //每次构建时因为表的重名会导致下面的数据库表显示创建失败，因此可以改变数据库名重新构建
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
}

void PokemonServer::newconnect()
{
    this->Pokemonsocket = Pokemonserver->nextPendingConnection();
    connect(Pokemonsocket,SIGNAL(readyRead()),this,SLOT(receivemsg()));
}

void PokemonServer::sendmsg(int i)                 //向用户发送信息的函数
{
    this->blocksize=0;
    QByteArray block;  //用于暂存我们要发送的数据
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    out <<(quint16)0;
    switch(i)
    {
        case 1:                                 //发送用户信息
            out.device()->seek(0);
            out << (quint16)(block.size()-sizeof(quint16));

            this->str = "U"+ database.tempid +"#"+                     //包括用户名，精灵数，是否在线，获胜场次，总场次
                        QString::number(database.temppetmun,10)+"#"+   //以十进制转换
                        QString::number(database.temponline,10)+"#"+
                        QString::number(database.tempwin,10)+"#"+
                        QString::number(database.temptotalgame,10)+"#";
            out << this->str;
            Pokemonsocket -> waitForConnected(10000);
            this->Pokemonsocket -> write(block);
            qDebug()<<str;
            break;

        case 2:                                  //发送精灵信息
            out.device()->seek(0);
            out << (quint16)(block.size()-sizeof(quint16));

            this->str = "P"+ database.tempid +"#"+
                     database.tempp_id +"#"+
                     QString::number(database.temptype,10)+"#"+   //以十进制转换
                     QString::number(database.temp_level,10)+"#"+
                     QString::number(database.tempexp,10)+"#";
            out << this->str;
            Pokemonsocket -> waitForConnected(10000);
            this->Pokemonsocket -> write(block);
            qDebug()<<str;
            break;

        case 3:                                 //用户名账号不匹配
            out<<tr("errorpassword");                //发送错误信息
            out.device()->seek(0);
            out << (quint16)(block.size()-sizeof(quint16));
            Pokemonsocket -> waitForConnected(10000);
            this->Pokemonsocket -> write(block);
            break;

        case 4:                               //发现重复的账号
            out<<tr("existthisid");              //发送错误信号
            out.device()->seek(0);
            out << (quint16)(block.size()-sizeof(quint16));
            Pokemonsocket -> waitForConnected(10000);
            this->Pokemonsocket -> write(block);
            break;

        case 5:                                //账号创建成功
            out<<tr("creatsucceed");              //发送成功信号
            out.device()->seek(0);
            out << (quint16)(block.size()-sizeof(quint16));
            Pokemonsocket -> waitForConnected(10000);
            this->Pokemonsocket -> write(block);
            break;

        case 6:                                 //没有找到id
            out<<tr("nothisid");              //发送未找到id信号
            out.device()->seek(0);
            out << (quint16)(block.size()-sizeof(quint16));
            Pokemonsocket -> waitForConnected(10000);
            this->Pokemonsocket -> write(block);
            break;
        case 7:
            out<<tr("quitsucceed");
            out.device()->seek(0);
            out << (quint16)(block.size()-sizeof(quint16));
            Pokemonsocket -> waitForConnected(10000);
            this->Pokemonsocket -> write(block);
            break;
        case 8:                                //发送在线用户的名字
            out.device()->seek(0);
            out << (quint16)(block.size()-sizeof(quint16));
            this->str=database.gettotal();
           // qDebug()<<str;
            out << this->str;
            this->Pokemonsocket -> write(block);
            qDebug()<<str;
            break;
        case 9:                                    //没有找到这个精灵
            out<<tr("nothispokemon");              //发送错误信号
            out.device()->seek(0);
            out << (quint16)(block.size()-sizeof(quint16));
            Pokemonsocket -> waitForConnected(10000);
            this->Pokemonsocket -> write(block);
            break;
        case 10:                              //无效的接收消息
            out<<tr("unusemsg");              //发送错误信号
            out.device()->seek(0);
            out << (quint16)(block.size()-sizeof(quint16));
            Pokemonsocket -> waitForConnected(10000);
            this->Pokemonsocket -> write(block);
            break;
      }
}

void PokemonServer::receivemsg()              //收到消息时的处理
{
        this->blocksize=0;
        QDataStream in(Pokemonsocket);
        in.setVersion(QDataStream::Qt_5_5);
        if(blocksize==0)
        {
             if(Pokemonsocket->bytesAvailable()<(int)sizeof(quint16))
             return;
             in>>blocksize;
        }
        if(Pokemonsocket->bytesAvailable()<blocksize)
             return;
        in>>this->str;
        ui->lineEdit_2->setText(this->str);

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


            //qDebug()<<"1111111该精灵不存在！";
            database.checkpokemon(id,pid);
            //qDebug()<<"2222222该精灵不存在！";
            if( id == database.tempid)
            {
                if(pid==database.tempp_id)
                    sendmsg(2);
                else
                    sendmsg(9);
            }
            else
                sendmsg(9);
        }

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
             if( id == database.tempid)
             {
                     sendmsg(1);                //发送该用户的ID 精灵数，在线状态，获胜场次，总场次
             }
             else
                 sendmsg(6);  //发送密码错误的消息
       }
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
       else if(this->str.at(0)=='G')      //查询总的在线用户gettotal
       {
            sendmsg(8);
       }
       else
            sendmsg(10);
}
