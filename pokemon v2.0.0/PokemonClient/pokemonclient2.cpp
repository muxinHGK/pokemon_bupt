#include "pokemonclient2.h"
#include "ui_pokemonclient2.h"

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
    QByteArray block;
    this->blocksize=0;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    out <<(quint16)0;

    switch(i)
    {
    case 1:                                                 //注册用户的账号和密码Creat
        out.device()->seek(0);
        out << (quint16)(block.size()-sizeof(quint16));
        this->str = "C"+ this->name +"#"+ this->password+"#";
        out << this->str;
        Clientsocket -> waitForConnected(10000);
        Clientsocket -> write(block);
        qDebug()<<str;
        break;

    case 2:                                                 //登陆用户的账号和密码Login
        out.device()->seek(0);
        out << (quint16)(block.size()-sizeof(quint16));
        this->str = "L"+ this->name + "#" + this->password+"#";
        out << this->str;
        Clientsocket -> waitForConnected(10000);
        Clientsocket -> write(block);
        qDebug()<<str;
        break;
    case 3:                                                 //查询宠物信息Pokemon
        out.device()->seek(0);
        out << (quint16)(block.size()-sizeof(quint16));
        this->str = "P"+ this->name + "#" + this->petid+"#";
        out << this->str;
        Clientsocket -> waitForConnected(10000);
        Clientsocket -> write(block);
        qDebug()<<str;
        break;
    case 4:                                                 //查询用户信息User
        out.device()->seek(0);
        out << (quint16)(block.size()-sizeof(quint16));
        this->str = "U"+ this->name + "#";
        out << this->str;
        Clientsocket -> waitForConnected(10000);
        Clientsocket -> write(block);
        qDebug()<<str;
        break;
    case 5:                                                 //用户退出Exit
        out.device()->seek(0);
        out << (quint16)(block.size()-sizeof(quint16));
        this->str = "E#" ;
        out << this->str;
        Clientsocket -> waitForConnected(10000);
        Clientsocket -> write(block);
        qDebug()<<str;
        break;
    case 6:                                                 //查询总在线用户信息Gettotal
        out.device()->seek(0);
        out << (quint16)(block.size()-sizeof(quint16));
        this->str = "G#";
        out << this->str;
        Clientsocket -> waitForConnected(10000);
        Clientsocket -> write(block);
        qDebug()<<str;
        break;
    }
}

void PokemonClient::receivemsg()                //从服务器接收消息时的处理
{
    this->blocksize=0;
    QDataStream in(Clientsocket);
    in.setVersion(QDataStream::Qt_5_5);
    if(blocksize==0){
        if(Clientsocket->bytesAvailable()<(int)sizeof(quint16))
            return;
        in>>blocksize;
    }
    if(Clientsocket->bytesAvailable()<blocksize)
        return;
    in>>this->str;


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

        if(temp==1)
        {
            //qDebug()<<"1111";
            l = new Login;
            connect(this,SIGNAL(sendtologin(QString,int,int,int,int)),l,SLOT(getfmain(QString,int,int,int,int)));
            connect(l,SIGNAL(sendquit()),this,SLOT(getquit()));
            connect(l,SIGNAL(sendcheckusertomain(QString)),this,SLOT(getcheckuserfromlogin(QString)));
            connect(l,SIGNAL(sendcheckpokemontomain(QString,QString)),this,SLOT(getcheckpokemonfromlogin(QString,QString)));
            connect(this,SIGNAL(sendgetusertologin(QString,int,int,int,int)),l,SLOT(getcheckuserformmain(QString,int,int,int,int)));
            connect(this,SIGNAL(sendcheckpokemontologin(QString,QString,int,int,int)),l,SLOT(getcheckpokemonformmain(QString,QString,int,int,int)));
            connect(l,SIGNAL(checkonline()),this,SLOT(checkonlinefromlogin()));
            connect(this,SIGNAL(sendonlinetologin(QString)),l,SLOT(getonlinefrommain(QString)));
            l->show();
            emit sendtologin(get_name,get_petnum,get_online,get_win,get_total);
        }
        else
            emit sendgetusertologin(get_name,get_petnum,get_online,get_win,get_total);

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
        qDebug()<<"11222333";
        this->p_name = this->str.mid(1,id_len);
        this->p_id = this->str.mid(id_len+2,pid_len);
        this->p_type= this->str.mid(id_len+pid_len+3,1).toInt();
        this->p_level = this->str.mid(id_len+pid_len+5,level_len).toInt();
        this->p_exp = this->str.mid(id_len+pid_len+level_len+6,exp_len).toInt();

        emit sendcheckpokemontologin(p_name,p_id,p_type,p_level,p_exp);
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
    this->name=pname;
    this->petid=ppid;
    sendmsg(3);
}

void PokemonClient::checkonlinefromlogin()
{
    sendmsg(6);
}

void PokemonClient::paintEvent(QPaintEvent *)
{
    QPainter *painter=new QPainter(this);
    QPixmap pix;
    pix.load("C:/Users/Administrator/Desktop/PokemonGo/pokemon2/picture/84b996634a4155f9.jpg");
    painter->setOpacity(0.8);
    painter->drawPixmap(0,0,this->width(),this->height(),pix);
}
