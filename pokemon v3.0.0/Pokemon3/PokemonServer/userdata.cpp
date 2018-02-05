#include "userdata.h"

userdata::userdata()
{
    totaluser=0;
}

bool userdata::insert(QString id,QString password)
{
    QSqlDatabase db = QSqlDatabase::database("Pokemon0000");
    QSqlQuery query(db);

    query.prepare("insert into userdata values(?,?,?,?,?,?)");
    query.bindValue(0,id);
    query.bindValue(1,password);
    query.bindValue(2,3);              //拥有的精灵数目
    query.bindValue(3,0);              //是否在线，在线为1，不在线为0
    query.bindValue(4,0);              //获胜场次
    query.bindValue(5,0);              //总战斗场次
    bool success1=query.exec();
    for(int i=1;i<4;i++)
    {
        query.prepare("insert into pokemondata values(?,?,?,?,?)");
        query.bindValue(0,id);
        query.bindValue(1,i);                       //宠物的编号
        query.bindValue(2,rand()%8+1);              //随机分配一个宠物类型
        query.bindValue(3,1);              //等级
        query.bindValue(4,0);              //经验
        bool success=query.exec();
        if(!success)
        {
            QSqlError lastError = query.lastError();
            qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
            return false;
        }
    }
    if(!success1)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
        return false;
    }
    totaluser++;
    return true;

}

bool userdata::update(QString id,QString password,int pet_num,int is_online,int win,int total_game)
{
    QSqlDatabase db = QSqlDatabase::database("Pokemon0000");
    QSqlQuery query(db);

    query.prepare(QString("update userdata set ID=:ID,Password=:password,"
                          "pet_number=:pet_num,is_online=:is_online,win=:win,total_game=:total_game where ID= :ID"));
    query.bindValue(":ID",id);
    query.bindValue(":password",password);
    query.bindValue(":pet_num",pet_num);
    query.bindValue(":is_online",is_online);
    query.bindValue(":win",win);
    query.bindValue(":total_game",total_game);
    bool success=query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("更新失败"));
        return false;
    }
    return true;
}

bool userdata::checkuser(QString id)             //查用户信息
{
    QSqlDatabase db = QSqlDatabase::database("Pokemon0000");
    QSqlQuery query(db);
    query.prepare("select * from userdata where ID= :id");
    query.bindValue(":id",id);
    if(query.exec())
    {
        while(query.next())
        {
            this->tempid = query.value(0).toString().trimmed();
            this->temppassword = query.value(1).toString().trimmed();
            this->temppetmun = query.value(2).toInt();
            this->temponline = query.value(3).toInt();
            this->tempwin = query.value(4).toInt();
            this->temptotalgame = query.value(5).toInt();
        }
        return true;
    }
    else
        return false;
}

bool userdata::checkpokemon(QString id,QString p_id)
{
    QSqlDatabase db = QSqlDatabase::database("Pokemon0000");
    QSqlQuery query(db);
    query.prepare("select * from pokemondata where ID=:id AND p_id=:p_id");
    query.bindValue(":id",id);
    query.bindValue(":p_id",p_id);
    if(query.exec()){
        while(query.next()){
            this->tempid = query.value(0).toString().trimmed();
            this->tempp_id = query.value(1).toString().trimmed();       //去双引号
            this->temptype = query.value(2).toInt();
            this->temp_level  = query.value(3).toInt();
            this->tempexp = query.value(4).toInt();
        }
        return true;
    }
    else
        return false;
}

QString userdata::gettotal()
{
    QString str="G";
    int i=1;
    QSqlDatabase db = QSqlDatabase::database("Pokemon0000");
    QSqlQuery query(db);
    query.prepare("select * from userdata where is_online=:i");
    query.bindValue(":i",i);
    if(query.exec())
    {
        while(query.next())
        {
                //qDebug()<<"3333";
                str=str+query.value(0).toString()+"  ";
        }
    }
    //qDebug()<<"11111";
    qDebug()<<str;
   // qDebug()<<"22222";
    return str;
}
bool userdata::updatapokemon(QString id, QString pid, int type, int level, int exp)
{
    QSqlDatabase db = QSqlDatabase::database("Pokemon0000");
    QSqlQuery query(db);

    query.prepare(QString("update pokemondata set ID=:ID,p_id=:pid,"
                          "type=:type,p_level=:level,exp=:exp where ID=:ID AND p_id=:pid"));
    query.bindValue(":ID",id);
    query.bindValue(":pid",pid);
    query.bindValue(":type",type);
    query.bindValue(":level",level);
    query.bindValue(":exp",exp);
    query.bindValue(":ID",id);
    query.bindValue(":pid",pid);
    bool success=query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("更新失败"));
        return false;
    }
    return true;
}

bool userdata::insertpet(QString id,int pid,int type, int level)
{
    //qDebug() <<"121212212";
    QSqlDatabase db = QSqlDatabase::database("Pokemon0000");
    QSqlQuery query(db);
    query.prepare("insert into pokemondata values(?,?,?,?,?)");//插入表的最后面
    query.bindValue(0,id);
    query.bindValue(1,pid);                       //宠物的编号
    query.bindValue(2,type);              //宠物类型
    query.bindValue(3,level);              //等级
    query.bindValue(4,0);              //经验
    bool success=query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
        return false;
    }
}


bool userdata::deletepet(QString id, int pid,int petnum)
{
    //qDebug()<<"delet1111111e error!";
    QSqlDatabase db = QSqlDatabase::database("Pokemon0000");
    QSqlQuery query(db);
    query.prepare("delete from pokemondata where ID=:id AND p_id=:pid");
    query.bindValue(":id",id);
    query.bindValue(":pid",pid);
    bool suc=query.exec();
    if(!suc)
        qDebug()<<"delete error!";
    for(int i=pid;i<petnum;i++)
    {
        int a=i+1;
        query.prepare(QString("update pokemondata set p_id=:pid where ID=:ID AND p_id=:a"));
        query.bindValue(":pid",i);
        query.bindValue(":ID",id);
        query.bindValue(":a",a);
        query.exec();
    }
}

int userdata::checkhighlevelpet(QString id)
{
    int highlevelpet=0;
    QSqlDatabase db = QSqlDatabase::database("Pokemon0000");
    QSqlQuery query(db);
    query.prepare("select * from pokemondata where ID=:ID AND p_level=:15");
    query.bindValue(":i",id);
    query.bindValue(":15",15);
    if(query.exec())
    {
        while(query.next())
        {
               highlevelpet++;
        }
    }
    return highlevelpet;
}



