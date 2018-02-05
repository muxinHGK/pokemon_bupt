#ifndef ONLINE_H
#define ONLINE_H

#include <QDialog>
#include <QPainter>
#include <QPixmap>

namespace Ui {
class Online;
}

class Online : public QDialog
{
    Q_OBJECT

public:
    explicit Online(QWidget *parent = 0);
    ~Online();
public slots:
    void getcheckonline(QString string);
private:
    Ui::Online *ui;
    void paintEvent(QPaintEvent *);
};

#endif // ONLINE_H
