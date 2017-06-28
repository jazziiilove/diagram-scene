#include "database.h"
#include <QtSql>
#include <QTableView>

//! [0]
void Database::connectDb()
{

    // connect mysql instance

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    QStringList driverList;
    driverList = QSqlDatabase::drivers();

    /*
    if (driverList.contains("QMYSQL", Qt::CaseInsensitive))
        qDebug()<<"No QMYSQL support! Check all needed dll-files!";
    else
        qDebug()<<"QMYSQL support is avaiable.";
    */

    db.setHostName("localhost");
    db.setDatabaseName("qtschema");
    db.setUserName("root");
    db.setPassword("root");
    if(db.open())
    {
        qDebug() << "connected " << db.hostName();
        //createModel(db);
    }else{
        qDebug()<<"Error while opening DB: " << db.databaseName()
               << db.lastError();
    }
}
//! [0]

