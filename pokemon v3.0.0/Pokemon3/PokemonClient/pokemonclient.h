#ifndef POKEMONCLIENT_H
#define POKEMONCLIENT_H

#include <QMainWindow>
#include <QDialog>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QHostAddress>
#include <QTcpSocket>
#include <QTimer>
#include "creat.h"
#include "login.h"
#include <QMessageBox>
#include "fight1.h"
#include "fight2.h"
#include "losepet.h"
#include <QPainter>
#include <QPixmap>

namespace Ui {
class PokemonClient;
}

class PokemonClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit PokemonClient(QWidget *parent = 0);
    ~PokemonClient();
    QTcpSocket *Clientsocket;
    quint32 blocksize;
    QString name,password;//用于记录登陆用户的名字和密码
    QString str,petid;  //用于记录查询精灵的ID

    QString get_name;
    int get_petnum,get_online,get_win,get_total,get_highpet;

    QString p_name,p_id;
    int p_type,p_exp,p_level;
    int addpettype,addpetlevel;
    QString losemypet;//指示决斗赛失败丢失的精灵编号

    Creat *c;
    Login *l;
    fight1 *f1;
    fight2 *f2;
    losepet *s;
    int temp;//用于指示是登陆用户信息还是查询用户信息
    int temp1;//用于指示精灵信息是对战精灵还是查询精灵

    int f1result,f1level,f1exp;//记录对战后当前精灵的属性 用于TCP
    int f2result,f2level,f2exp;//记录对战后当前精灵的属性 用于TCP

signals:
    void sendtologin(QString a,int b,int c,int d,int e,int f);

    void sendgetusertologin(QString toname,int topetnum,int toonline,int towin,int totoal,int highpet);
    void sendcheckpokemontologin(QString pname,QString pid,int type,int level,int exp);
    void sendonlinetologin(QString string);   
    void sendpettofight1(QString pname,QString pid,int type,int level,int exp);
    void sendpettofight2(QString pname,QString pid,int type,int level,int exp);

    void aaa(int petnum);

private slots:
    void timedone();
    void receivemsg();
    void sendmsg(int i);
    void getquit();
    void getcheckuserfromlogin(QString checkname);
    void getcheckpokemonfromlogin(QString pname,QString ppid);
    void checkonlinefromlogin();

    void creatfight1();
    void getpetid1(QString str);
    void getwinfight1(int result,int petlevel,int petexp,int addtype,int addlevel);
    void getlosefight1(int result,int petlevel,int petexp);

    void ddd(QString);

    void creatfight2();
    void getpetid(QString str);
    void getwinfight2(int result,int petlevel,int petexp);
    void getlosefight2(int result,int petlevel,int petexp);

    void creatuser(QString id,QString code);

    void on_CreatBtn_clicked(bool checked);
    void on_LoginBtn_clicked(bool checked);
    void on_Username_editingFinished();
    void on_Password_editingFinished();
    void on_pushButton_clicked();

private:
    Ui::PokemonClient *ui;
    void paintEvent(QPaintEvent *);
};

#endif // POKEMONCLIENT_H
