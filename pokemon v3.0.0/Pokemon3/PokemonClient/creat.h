#ifndef CREAT_H
#define CREAT_H

#include <QDialog>
#include <QPainter>
#include <QPixmap>

namespace Ui {
class Creat;
}

class Creat : public QDialog
{
    Q_OBJECT

public:
    explicit Creat(QWidget *parent = 0);
    ~Creat();
    QString cname,cpassword,ensurepass;
signals:
    void send(QString name,QString code);
public:
    Ui::Creat *ui;
    void paintEvent(QPaintEvent *);
private slots:
    void on_CcreatBtn_clicked();
    void on_Cname_editingFinished();
    void on_Cpass_editingFinished();
    void on_Csurepass_editingFinished();
};

#endif // CREAT_H
