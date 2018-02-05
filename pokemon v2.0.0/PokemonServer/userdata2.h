#ifndef USERDATA_H
#define USERDATA_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QsqlDriver>
#include <QSqlError>
#include <QSqlRecord>

class userdata
{
public:
    userdata();
    QString tempid,temppassword,tempp_id;
    int temppetmun,temponline,tempwin,temptotalgame;
    int temptype,temp_level,tempexp;
    int totaluser;
    bool insert(QString id,QString password);
    bool update(QString id,QString password,int pet_num,int is_online,int win,int total_game);
    bool checkuser(QString id);
    bool checkpokemon(QString id,QString p_id);
    QString gettotal();
};

#endif // USERDATA_H

