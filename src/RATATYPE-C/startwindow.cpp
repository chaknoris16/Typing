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

    mainWindow->fillLessonsComboBox(mainWindow->selectedCourseIndex, ui->lessons_comboBox, mainWindow->lessonsArray);
    ui->lessons_comboBox->setCurrentIndex(mainWindow->selectedLessonIndex);
    mainWindow->fillExercisesComboBox(mainWindow->selectedLessonIndex, ui->exercisesComboBox, mainWindow->exercisesArray);
    ui->exercisesComboBox->setCurrentIndex(mainWindow->selectedExercisesIndex);
}

void startwindow::setNumbEntranceInLabel(){
    QString labeltext = "Вправа " + QString::number(ui->exercisesComboBox->currentIndex()+1) + " з " + QString::number(mainWindow->exercisesArray.size());
    ui->exercise_label->setText(labeltext);
}

void startwindow::connectSignalsAndSlots()
{
    connect(ui->lessons_comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int newLessonsIndex){
        emit changingValueInComboBox(newLessonsIndex, ui->exercisesComboBox->currentIndex());
        mainWindow->fillExercisesComboBox(newLessonsIndex, ui->exercisesComboBox, mainWindow->exercisesArray);
    });

    connect(ui->exercisesComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int newExerciseIndex){
        emit changingValueInComboBox(ui->lessons_comboBox->currentIndex(), newExerciseIndex);
    });

    connect(ui->begin_button, &QPushButton::clicked, this, [=](){
        mainWindow->restart();
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
