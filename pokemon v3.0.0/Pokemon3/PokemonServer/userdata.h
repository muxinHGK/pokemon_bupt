#ifndef USERDATA_H
#define USERDATA_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QsqlDriver>
#include <QSqlError>
#include <QSqlRecord>
#include <QPainter>
#include <QPixmap>

class userdata
{
public:
    userdata();
    QString tempid,temppassword,tempp_id;
    int temppetmun,temponline,tempwin,temptotalgame;
    int temptype,temp_level,tempexp;
    int totaluser;
    int checkhighlevelpet(QString id);

    bool insert(QString id,QString password);
    bool update(QString id,QString password,int pet_num,int is_online,int win,int total_game);
    bool checkuser(QString id);
    bool checkpokemon(QString id,QString p_id);
    QString gettotal();
    bool updatapokemon(QString id,QString pid,int type,int level,int exp);
    bool insertpet(QString id,int pid,int type,int level);
    bool deletepet(QString id,int pid,int petnum);
};

#endif // USERDATA_H

