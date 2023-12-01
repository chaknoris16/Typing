#ifndef DBTESTINGQUERY_H
#define DBTESTINGQUERY_H
#include "IDBManager.h"
#include <QSqlQuery>
#include <QVariantList>
#include <QString>
#include <QDateTime>
#include <QSqlError>
class DBTestingQuery : public IDBManager
{
public:
    DBTestingQuery(const QString& DBName, const QString& queryName) : IDBManager(DBName, queryName)
    {
        if(!_database.open()) qDebug()<<"database faild";
        setQuery(_queryName);
    }

    ~DBTestingQuery() override
    {
        _database.close();
    }
    void setQuery(const QString& queryName) override
    {
        QSqlQuery testingResultQuery(QSqlDatabase::database(_queryName + "_connection"));
        testingResultQuery.exec("CREATE TABLE IF NOT EXISTS " + queryName + " ("
                                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                "\"Typing Speed\" INTEGER,"
                                "\"Accuracy\" INTEGER,"
                                "\"Date Time\" TEXT)");
        if (!testingResultQuery.isActive()) qDebug() << "Error: Could not create table " << _queryName + ".";
    }

    void saveResult(const QVariantList& result) override
    {
        if(_database.open())
        {
            QSqlQuery query(QSqlDatabase::database(_queryName + "_connection"));
            query.prepare("INSERT INTO " + _queryName + " (\"Typing Speed\", \"Accuracy\", \"Date Time\") "
                          "VALUES (:typing_speed, :accuracy, :datetime)");
            query.bindValue(":typing_speed", result[0].toInt());
            query.bindValue(":accuracy", result[1].toInt());
            query.bindValue(":datetime", QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
            if (query.exec()) {
                qDebug() << "Data inserted successfully!";
            } else {
                qDebug() << "Error inserting data:" << query.lastError().text();
            }
        }else qDebug() << "Error: Could not open the database.";
    }

    QList<QVariantMap> getAllResults() const override
    {
        QList<QVariantMap> results;

        QSqlQuery query(QSqlDatabase::database(_queryName + "_connection"));
        query.exec("SELECT * FROM " + _queryName);
        while (query.next()) {
            QVariantMap result;
            result["typing_speed"] = query.value("typing_speed").toInt();
            result["accuracy"] = query.value("accuracy").toInt();
            result["datetime"] = query.value("datetime").toDateTime();

            results.append(result);
        }

        return results;
    }

    QSqlQuery getQuery() const override
    {
        QSqlQuery query = QSqlQuery(QSqlDatabase::database(_queryName + "_connection"));
        query.exec("SELECT * FROM " + _queryName);
        return query;
    }
};

#endif // DBTESTINGQUERY_H
