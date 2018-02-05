#include "losepet.h"
#include "ui_losepet.h"

losepet::losepet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::losepet)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
}

losepet::~losepet()
{
    delete ui;
}

void losepet::bbb(int i)
{
    if(i==1)
    {
        choice1=1;
        ui->lineEdit->setText(QString::number(1,10));
    }
    else if(i==2)
    {
        choice1=1;
        choice2=2;
        ui->lineEdit->setText(QString::number(1,10));
        ui->lineEdit_2->setText(QString::number(2,10));
    }
    else if(i==3)
    {
        choice1=1;
        choice2=2;
        choice3=3;
        ui->lineEdit->setText(QString::number(1,10));
        ui->lineEdit_2->setText(QString::number(2,10));
        ui->lineEdit_3->setText(QString::number(3,10));
    }
    else
    {
        choice1=rand()%(i-1)+1;
        choice2=rand()%(i-1)+1;
        while(choice1==choice2)
        {
            choice2=rand()%(i-1)+1;
        }
        choice3=rand()%(i-1)+1;
        while((choice3==choice1)||(choice3==choice1))
        {
            choice3=rand()%(i-1)+1;
        }
        ui->lineEdit->setText(QString::number(choice1,10));
        ui->lineEdit_2->setText(QString::number(choice2,10));
        ui->lineEdit_3->setText(QString::number(choice3,10));
    }
}

void losepet::on_lineEdit_4_editingFinished()
{
        this->mychoice=ui->lineEdit_4->text();
}

void losepet::on_pushButton_clicked()
{
    emit ccc(mychoice);
    QMessageBox::information(this,"message","你失去了一个精灵！");
}

void losepet::on_pushButton_2_clicked()
{
    ui->pushButton->setEnabled(true);
}

void losepet::paintEvent(QPaintEvent *)
{
    QPainter *painter=new QPainter(this);
    QPixmap pix;
    pix.load("C:/Users/Administrator/Desktop/PokemonGo/pokemon3/picture/860c9c33b76c88b4.jpg");
    painter->setOpacity(0.8);
    painter->drawPixmap(0,0,this->width(),this->height(),pix);
}
