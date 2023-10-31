#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include "mainwindow.h"
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
signals:
    void changingValueInComboBox(int newLessonsIndex, int newExerciseIndex);
private:
    Ui::startwindow *ui;
    void connectSignalsAndSlots();
    void blockSignalsInComboBoxes();
    void unBlockSignalsInComboBoxes();
    void conclusionExercise();
    void fillComboBoxes();
    void setNumbEntranceInLabel();
    MainWindow* mainWindow;
    void nextLessons();

};

#endif // STARTWINDOW_H
