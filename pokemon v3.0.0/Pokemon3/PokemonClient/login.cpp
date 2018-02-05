#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_CtotalBtn_clicked(bool checked)
{
    o= new Online;
    emit checkonline();
    connect(this,SIGNAL(sendchecktoonline(QString)),o,SLOT(getcheckonline(QString)));
    o->show();
}

void Login::on_LuserBtn_clicked(bool checked)
{
    u= new User;
    connect(u,SIGNAL(sendcheckusertologin(QString)),this,SLOT(getcheckuser(QString)));
    connect(this,SIGNAL(sendcheckusertouser(QString,int,int,int,int,int)),u,SLOT(getcheckuserfromlogin(QString,int,int,int,int,int)));
    u->show();
}

void Login::on_CpetBtn_clicked(bool checked)
{
    p =new Pokemon;
    connect(p,SIGNAL(sendcheckpokemontologin(QString,QString)),this,SLOT(getcheckpokemonformpet(QString,QString)));
    connect(this,SIGNAL(sendcheckpokemontopet(QString,QString,int,int,int)),p,SLOT(getcheckpokemonfromlogin(QString,QString,int,int,int)));
    p->show();
}

void Login::getfmain(QString a,int b,int c,int d,int e,int f)
{
    ui->Lname->setText(a);
    ui->Lpetnum->setText(QString::number(b,10));
    ui->Lonline->setText(QString::number(c,10));
    ui->Lwin->setText(QString::number(d,10));
    ui->Ltotal->setText(QString::number(e,10));
    int winrate;
    QString str1,str2;
    if(e==0)
        winrate=0;
    else
        winrate=(d*100)/e;
    ui->lineEdit->setText(QString::number(winrate,10));

    if(b<=3)                       //精灵数目小于3：copper     4~5：silver    6:gold
        str1="copper";
    else if((4<b)&&(b<5))
        str1="silver";
    else
        str1="gold";
    ui->lineEdit_2->setText(str1);

    if(f<=3)                      //高级精灵数目小于3：copper     4~5：silver    6:gold
        str2="copper";
    else if((3<f)&&(e<f))
        str2="silver";
    else
        str2="gold";
    ui->lineEdit_3->setText(str2);
}

void Login::on_LquitBtn_clicked()
{
    emit sendquit();
}

void Login::getcheckuser(QString cname)
{
    emit sendcheckusertomain(cname);
}

void Login::getcheckuserformmain(QString name,int petnum, int online, int win, int total,int highpet)
{
    emit sendcheckusertouser(name,petnum,online,win,total,highpet);
}

void Login::getcheckpokemonformmain(QString name, QString petid, int type, int level, int exp)
{
    emit sendcheckpokemontopet(name,petid,type,level,exp);
  //  qDebug()<<"11222333";
}

void Login::getcheckpokemonformpet(QString name, QString petid)
{
    emit sendcheckpokemontomain(name,petid);
}

void Login::getonlinefrommain(QString string)
{
    emit sendchecktoonline(string);
}


void Login::on_Lfight2Btn_clicked()
{
    emit openfight2();
}

void Login::on_Lfight1Btn_clicked()
{
    emit openfight1();
}

void Login::paintEvent(QPaintEvent *)
{
    QPainter *painter=new QPainter(this);
    QPixmap pix;
    pix.load("C:/Users/Administrator/Desktop/PokemonGo/pokemon3/picture/8716b6a2a5985265.jpg");
    painter->setOpacity(0.8);
    painter->drawPixmap(0,0,this->width(),this->height(),pix);
}
