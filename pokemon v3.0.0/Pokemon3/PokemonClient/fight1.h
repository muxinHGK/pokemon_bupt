#ifndef FIGHT1_H
#define FIGHT1_H

#include <QDialog>
#include <QTime>
#include <QTimer>
#include <QApplication>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>

namespace Ui {
class fight1;
}

class fight1 : public QDialog
{
    Q_OBJECT

public:
    explicit fight1(QWidget *parent = 0);
    ~fight1();
    QString mypetname,mypetid,mypettype;   //精灵名字和编号 类型
    int mytype,mylevel,myexp,mylife,myattack,mydefense,myspeed; //用于记录出战精灵的等级等信息
    QString yourpetname,yourpettype;//对手精灵名字
    int yourtype,yourlevel,yourlife,yourexp,yourattack,yourdefense,yourspeed; // 用于记录对手精灵的类型和等级等信息
    int mynowlife,yournowlife;//用于记录对战过程中双方的当前生命值
    QString skill1,skill2;//用于记录双方的技能名称
    void startfight1();

signals:
    void getpet1(QString pid);
    void winfight1(int result,int level,int exp,int gettype,int getlevel);
    void losefight1(int result,int level,int exp);
    //void getyourpet(int type,int level);
    //void losemypet();

public slots:
    void getpetfrommain1(QString str1,QString str2,int a,int b,int c);

private slots:
    void on_lineEdit_10_editingFinished();

    void on_lineEdit_11_editingFinished();

    void on_lineEdit_9_editingFinished();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::fight1 *ui;
    void paintEvent(QPaintEvent *);
};

#endif // FIGHT1_H
