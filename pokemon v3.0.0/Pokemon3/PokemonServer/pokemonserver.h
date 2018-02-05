#ifndef POKEMONSERVER_H
#define POKEMONSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QObject>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>
#include <Qtimer>
#include "userdata.h"
#include <QPainter>
#include <QPixmap>

namespace Ui {
class PokemonServer;
}

class PokemonServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit PokemonServer(QWidget *parent = 0);
    ~PokemonServer();
    QTcpServer* Pokemonserver;
    QTcpSocket* Pokemonsocket;
    QString str;
    void sendmsg(int i);
    userdata database;
    QString quitname;
    int highpet=0;
private:
    Ui::PokemonServer *ui;
    void paintEvent(QPaintEvent *);
public slots:
    void slotCreateTcpServer();
    void receivemsg();
    void newconnect();
    void showdatabase();
};

#endif // POKEMONSERVER_H
