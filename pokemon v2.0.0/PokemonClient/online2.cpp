#include "online2.h"
#include "ui_online2.h"

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
     pix.load("C:/Users/Administrator/Desktop/PokemonGo/pokemon2/picture/84b996634a4155f9.jpg");
     painter->setOpacity(0.8);
     painter->drawPixmap(0,0,this->width(),this->height(),pix);
 }
