#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"
#include "vector_of_exercises.h"

class MainWindow;
startwindow::startwindow(MainWindow* mainWindow, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startwindow),
    mainWindow(mainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    fillComboBoxes();
    connectSignalsAndSlots();
    setNumbEntranceInLabel();
}
startwindow::~startwindow()
{
    delete ui;
}
void startwindow::fillComboBoxes()
{
    blockSignalsInComboBoxes();
    mainWindow->fillLessonsComboBox_M(ui->lessons_comboBox, jsonParser->lessonsArray);
    ui->lessons_comboBox->setCurrentIndex(jsonParser->getCurrentLessonIndex());
    mainWindow->fillExercisesComboBox_M(ui->exercisesComboBox,jsonParser->exercisesArray);
    ui->exercisesComboBox->setCurrentIndex(jsonParser->getCurrentExercisIndex());
    unBlockSignalsInComboBoxes();

}

void startwindow::setNumbEntranceInLabel(){
    QString labeltext = "Exercise " + QString::number(ui->exercisesComboBox->currentIndex()+1) + " of " + QString::number(mainWindow->jsonParser->exercisesArray.size());
    ui->exercise_label->setText(labeltext);
}

void startwindow::connectSignalsAndSlots()
{
    connect(ui->lessons_comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int newLessonsIndex){
        mainWindow->comboBox_Lessons->setCurrentIndex(newLessonsIndex);
        mainWindow->fillExercisesComboBox_M(ui->exercisesComboBox, mainWindow->jsonParser->exercisesArray);
    });


    connect(ui->exercisesComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int newExerciseIndex){
        mainWindow->comboBox_Exercises->setCurrentIndex(newExerciseIndex);
        this->setNumbEntranceInLabel();
    });
    connect(ui->begin_button, &QPushButton::clicked, this, [=](){
        this->close();
    });
}

void startwindow::blockSignalsInComboBoxes()
{
    ui->lessons_comboBox->blockSignals(true);
    ui->exercisesComboBox->blockSignals(true);
}

void startwindow::unBlockSignalsInComboBoxes()
{
    ui->lessons_comboBox->blockSignals(false);
    ui->exercisesComboBox->blockSignals(false);
}
