#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "online.h"
#include "user.h"
#include "pokemon.h"
#include <QPainter>
#include <QPixmap>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    Online *o;
    User *u;
    Pokemon *p;
signals:
    void sendquit();
    void sendcheckusertomain(QString name);//连接user到main的信号
    void sendcheckusertouser(QString name,int petnum,int online,int win,int total,int highpet);//连接main到user的信号
    void sendcheckpokemontopet(QString name,QString petid,int type,int level,int exp);
    void sendcheckpokemontomain(QString name,QString pid);
    void checkonline();
    void sendchecktoonline(QString string);
    void openfight1();
    void openfight2();
public slots:

     void getfmain(QString a,int b,int c,int d,int e,int f);//用户登陆成功处理的槽

     void getcheckuser(QString cname);//处理来自user用户查询的槽
     void getcheckuserformmain(QString name,int petnum,int online,int win,int total,int highpet);//处理来自main用户查询的槽

     void getcheckpokemonformmain(QString name,QString petid,int type,int level,int exp);
     void getcheckpokemonformpet(QString name,QString pid);

     void getonlinefrommain(QString string);

private slots:
    void on_CtotalBtn_clicked(bool checked);
    void on_LuserBtn_clicked(bool checked);
    void on_CpetBtn_clicked(bool checked);
    void on_LquitBtn_clicked();


    void on_Lfight2Btn_clicked();

    void on_Lfight1Btn_clicked();

private:
    Ui::Login *ui;
    void paintEvent(QPaintEvent *);
};

#endif // LOGIN_H
