#include "resultwindow.h"
#include "ui_resultwindow.h"
#include "mainwindow.h"

#include "vector_of_exercises.h"
class MainWindow;
resultwindow::resultwindow(MainWindow *mainWindow, QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::resultwindow),
    mainWindow(mainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    connectSignalsAndSlots();

}

resultwindow::~resultwindow()
{
    delete ui;
}


void resultwindow::setCounterTypingSpeed(int typingSpeed){
    ui->speed_typing_label_sw->setText(QString::number(typingSpeed));
    if(typingSpeed < minSpeed ){
        ui->main_label->setText(text_VerySlowly);
    }
}

void resultwindow::setErrorCounter(int errorsCounter){
    ui->counter_Label->setText(QString::number(errorsCounter));
    ui->text_under_counter->setText(text_ErrosUanderCounter);
    if(errorsCounter > get_maxNumberErrors()){
        ui->main_label->setText(text_FailedExercise);
        ui->instruct_label->setText(text_FailedExerciseInstruction);
        ui->nextLevelButton->setEnabled(false);
    } else ui->main_label->setText(text_СompletedExercise);
}

void resultwindow::setAccyracyСounter(int accyracy)
{
    ui->counter_Label->setText(QString::number(accyracy));
    ui->text_under_counter->setText(text_AcyratlyUanderCounter);
}

void resultwindow::connectSignalsAndSlots()
{
    connect(ui->againButton, &QPushButton::clicked, this, [=](){
        mainWindow->restart();
        this->close();
    });
    connect(ui->nextLevelButton, &QPushButton::clicked, this, [=](){
        mainWindow->moveOnNextExercise();
        this->close();
    });
}
void resultwindow::offOrOnNextButton(bool visible)
{
    ui->nextLevelButton->setVisible(visible);
}
