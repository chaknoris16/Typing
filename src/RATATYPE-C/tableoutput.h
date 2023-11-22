#ifndef TABLEOUTPUT_H
#define TABLEOUTPUT_H

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlRecord>
class TableOutPut : public QTableWidget
{
public:
    TableOutPut(QTableWidget *tableWidget, QWidget *parent = nullptr);
    void setTable(QSqlQuery query);
private:
    QTableWidget* _tableWidget;
};

#endif // TABLEOUTPUT_H
