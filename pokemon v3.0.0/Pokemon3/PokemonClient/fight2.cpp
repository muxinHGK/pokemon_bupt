#include "fight2.h"
#include "ui_fight2.h"

fight2::fight2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fight2)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);
}

fight2::~fight2()
{
    delete ui;
}

void fight2::getpetfrommain(QString str1, QString str2, int a, int b, int c)
{
    this->mytype=a;
    this->mylevel=b;
    this->myexp=c;
    if(mytype==0)
    {
        this->mypetname="pikaqiu";
        this->mypettype="attack";
        this->skill1="ELECTRIC SHOCK!";
        this->myattack=(40+20*mylevel);
        this->mydefense=(40+10*mylevel);
        this->mylife=(400+100*mylevel);
        this->myspeed=(51-1*mylevel);
    }
    else if(mytype==1)
    {
        this->mypetname="xiaohuolong";
        this->mypettype="attack";
        this->skill1="DRAGON FLAMES!";
        this->myattack=(40+20*mylevel);
        this->mydefense=(40+10*mylevel);
        this->mylife=(400+100*mylevel);
        this->myspeed=(51-1*mylevel);
    }
    else if(mytype==2)
    {
        this->mypetname="tiejiayong";
        this->mypettype="defense";
        this->skill1="SHIELD IMPACK!";
        this->myattack=(40+10*mylevel);
        this->mydefense=(40+20*mylevel);
        this->mylife=(400+100*mylevel);
        this->myspeed=(51-1*mylevel);
    }
    else if(mytype==3)
    {
        this->mypetname="chouni";
        this->mypettype="defense";
        this->skill1="TOXIC DUST!";
        this->myattack=(40+10*mylevel);
        this->mydefense=(40+20*mylevel);
        this->mylife=(400+100*mylevel);
        this->myspeed=(51-1*mylevel);
    }
    else if(mytype==4)
    {
        this->mypetname="haixingxing";
        this->mypettype="life";
        this->skill1="WATER JET!";
        this->myattack=(40+10*mylevel);
        this->mydefense=(40+10*mylevel);
        this->mylife=(400+200*mylevel);
        this->myspeed=(51-1*mylevel);
    }
    else if(mytype==5)
    {
        this->mypetname="daidaishou";
        this->mypettype="life";
        this->skill1="MENTAL POWER!";
        this->myattack=(40+10*mylevel);
        this->mydefense=(40+10*mylevel);
        this->mylife=(400+200*mylevel);
        this->myspeed=(51-1*mylevel);
    }
    else if(mytype==6)
    {
        this->mypetname="feitiantanglang";
        this->mypettype="speed";
        this->skill1="FAST ATTACK!";
        this->myattack=(40+210*mylevel);
        this->mydefense=(40+10*mylevel);
        this->mylife=(400+100*mylevel);
        this->myspeed=(51-2*mylevel);
    }
    else if(mytype==7)
    {
        this->mypetname="bingniao";
        this->mypettype="speed";
        this->skill1="ABSLOTE ZERO!";
        this->myattack=(40+10*mylevel);
        this->mydefense=(40+10*mylevel);
        this->mylife=(400+100*mylevel);
        this->myspeed=(51-2*mylevel);
    }
    ui->lineEdit->setText(mypetname);
    ui->lineEdit_2->setText(mypettype);
    ui->lineEdit_3->setText(QString::number(mylevel,10));
    ui->lineEdit_4->setText(QString::number(myattack,10));
    ui->lineEdit_5->setText(QString::number(mydefense,10));
    ui->lineEdit_6->setText(QString::number(mylife,10));
    ui->lineEdit_7->setText(QString::number(myspeed,10));
    ui->lineEdit_8->setText(QString::number(myexp,10));

    this->yourexp=0;
    if(yourtype==0)
    {
        this->yourpetname="pikaqiu";
        this->yourpettype="attack";
        this->skill2="ELECTRIC SHOCK!";
        this->yourattack=(40+20*yourlevel);
        this->yourdefense=(40+10*yourlevel);
        this->yourlife=(400+100*yourlevel);
        this->yourspeed=(51-1*yourlevel);
    }
    else if(yourtype==1)
    {
        this->yourpetname="xiaohuolong";
        this->yourpettype="attack";
        this->skill2="DRAGON FLAMES!";
        this->yourattack=(40+20*yourlevel);
        this->yourdefense=(40+10*yourlevel);
        this->yourlife=(400+100*yourlevel);
        this->yourspeed=(51-1*yourlevel);
    }
    else if(yourtype==2)
    {
        this->yourpetname="tiejiayong";
        this->yourpettype="defense";
        this->skill2="SHIELD IMPACK!";
        this->yourattack=(40+10*yourlevel);
        this->yourdefense=(40+20*yourlevel);
        this->yourlife=(400+100*yourlevel);
        this->yourspeed=(51-1*yourlevel);
    }
    else if(yourtype==3)
    {
        this->yourpetname="chouni";
        this->yourpettype="defense";
        this->skill2="TOXIC DUST!";
        this->yourattack=(40+10*yourlevel);
        this->yourdefense=(40+20*yourlevel);
        this->yourlife=(400+100*yourlevel);
        this->yourspeed=(51-1*yourlevel);
    }
    else if(yourtype==4)
    {
        this->yourpetname="haixingxing";
        this->yourpettype="life";
        this->skill2="WATER JET!";
        this->yourattack=(40+10*yourlevel);
        this->yourdefense=(40+10*yourlevel);
        this->yourlife=(400+200*yourlevel);
        this->yourspeed=(51-1*yourlevel);
    }
    else if(yourtype==5)
    {
        this->yourpetname="daidaishou";
        this->yourpettype="life";
        this->skill2="MENTAL POWER!";
        this->yourattack=(40+10*yourlevel);
        this->yourdefense=(40+10*yourlevel);
        this->yourlife=(400+200*yourlevel);
        this->yourspeed=(51-1*yourlevel);
    }
    else if(yourtype==6)
    {
        this->yourpetname="feitiantanglang";
        this->yourpettype="speed";
        this->skill2="FAST ATTACK!";
        this->yourattack=(40+210*yourlevel);
        this->yourdefense=(40+10*yourlevel);
        this->yourlife=(400+100*yourlevel);
        this->yourspeed=(51-2*yourlevel);
    }
    else if(yourtype==7)
    {
        this->yourpetname="bingniao";
        this->yourpettype="speed";
        this->skill2="ABSLOTE ZERO!";
        this->yourattack=(40+10*yourlevel);
        this->yourdefense=(40+10*yourlevel);
        this->yourlife=(400+100*yourlevel);
        this->yourspeed=(51-2*yourlevel);
    }
    ui->lineEdit_9->setText(yourpetname);
    ui->lineEdit_10->setText(yourpettype);
    ui->lineEdit_11->setText(QString::number(yourlevel,10));
    ui->lineEdit_12->setText(QString::number(yourattack,10));
    ui->lineEdit_13->setText(QString::number(yourdefense,10));
    ui->lineEdit_14->setText(QString::number(yourlife,10));
    ui->lineEdit_15->setText(QString::number(yourspeed,10));
    ui->lineEdit_16->setText(QString::number(yourexp,10));
}

void fight2::on_pushButton_clicked()
{
    emit getpet(mypetid);
    ui->pushButton_2->setEnabled(true);
}

void fight2::on_lineEdit_19_editingFinished()
{
    this->mypetid=ui->lineEdit_19->text();
}

void fight2::on_lineEdit_20_editingFinished()
{
    this->yourtype=ui->lineEdit_20->text().toInt();
}

void fight2::on_lineEdit_21_editingFinished()
{
    this->yourlevel=ui->lineEdit_21->text().toInt();
}

void fight2::on_pushButton_2_clicked()
{
    startfight2();
}

void fight2::startfight2()
{
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    //int xxx=qrand()%100
    //%100 ：在0-100中选出随机数

    int run=0;     //模拟战斗的变量
    int round=0;   //回合数
    int hurt=0;    //伤害值
    QString str;

    mynowlife=mylife;
    yournowlife=yourlife;
    ui->lineEdit_17->setText(QString::number(mynowlife,10));
    ui->lineEdit_18->setText(QString::number(yournowlife,10));

    while((mynowlife>0)&&(yournowlife>0))
    {
        run++;
        if(run%myspeed==0)
        {
            round++;
            hurt=30+myattack-yourdefense*0.2;//伤害计算公式，与第一版本不同，考虑等级相差过大的情况下伤害值不能为负
            int a=qrand()%4+1;//产生1~5之间的随机数，模拟暴击和闪避 暴击和闪避几率都为20%
            if(a==1) //暴击
            {
                hurt=hurt*2;
                yournowlife=yournowlife-hurt;
                if(yournowlife<0)
                    yournowlife=0;
                ui->lineEdit_18->setText(QString::number(yournowlife,10));
                str="Round"+QString::number(round,10)+":  "+mypetname+" use "+skill1+" with crit,"+yourpetname+" get "+QString::number(hurt,10)+" hurt!";
                ui->textEdit->setText(str);
            }
            else if(a==2)//闪避
            {
                hurt=0;
                yournowlife=yournowlife-hurt;
                if(yournowlife<0)
                    yournowlife=0;
                ui->lineEdit_18->setText(QString::number(yournowlife,10));
                str="Round"+QString::number(round,10)+":  "+mypetname+" use "+skill1+",but "+yourpetname+" dodge!";
                ui->textEdit->setText(str);
            }
            else
            {
                yournowlife=yournowlife-hurt;
                if(yournowlife<0)
                    yournowlife=0;
                ui->lineEdit_18->setText(QString::number(yournowlife,10));
                str="Round"+QString::number(round,10)+":  "+mypetname+" use "+skill1+","+yourpetname+" get "+QString::number(hurt,10)+" hurt!";
                ui->textEdit->setText(str);
            }
            QTime m=QTime::currentTime().addMSecs(1000);
            while( QTime::currentTime()<m)
                QCoreApplication::processEvents(QEventLoop::AllEvents,1000);
        }

        if((run%yourspeed==0)&&(yournowlife>0))
        {
            round++;
            hurt=30+yourattack-mydefense*0.2;//伤害计算公式，与第一版本不同，考虑等级相差过大的情况下伤害值不能为负
            int a=qrand()%4+1;//产生1~5之间的随机数，模拟暴击和闪避 暴击和闪避几率都为20%
            if(a==1) //暴击
            {
                hurt=hurt*2;
                mynowlife=mynowlife-hurt;
                if(mynowlife<0)
                    mynowlife=0;
                ui->lineEdit_17->setText(QString::number(mynowlife,10));
                str="Round"+QString::number(round,10)+":  "+yourpetname+" use "+skill2+" with crit,"+mypetname+" get "+QString::number(hurt,10)+" hurt!";
                ui->textEdit->setText(str);
            }
            else if(a==2)//闪避
            {
                hurt=0;
                mynowlife=mynowlife-hurt;
                if(mynowlife<0)
                    mynowlife=0;
                ui->lineEdit_17->setText(QString::number(mynowlife,10));
                str="Round"+QString::number(round,10)+":  "+yourpetname+" use "+skill2+",but "+mypetname+" dodge!";
                ui->textEdit->setText(str);
            }
            else
            {
                mynowlife=mynowlife-hurt;
                if(mynowlife<0)
                    mynowlife=0;
                ui->lineEdit_17->setText(QString::number(mynowlife,10));
                str="Round"+QString::number(round,10)+":  "+yourpetname+" use "+skill2+","+mypetname+" get "+QString::number(hurt,10)+" hurt!";
                ui->textEdit->setText(str);
            }
            QTime m=QTime::currentTime().addMSecs(1000);
            while( QTime::currentTime()<m)
                QCoreApplication::processEvents(QEventLoop::AllEvents,1000);
        }
    }
    if(mynowlife>0)
    {
        myexp=myexp+10;
        if((myexp>=mylevel*10)&&(mylevel<15))
        {
            myexp=myexp-mylevel*10;
            mylevel++;
        }
        QMessageBox::information(this,"message","你赢了！");
        emit winfight2(1,mylevel,myexp);
    }
    else if(yournowlife>0)
    {
        myexp=myexp+5;
        if((myexp>=mylevel*10)&&(mylevel<15))
        {
            myexp=myexp-mylevel*10;
            mylevel++;
        }
        QMessageBox::information(this,"message","你输了！");
        emit losefight2(0,mylevel,myexp);
    }
}

void fight2::paintEvent(QPaintEvent *)
{
    QPainter *painter=new QPainter(this);
    QPixmap pix;
    pix.load("C:/Users/Administrator/Desktop/PokemonGo/pokemon3/picture/84b996634a4155f9.jpg");
    painter->setOpacity(0.8);
    painter->drawPixmap(0,0,this->width(),this->height(),pix);
}
