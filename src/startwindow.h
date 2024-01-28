#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include "mainwindow.h"
#include "jsonconfigparser.h"
#include "ComboBoxManager.h"
#include "CostomComboBox.h"
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
    ComboBoxManager* comboBoxManager = new ComboBoxManager(this);
    CustomComboBox* lesson_ComboBox;
    CustomComboBox* exercise_ComboBox;
};

#endif // STARTWINDOW_H
