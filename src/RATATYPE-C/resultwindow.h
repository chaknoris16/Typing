#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include "mainwindow.h"
#include <QDialog>
class MainWindow;
namespace Ui {
class resultwindow;
}

class resultwindow : public QDialog
{
    Q_OBJECT
 Ui::resultwindow *ui;
public:
    MainWindow* mainWindow;
    explicit resultwindow(MainWindow *mainWindow , QWidget *parent = nullptr);
    void setCounterTypingSpeed(int typingSpeed);
    void setErrorCounter(int errorsCounter);
    void setAccyracyСounter(int accyracy);
    int get_minSpeed(){
        return minSpeed;
    }
    int get_maxNumberErrors(){
        return maxNumberErrors;
    }
    void offOrOnNextButton(bool visible);
    ~resultwindow();
private:
    int minSpeed = 60;
    int maxNumberErrors = 2;
    void connectSignalsAndSlots();

};

#endif // RESULTWINDOW_H
