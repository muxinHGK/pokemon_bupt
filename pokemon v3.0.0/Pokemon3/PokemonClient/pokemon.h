#ifndef POKEMON_H
#define POKEMON_H

#include <QDialog>
#include <QPainter>
#include <QPixmap>

namespace Ui {
class Pokemon;
}

class Pokemon : public QDialog
{
    Q_OBJECT

public:
    explicit Pokemon(QWidget *parent = 0);
    ~Pokemon();
    QString pname,ppid;
    QString petname,owner,petid,ptype;
    int level,exp,attack,defense,life,speed;

signals:
    void sendcheckpokemontologin(QString name,QString pid);

public slots:
    void getcheckpokemonfromlogin(QString id,QString pid,int type,int level,int exp);
private slots:
    void on_pushButton_clicked();

    void on_PCuser_editingFinished();

    void on_Ppetnum_editingFinished();

    void on_PcheckBtn_clicked();

private:
    Ui::Pokemon *ui;
    void paintEvent(QPaintEvent *);
};

#endif // POKEMON_H
