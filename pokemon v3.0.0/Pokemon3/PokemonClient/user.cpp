#include "user.h"
#include "ui_user.h"

User::User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
    ui->UcheckBtn->setEnabled(false);
}

User::~User()
{
    delete ui;
}

void User::on_UCuser_editingFinished()
{
    this->ucheckname=ui->UCuser->text();
}

void User::on_UcheckBtn_clicked()
{
    emit sendcheckusertologin(ucheckname);
}

void User::getcheckuserfromlogin(QString uname, int upetnum, int uonline, int uwin, int utotal,int uhighpet)
{
    ui->Uuser->setText(uname);
    ui->Upetnum->setText(QString::number(upetnum,10));
    ui->Uonline->setText(QString::number(uonline,10));
    ui->Uwin->setText(QString::number(uwin,10));
    ui->Utotal->setText(QString::number(utotal,10));
    if(utotal==0)
        this->winrate=0;
    else
        this->winrate=(uwin*100)/utotal;
    ui->lineEdit->setText(QString::number(winrate,10));
    if(upetnum<=3)
        this->petnumstr="copper";
    else if((3<upetnum)&&(upetnum<5))
        this->petnumstr="silver";
    else
        this->petnumstr="gold";
    ui->lineEdit_2->setText(petnumstr);

    if(uhighpet<=3)
        this->petlevelstr="copper";
    else if((3<uhighpet)&&(uhighpet<5))
        this->petlevelstr="silver";
    else
        this->petlevelstr="gold";
    this->petlevelstr="copper";
    ui->lineEdit_3->setText(petlevelstr);

}

void User::on_pushButton_2_clicked()
{
    ui->UcheckBtn->setEnabled(true);
}

void User::paintEvent(QPaintEvent *)
{
    QPainter *painter=new QPainter(this);
    QPixmap pix;
    pix.load("C:/Users/Administrator/Desktop/PokemonGo/pokemon3/picture/e2234fc68245e400.jpg");
    painter->setOpacity(0.8);
    painter->drawPixmap(0,0,this->width(),this->height(),pix);
}
