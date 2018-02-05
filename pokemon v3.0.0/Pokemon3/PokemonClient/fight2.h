#ifndef FIGHT2_H
#define FIGHT2_H

#include <QDialog>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>

namespace Ui {
class fight2;
}

class fight2 : public QDialog
{
    Q_OBJECT

public:
    explicit fight2(QWidget *parent = 0);
    ~fight2();
    QString mypetname,mypetid,mypettype;   //精灵名字和编号 类型
    int mytype,mylevel,myexp,mylife,myattack,mydefense,myspeed; //用于记录出战精灵的等级等信息
    QString yourpetname,yourpettype;//对手精灵名字
    int yourtype,yourlevel,yourlife,yourexp,yourattack,yourdefense,yourspeed; // 用于记录对手精灵的类型和等级等信息
    int mynowlife,yournowlife;//用于记录对战过程中双方的当前生命值
    QString skill1,skill2;//用于记录双方的技能名称

    void startfight2();

signals:
    void getpet(QString str);
    void winfight2(int result,int petlevel,int petexp);
    void losefight2(int result,int petlevel,int petexp);

public slots:
    void getpetfrommain(QString str1,QString str2,int a,int b,int c);

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_19_editingFinished();

    void on_lineEdit_20_editingFinished();

    void on_lineEdit_21_editingFinished();

    void on_pushButton_2_clicked();

private:
    Ui::fight2 *ui;
    void paintEvent(QPaintEvent *);
};

#endif // FIGHT2_H
