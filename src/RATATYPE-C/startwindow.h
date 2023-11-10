#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include "mainwindow.h"
#include "jsonconfigparser.h"
class MainWindow;
namespace Ui {
class startwindow;
}

class startwindow : public QDialog
{
    Q_OBJECT
public:
    explicit startwindow(MainWindow* mainWindow, QWidget *parent = nullptr);
    ~startwindow();
private:
    Ui::startwindow *ui;
    void connectSignalsAndSlots();
    void blockSignalsInComboBoxes();
    void unBlockSignalsInComboBoxes();
    void fillComboBoxes();
    void setNumbEntranceInLabel();
    MainWindow* mainWindow;
    JsonConfigParser* jsonParser = new JsonConfigParser(this);
};

#endif // STARTWINDOW_H
