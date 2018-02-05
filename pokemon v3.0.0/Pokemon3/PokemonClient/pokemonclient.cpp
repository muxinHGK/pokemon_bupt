#include "pokemonclient.h"
#include "ui_pokemonclient.h"

PokemonClient::PokemonClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PokemonClient)
{
    ui->setupUi(this);
    this->setWindowTitle("PokemonClient");

//-----------------建立TCP连接----------------------------

    Clientsocket = new QTcpSocket(this);
    Clientsocket->connectToHost(QHostAddress::LocalHost,6666);
    connect(Clientsocket,SIGNAL(readyRead()),this,SLOT(receivemsg()));
    connect(Clientsocket,SIGNAL(disconnected()),Clientsocket,SLOT(deleteLater()));

//-----------------设置定时以检查TCP连接是否正常--------------

    QTimer *time=new QTimer(this);
    time->setInterval(1000);
    connect(time,SIGNAL(timeout()),this,SLOT(timedone()));
    time->start();

    ui->LoginBtn->setEnabled(false);

}

void PokemonClient::timedone()
{
    int i=Clientsocket->waitForConnected(1000);
    if(i!=1)
        qDebug()<<"TCP连接失败！";
    else
        qDebug()<<"TCP连接成功！";
}

PokemonClient::~PokemonClient()
{
    delete ui;
}

void PokemonClient::sendmsg(int i)                   // 向服务器发送消息的函数
{
    QByteArray array;

    switch(i)
    {
    case 1:                                                 //注册用户的账号和密码Creat

        this->str = "C"+ this->name +"#"+ this->password+"#";

        array.append(str);
        Clientsocket -> write(array);
        qDebug()<<str;
        break;

    case 2:                                                 //登陆用户的账号和密码Login

        this->str = "L"+ this->name + "#" + this->password+"#";

        array.append(str);
        Clientsocket -> write(array);
        qDebug()<<str;
        break;
    case 3:                                                 //查询宠物信息Pokemon

        this->str = "P"+ this->name + "#" + this->petid+"#";

        array.append(str);
        Clientsocket -> write(array);
        qDebug()<<str;
        break;
    case 4:                                                 //查询用户信息User

        this->str = "U"+ this->name + "#";

        array.append(str);
        Clientsocket -> write(array);
        qDebug()<<str;
        break;
    case 5:                                                 //用户退出Exit

        this->str = "E#" ;

        array.append(str);
        Clientsocket -> write(array);
        qDebug()<<str;
        break;
    case 6:                                                 //查询总在线用户信息Gettotal

        this->str = "G#";

        array.append(str);
        Clientsocket -> write(array);
        qDebug()<<str;
        break;
    case 7:                                                //更新升级赛结果,关键字A

        this->str="A"+name+"#"+petid+"#"+
                QString::number(f2result,10)+"#"+
                QString::number(f2level,10)+"#"+
                QString::number(f2exp,10)+"#";

        array.append(str);
        Clientsocket -> write(array);
        qDebug()<<str;
        break;
    case 8:                                                //更新决斗赛获胜结果,关键字B
                                                           //B000#1#1#1#0#1#1#
        this->str="B"+name+"#"+petid+"#"+
                QString::number(f1result,10)+"#"+
                QString::number(f1level,10)+"#"+
                QString::number(f1exp,10)+"#"+
                QString::number(addpettype,10)+"#"+
                QString::number(addpetlevel,10)+"#";

        array.append(str);
        Clientsocket -> write(array);
        qDebug()<<str;
        break;
    case 9:                                                //更新决斗赛失败结果，关键字D

        this->str="D"+name+"#"+petid+"#"+
                QString::number(f1result,10)+"#"+
                QString::number(f1level,10)+"#"+
                QString::number(f1exp,10)+"#"+
                losemypet+"#";

        array.append(str);
        Clientsocket -> write(array);
        qDebug()<<str;
        break;
    }
}

void PokemonClient::receivemsg()                //从服务器接收消息时的处理
{
    str =Clientsocket->readAll();
    qDebug()<<str;

    if(str=="errorpassword")
    {
        qDebug()<<"密码错误！";
        QMessageBox::information(this,"message","密码错误！");
    }

    else if(str =="existthisid")
    {
        qDebug()<<"账号重复！";
        QMessageBox::information(this,"message","账号重复！");
    }

    else if(str == "creatsucceed")
    {
        qDebug()<<"注册成功！";
        QMessageBox::information(this,"message","注册成功！");
    }

    else if(str == "nothisid")
    {
        qDebug()<<"没有这个用户";
        QMessageBox::information(this,"message","没有这个用户！");
    }

    else if(str == "quitsucceed")
    {
        qDebug()<<"退出成功！";
        QMessageBox::information(this,"message","退出成功！");
    }

    else if(str == "nothispokemon")
    {
        qDebug()<<"该精灵不存在！";
        QMessageBox::information(this,"message","该精灵不存在！");
    }


    //登陆成功或者查询成功发回的信息处理，包括用户名，精灵数1位，是否在线1位，获胜场次，总场次
    else if(this->str.at(0)=='U')
    {
        int id_len = 0,win_len =0,total_len=0;
        for(int i=1;this->str.at(i)!='#';i++){
            id_len++;
        }
        for(int j=id_len+6;this->str.at(j)!='#';j++){
            win_len++;
        }
        for(int k=id_len+win_len+7;this->str.at(k)!='#';k++){
            total_len++;
        }

        this->get_name = this->str.mid(1,id_len);
        this->get_petnum = this->str.mid(id_len+2,1).toInt();
        this->get_online = this->str.mid(id_len+4,1).toInt();
        this->get_win = this->str.mid(id_len+6,win_len).toInt();
        this->get_total = this->str.mid(id_len+win_len+7,total_len).toInt();
        this->get_highpet=this->str.mid(id_len+win_len+9,1).toInt();
        qDebug()<<QString::number(get_highpet,10);

        if((get_petnum>=6)&&(temp==1))
        {
            QMessageBox::information(this,"message","此用户精灵已达上限，进行决斗赛不能获得精灵！");
        }

        if(temp==1)
        {
            //qDebug()<<"1111";
            l = new Login;
            connect(this,SIGNAL(sendtologin(QString,int,int,int,int,int)),l,SLOT(getfmain(QString,int,int,int,int,int)));
            connect(l,SIGNAL(sendquit()),this,SLOT(getquit()));
            connect(l,SIGNAL(sendcheckusertomain(QString)),this,SLOT(getcheckuserfromlogin(QString)));
            connect(l,SIGNAL(sendcheckpokemontomain(QString,QString)),this,SLOT(getcheckpokemonfromlogin(QString,QString)));
            connect(this,SIGNAL(sendgetusertologin(QString,int,int,int,int,int)),l,SLOT(getcheckuserformmain(QString,int,int,int,int,int)));
            connect(this,SIGNAL(sendcheckpokemontologin(QString,QString,int,int,int)),l,SLOT(getcheckpokemonformmain(QString,QString,int,int,int)));
            connect(l,SIGNAL(checkonline()),this,SLOT(checkonlinefromlogin()));
            connect(this,SIGNAL(sendonlinetologin(QString)),l,SLOT(getonlinefrommain(QString)));
            connect(l,SIGNAL(openfight1()),this,SLOT(creatfight1()));
            connect(l,SIGNAL(openfight2()),this,SLOT(creatfight2()));
            l->show();
            emit sendtologin(get_name,get_petnum,get_online,get_win,get_total,get_highpet);
        }
        else
            emit sendgetusertologin(get_name,get_petnum,get_online,get_win,get_total,get_highpet);

    }

    else if(this->str.at(0)=='P')
    {
        int id_len = 0,pid_len =0,level_len=0,exp_len=0;
        for(int i=1;this->str.at(i)!='#';i++){
            id_len++;
        }
        for(int j=id_len+2;this->str.at(j)!='#';j++){
            pid_len++;
        }
        for(int k=id_len+pid_len+5;this->str.at(k)!='#';k++){
            level_len++;
        }
        for(int m=id_len+pid_len+level_len+6;this->str.at(m)!='#';m++){
            exp_len++;
        }
        //qDebug()<<"11222333";
        this->p_name = this->str.mid(1,id_len);
        this->p_id = this->str.mid(id_len+2,pid_len);
        this->p_type= this->str.mid(id_len+pid_len+3,1).toInt();
        this->p_level = this->str.mid(id_len+pid_len+5,level_len).toInt();
        this->p_exp = this->str.mid(id_len+pid_len+level_len+6,exp_len).toInt();
        if(temp1==0)
            emit sendcheckpokemontologin(p_name,p_id,p_type,p_level,p_exp);
        else if(temp1==1)
            emit sendpettofight2(p_name,p_id,p_type,p_level,p_exp);
        else if(temp1==2)
            emit sendpettofight1(p_name,p_id,p_type,p_level,p_exp);
    }
    else if(this->str.at(0)=='G')
    {
        int strlen=this->str.length()-1;
        QString totalstr;
        totalstr=str.mid(1,strlen);
        emit sendonlinetologin(totalstr);
    }
}

void PokemonClient::on_CreatBtn_clicked(bool checked)
{
    //qDebug()<<"1111";
    c = new Creat;
    connect(c,SIGNAL(send(QString,QString)),this,SLOT(creatuser(QString,QString)));
    c->show();
}

void PokemonClient::on_LoginBtn_clicked(bool checked)
{
    temp=1;
    sendmsg(2);
}

void PokemonClient::creatuser(QString id,QString code)
{
    this->name=id;
    this->password=code;
    sendmsg(1);
}


void PokemonClient::on_Username_editingFinished()
{
    this->name=ui->Username->text();
}

void PokemonClient::on_Password_editingFinished()
{
    this->password=ui->Password->text();
}

void PokemonClient::on_pushButton_clicked()
{
    if(name!=""&&password!="")
     ui->LoginBtn->setEnabled(true);
}

void PokemonClient::getquit()
{
    sendmsg(5);
}

void PokemonClient::getcheckuserfromlogin(QString checkname)
{
    this->name=checkname;
    temp=0;
    sendmsg(4);
}

void PokemonClient::getcheckpokemonfromlogin(QString pname,QString ppid)
{
    temp1=0;
    this->name=pname;
    this->petid=ppid;
    sendmsg(3);
}

void PokemonClient::checkonlinefromlogin()
{
    sendmsg(6);
}

//---------------------------fight1-----------------------

void PokemonClient::creatfight1()
{
    f1=new fight1;
    connect(f1,SIGNAL(getpet1(QString)),this,SLOT(getpetid1(QString)));
    connect(this,SIGNAL(sendpettofight1(QString,QString,int,int,int)),f1,SLOT(getpetfrommain1(QString,QString,int,int,int)));
    connect(f1,SIGNAL(winfight1(int,int,int,int,int)),this,SLOT(getwinfight1(int,int,int,int,int)));
    connect(f1,SIGNAL(losefight1(int,int,int)),this,SLOT(getlosefight1(int,int,int)));
    //connect(f1,SIGNAL(getyourpet(int,int)),this,SLOT(f1getyourpet(int,int)));
    //connect(f1,SIGNAL(losemypet()),this,SLOT(f1losemypet()));
    f1->show();
}

void PokemonClient::getpetid1(QString str)
{
    temp1=2;
    this->petid=str;
    sendmsg(3);
}

void PokemonClient::getwinfight1(int result, int petlevel, int petexp,int addtype,int addlevel)
{
    this->f1result=result;
    this->f1level=petlevel;
    this->f1exp=petexp;
    this->addpettype=addtype;
    this->addpetlevel=addlevel;
    sendmsg(8);
}

void PokemonClient::getlosefight1(int result, int petlevel, int petexp)
{
    this->f1result=result;
    this->f1level=petlevel;
    this->f1exp=petexp;
    s=new losepet;
    connect(this,SIGNAL(aaa(int)),s,SLOT(bbb(int)));
    connect(s,SIGNAL(ccc(QString)),this,SLOT(ddd(QString)));
    s->show();
    emit aaa(get_petnum);
}


/*void PokemonClient::f1losemypet()
{
    s=new losepet;
    connect(this,SIGNAL(aaa(int)),s,SLOT(bbb(int)));
    connect(s,SIGNAL(ccc(QString)),this,SLOT(ddd(QString)));
    s->show();
    emit aaa(get_petnum);
}*/

void PokemonClient::ddd(QString str)
{
    this->losemypet=str;
    sendmsg(9);
}

//---------------------------fight2------------------------

void PokemonClient::creatfight2()
{
    f2=new fight2;
    connect(f2,SIGNAL(getpet(QString)),this,SLOT(getpetid(QString)));
    connect(this,SIGNAL(sendpettofight2(QString,QString,int,int,int)),f2,SLOT(getpetfrommain(QString,QString,int,int,int)));
    connect(f2,SIGNAL(winfight2(int,int,int)),this,SLOT(getwinfight2(int,int,int)));
    connect(f2,SIGNAL(losefight2(int,int,int)),this,SLOT(getlosefight2(int,int,int)));
    f2->show();
}

void PokemonClient::getpetid(QString str)
{
    temp1=1;
    this->petid=str;
    sendmsg(3);
}

void PokemonClient::getwinfight2(int result, int petlevel, int petexp)
{
    this->f2result=result;
    this->f2level=petlevel;
    this->f2exp=petexp;
   // qDebug()<<"1122223333";
    sendmsg(7);
   // qDebug()<<"kkkk2223333";
}

void PokemonClient::getlosefight2(int result, int petlevel, int petexp)
{
    this->f2result=result;
    this->f2level=petlevel;
    this->f2exp=petexp;
    sendmsg(7);
}

void PokemonClient::paintEvent(QPaintEvent *)
{
    QPainter *painter=new QPainter(this);
    QPixmap pix;
    pix.load("C:/Users/Administrator/Desktop/PokemonGo/pokemon3/picture/e2234fc68245e400.jpg");
    painter->setOpacity(0.8);
    painter->drawPixmap(0,0,this->width(),this->height(),pix);
}


