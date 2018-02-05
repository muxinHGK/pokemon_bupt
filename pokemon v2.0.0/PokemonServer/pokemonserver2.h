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
#include "userdata2.h"

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
    quint16 blocksize;
    void sendmsg(int i);
    userdata database;
    QString quitname;
private:
    Ui::PokemonServer *ui;
public slots:
    void slotCreateTcpServer();
    void receivemsg();
    void newconnect();
    void showdatabase();
};

#endif // POKEMONSERVER_H
