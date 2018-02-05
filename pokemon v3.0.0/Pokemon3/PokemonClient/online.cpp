#include "online.h"
#include "ui_online.h"

Online::Online(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Online)
{
    ui->setupUi(this);
}

Online::~Online()
{
    delete ui;
}
 void Online::getcheckonline(QString string)
 {
     ui->Onlineuser->setText(string);
 }

 void Online::paintEvent(QPaintEvent *)
 {
     QPainter *painter=new QPainter(this);
     QPixmap pix;
     pix.load("C:/Users/Administrator/Desktop/PokemonGo/pokemon3/picture/8716b6a2a5985265.jpg");
     painter->setOpacity(0.8);
     painter->drawPixmap(0,0,this->width(),this->height(),pix);
 }
