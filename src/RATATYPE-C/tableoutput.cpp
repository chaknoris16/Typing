#include "tableoutput.h"
#include <QHeaderView>
TableOutPut::TableOutPut(QTableWidget *tableWidget, QWidget *parent)
    : QTableWidget(parent),
    _tableWidget{tableWidget}
{

}

void TableOutPut::setTable(QSqlQuery query)
{
    this->_tableWidget->setColumnCount(query.record().count());
    for (int i = 0; i < query.record().count(); ++i) {
        this->_tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(query.record().fieldName(i)));
    }
    int row = 0;

    while (query.next()) {
        _tableWidget->insertRow(row);
        for (int i = 0; i < query.record().count(); ++i) {
            _tableWidget->setItem(row, i, new QTableWidgetItem(query.value(i).toString()));
        }
        ++row;
    }
    _tableWidget->hideColumn(0);
    for (int col = 0; col < query.record().count(); ++col) {
    _tableWidget->horizontalHeader()->setSectionResizeMode(col, QHeaderView::Stretch);
    }
    _tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
