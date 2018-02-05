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
#include "creat2.h"
#include "login2.h"
#include <QMessageBox>
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
    quint16 blocksize;
    QString name,password,str,petid;

    QString get_name;
    int get_petnum,get_online,get_win,get_total;

    QString p_name,p_id;
    int p_type,p_exp,p_level;

    Creat *c;
    Login *l;
    int temp;//用于指示是登陆用户信息还是查询用户信息
signals:
    void sendtologin(QString a,int b,int c,int d,int e);

    void sendgetusertologin(QString toname,int topetnum,int toonline,int towin,int totoal);  
    void sendcheckpokemontologin(QString pname,QString pid,int type,int level,int exp);

    void sendonlinetologin(QString string);

private slots:
    void timedone();
    void receivemsg();
    void sendmsg(int i);
    void getquit();
    void getcheckuserfromlogin(QString checkname);
    void getcheckpokemonfromlogin(QString pname,QString ppid);
    void checkonlinefromlogin();

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
