#include "user2.h"
#include "ui_user2.h"

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

void User::getcheckuserfromlogin(QString uname, int upetnum, int uonline, int uwin, int utotal)
{
    ui->Uuser->setText(uname);
    ui->Upetnum->setText(QString::number(upetnum,10));
    ui->Uonline->setText(QString::number(uonline,10));
    ui->Uwin->setText(QString::number(uwin,10));
    ui->Utotal->setText(QString::number(utotal,10));
}

void User::on_pushButton_2_clicked()
{
    ui->UcheckBtn->setEnabled(true);
}

void User::paintEvent(QPaintEvent *)
{
    QPainter *painter=new QPainter(this);
    QPixmap pix;
    pix.load("C:/Users/Administrator/Desktop/PokemonGo/pokemon2/picture/84b996634a4155f9.jpg");
    painter->setOpacity(0.8);
    painter->drawPixmap(0,0,this->width(),this->height(),pix);
}
