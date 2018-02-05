#ifndef USER_H
#define USER_H

#include <QDialog>
#include <QDebug>
#include <QPainter>
#include <QPixmap>

namespace Ui {
class User;
}

class User : public QDialog
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = 0);
    ~User();
    QString ucheckname,uname,petnumstr,petlevelstr;
    int winrate;

signals:
    void sendcheckusertologin(QString name);//发送查询名字的信号，传到login

private slots:
    void on_UCuser_editingFinished();
    void on_UcheckBtn_clicked();

    void getcheckuserfromlogin(QString uname,int upetnum,int uonline,int uwin,int utotal,int uhighpet);//从login收到查询结果的处理槽

    void on_pushButton_2_clicked();

private:
    Ui::User *ui;
    void paintEvent(QPaintEvent *);
};

#endif // USER_H
