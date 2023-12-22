#include "tableoutput.h"
#include <QHeaderView>
TableOutPut::TableOutPut(QWidget *parent)
    : QTableWidget(parent)
{
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void TableOutPut::setTable(QSqlQuery query)
{
    this->setRowCount(0);
    qDebug() << "Column Count:" << query.record().count();

    if (!query.isActive() || !query.next()) {
        qDebug() << "Error: No records found in the query.";
        return;
    }
    this->setColumnCount(query.record().count());
    for (int i = 0; i < query.record().count(); ++i) {
        this->setHorizontalHeaderItem(i, new QTableWidgetItem(query.record().fieldName(i)));
    }
    int row = 0;

    do {
        this->insertRow(row);
        for (int i = 0; i < query.record().count(); ++i) {
            this->setItem(row, i, new QTableWidgetItem(query.value(i).toString()));
        }
        ++row;
    } while (query.next());


    for (int col = 0; col < this->columnCount(); ++col) {
        horizontalHeader()->setSectionResizeMode(col, QHeaderView::Stretch);
    }
    this->setSortingEnabled(true);
    this->sortByColumn(0, Qt::DescendingOrder);
    this->hideColumn(0);
}
