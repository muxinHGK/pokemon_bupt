#include "creat.h"
#include "ui_creat.h"

Creat::Creat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Creat)
{
    ui->setupUi(this);
    ui->CcreatBtn->setEnabled(false);
}

Creat::~Creat()
{
    delete ui;
}

void Creat::on_CcreatBtn_clicked()
{

    emit send(cname,cpassword);
}



void Creat::on_Cname_editingFinished()
{
    this->cname=ui->Cname->text();
}

void Creat::on_Cpass_editingFinished()
{
    this->cpassword = ui->Cpass->text();
}

void Creat::on_Csurepass_editingFinished()
{
    this->ensurepass = ui->Csurepass->text();
    if(cpassword==ensurepass)
    {
        ui->CcreatBtn->setEnabled(true);
    }
}

void Creat::paintEvent(QPaintEvent *)
{
    QPainter *painter=new QPainter(this);
    QPixmap pix;
    pix.load("C:/Users/Administrator/Desktop/PokemonGo/pokemon3/picture/10329653.jpg");
    painter->setOpacity(0.8);
    painter->drawPixmap(0,0,this->width(),this->height(),pix);
}
