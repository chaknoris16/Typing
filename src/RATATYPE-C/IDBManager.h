#ifndef IDBMANAGER_H
#define IDBMANAGER_H
#include <QVariantMap>
#include <QStringList>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
class IDBManager
{
public:
    IDBManager(const QString& DBName, const QString& queryName)
    : _DBName{DBName},
     _queryName{queryName}
    {
        _database = createDB(_DBName); //, connectionName
        qDebug()<<"create database";
        if(!_database.open()) qDebug()<<"database faild";

    }
    virtual ~IDBManager() = default;
    virtual void saveResult(const QVariantList& result) = 0;
    virtual QList<QVariantMap> getAllResults() const = 0;
    virtual void setQuery(const QString& queryName) = 0;
    virtual QSqlQuery getQuery() const = 0;
    QString _queryName;
    QSqlDatabase _database;
    QString connectionName = "MyConnection";
private:
    QString _DBName;
    QSqlDatabase createDB(const QString& DbName) //, const QString& connectionName
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  // , connectionName
        db.setDatabaseName(DbName);
        return db;
    }
};

#endif // IDBMANAGER_H
