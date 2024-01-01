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
    this->lesson_ComboBox = new CustomComboBox(this);
    this->exercise_ComboBox = new CustomComboBox(this);
    comboBoxManager->setComboBox(ui->verticalLayout_lesson, this->lesson_ComboBox);
    comboBoxManager->setComboBox(ui->verticalLayout_exercise, this->exercise_ComboBox);
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
    comboBoxManager->fillLessonsComboBox(this->lesson_ComboBox, mainWindow->jsonParser->lessonsArray, mainWindow->jsonParser->getMaxLessonIndex());
    this->lesson_ComboBox->setCurrentIndex(mainWindow->jsonParser->getCurrentLessonIndex());
    this->comboBoxManager->fillExercisesComboBox(this->exercise_ComboBox, mainWindow->jsonParser->exercisesArray, mainWindow->jsonParser->determinateMaxExerciseIndex());
    this->exercise_ComboBox->setCurrentIndex(mainWindow->jsonParser->getCurrentExercisIndex());
    unBlockSignalsInComboBoxes();
}

void startwindow::setNumbEntranceInLabel(){
    QString labeltext = "Exercise " + QString::number(this->exercise_ComboBox->currentIndex()+1) + " of " + QString::number(mainWindow->jsonParser->exercisesArray.size());
    ui->exercise_label->setText(labeltext);
}

void startwindow::connectSignalsAndSlots()
{
    connect(this->lesson_ComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int newLessonsIndex){
        mainWindow->getComboBox_Lessons()->setCurrentIndex(newLessonsIndex);
        this->comboBoxManager->fillExercisesComboBox(this->exercise_ComboBox, mainWindow->jsonParser->exercisesArray, mainWindow->jsonParser->getMaxExerciseIndex());
    });


    connect(this->exercise_ComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int newExerciseIndex){
        mainWindow->getComboBox_Exercises()->setCurrentIndex(newExerciseIndex);
        this->setNumbEntranceInLabel();
    });
    connect(ui->begin_button, &QPushButton::clicked, this, [=](){
        this->close();
    });
}

void startwindow::blockSignalsInComboBoxes()
{
    this->lesson_ComboBox->blockSignals(true);
    this->exercise_ComboBox->blockSignals(true);
}

void startwindow::unBlockSignalsInComboBoxes()
{
    this->lesson_ComboBox->blockSignals(false);
    this->exercise_ComboBox->blockSignals(false);
}
