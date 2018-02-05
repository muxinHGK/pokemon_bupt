#ifndef LOSEPET_H
#define LOSEPET_H

#include <QDialog>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>

namespace Ui {
class losepet;
}

class losepet : public QDialog
{
    Q_OBJECT

public:
    explicit losepet(QWidget *parent = 0);
    ~losepet();
    int choice1,choice2,choice3;
    QString mychoice;

signals:
    void ccc(QString str);

public slots:
    void bbb(int i);

private slots:
    void on_lineEdit_4_editingFinished();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::losepet *ui;
    void paintEvent(QPaintEvent *);
};

#endif // LOSEPET_H
