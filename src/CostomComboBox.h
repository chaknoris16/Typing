#ifndef COSTOMCOMBOBOX_H
#define COSTOMCOMBOBOX_H
#include <QComboBox>
#include <QStyledItemDelegate>
#include <QPainter>

class CustomComboBoxItemDelegate : public QStyledItemDelegate {
public:
    CustomComboBoxItemDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QStyleOptionViewItem optionCopy = option;
        initStyleOption(&optionCopy, index);


        bool isEnabled = index.data(Qt::UserRole).toBool();
        if (!isEnabled) {
            optionCopy.palette.setColor(QPalette::Text, QColor(Qt::gray));
        }

        QStyledItemDelegate::paint(painter, optionCopy, index);
    }
};

class CustomComboBox : public QComboBox {
public:
    CustomComboBox(QWidget *parent = nullptr) : QComboBox(parent) {
        setItemDelegate(new CustomComboBoxItemDelegate(this));
    }

    void setItemEnabled(int index, bool isEnabled) {
        if (index >= 0 && index < count()) {
            model()->setData(model()->index(index, 0), isEnabled, Qt::UserRole);
        }
    }

    bool getItemEnabled(int index){
        if(index >= 0)
        {
            return this->model()->data(model()->index(index, 0), Qt::UserRole).toBool();
        }
        return false;
    }
};
#endif // COSTOMCOMBOBOX_H
