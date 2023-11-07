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
    mainWindow->fillLessonsComboBox(ui->lessons_comboBox, jsonParser->lessonsArray);
    ui->lessons_comboBox->setCurrentIndex(jsonParser->getCurrentLessonIndex());
    mainWindow->fillExercisesComboBox(ui->exercisesComboBox,jsonParser->exercisesArray);
    ui->exercisesComboBox->setCurrentIndex(jsonParser->getCurrentExercisIndex());
    //qDebug()<<"currentIndex"<<mainWindow->ui->comboBox_Exercises->currentIndex();
    unBlockSignalsInComboBoxes();
}

void startwindow::setNumbEntranceInLabel(){
    QString labeltext = "Вправа " + QString::number(ui->exercisesComboBox->currentIndex()+1) + " з " + QString::number(mainWindow->jsonParser->exercisesArray.size());
    ui->exercise_label->setText(labeltext);
}

void startwindow::connectSignalsAndSlots()
{
    connect(ui->lessons_comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int newLessonsIndex){
        jsonParser->setLessonIndex(newLessonsIndex);
        jsonParser->setExercisesArray(newLessonsIndex);
        mainWindow->fillExercisesComboBox(ui->exercisesComboBox, jsonParser->exercisesArray);
    });

    connect(ui->exercisesComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), jsonParser, &JsonConfigParser::setExerciseIndex);
    //connect(ui->exercisesComboBox, &QComboBox::currentIndexChanged, mainWindow, &MainWindow::restart);
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
