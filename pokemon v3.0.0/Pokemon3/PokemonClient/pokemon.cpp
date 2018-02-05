#include "pokemon.h"
#include "ui_pokemon.h"

Pokemon::Pokemon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pokemon)
{
    ui->setupUi(this);
    ui->PcheckBtn->setEnabled(false);
}

Pokemon::~Pokemon()
{
    delete ui;
}

void Pokemon::getcheckpokemonfromlogin(QString id,QString pid,int type,int level,int exp)
{
    //qDebug()<<"112222222223";
     this->owner =id;
     this->petid=pid;
     this->level=level;
     this->exp=exp;
     if(type==0)
     {
         this->petname="pikaqiu";
         this->ptype="attack";
         this->attack=40+20*level;
         this->defense =40+10*level;
         this->life=400+100*level;
         this->speed=51-1*level;
     }
     if(type==1)
     {
         this->petname="xiaohuolong";
         this->ptype="attack";
         this->attack=40+20*level;
         this->defense =40+10*level;
         this->life=400+100*level;
         this->speed=51-1*level;
     }
     if(type==2)
     {
         this->petname="tiejiayong";
         this->ptype="defense";
         this->attack=40+10*level;
         this->defense =40+20*level;
         this->life=400+100*level;
         this->speed=51-1*level;
     }
     if(type==3)
     {
         this->petname="chouni";
         this->ptype="defense";
         this->attack=40+10*level;
         this->defense =40+20*level;
         this->life=400+100*level;
         this->speed=51-1*level;
     }
     if(type==4)
     {
         this->petname="haixingxing";
         this->ptype="life";
         this->attack=40+10*level;
         this->defense =40+10*level;
         this->life=400+200*level;
         this->speed=51-1*level;
     }
     if(type==5)
     {
         this->petname="daidaishou";
         this->ptype="life";
         this->attack=40+10*level;
         this->defense =40+10*level;
         this->life=400+200*level;
         this->speed=51-1*level;
     }
     if(type==6)
     {
         this->petname="fetiantanglang";
         this->ptype="spped";
         this->attack=40+10*level;
         this->defense =40+10*level;
         this->life=400+100*level;
         this->speed=51-2*level;
     }
     if(type==7)
     {
         this->petname="bingniao";
         this->ptype="speed";
         this->attack=40+10*level;
         this->defense =40+10*level;
         this->life=400+100*level;
         this->speed=51-2*level;
     }
    // ui->Lpetnum->setText(QString::number(b,10));
     ui->Puser_2->setText(owner);
     ui->Ptype->setText(ptype);
     ui->Ppokemon->setText(petname);
     ui->Ppetnum2->setText(petid);
     ui->Pexp->setText(QString::number(exp,10));
     ui->Pdefense->setText(QString::number(defense,10));
     ui->Pattack->setText(QString::number(attack,10));
     ui->Plife->setText(QString::number(life,10));
     ui->Ptime->setText(QString::number(speed,10));
     ui->Plevel->setText(QString::number(level,10));
}

void Pokemon::on_pushButton_clicked()
{
    ui->PcheckBtn->setEnabled(true);
}

void Pokemon::on_PCuser_editingFinished()
{
    this->pname=ui->PCuser->text();
}

void Pokemon::on_Ppetnum_editingFinished()
{
    this->ppid=ui->Ppetnum->text();
}

void Pokemon::on_PcheckBtn_clicked()
{
    emit sendcheckpokemontologin(pname,ppid);
}

void Pokemon::paintEvent(QPaintEvent *)
{
    QPainter *painter=new QPainter(this);
    QPixmap pix;
    pix.load("C:/Users/Administrator/Desktop/PokemonGo/pokemon3/picture/c4c4059836e74845.jpg");
    painter->setOpacity(0.8);
    painter->drawPixmap(0,0,this->width(),this->height(),pix);
}
