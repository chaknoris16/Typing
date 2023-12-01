#ifndef TABLEOUTPUT_H
#define TABLEOUTPUT_H

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
class TableOutPut : public QTableWidget
{
public:
    TableOutPut(QWidget *parent = nullptr);
    void setTable(QSqlQuery query);
private:
   // QTableWidget* _tableWidget;
};

#endif // TABLEOUTPUT_H
