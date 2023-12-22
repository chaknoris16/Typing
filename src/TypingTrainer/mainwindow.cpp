#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_startwindow.h"
#include "resultwindow.h"
#include "vector_of_exercises.h"
#include <QKeyEvent>
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QtSql/QSqlDatabase>
#include <QHeaderView>
#include <QElapsedTimer>
#include <QSqlError>
#include <QThread>
#include <QTimer>
#include <QTime>
#include <QtSql/QSqlDatabase>
#include <QHeaderView>
#include <QElapsedTimer>
#include "QGraphicsDropShadowEffect"
#include <QShortcut>
#include <QSqlError>
#include "jsonconfigparser.h"
#include <QInputMethod>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->keyboardLangControl = new KeyboardLayoutLanguageController(ui->keyFieldInside_2);

    this->comboBox_Course = new QComboBox(this);
    this->comboBox_Lessons = new CustomComboBox(this);
    this->comboBox_Exercises = new CustomComboBox(this);
    this->languageComboBox = new CustomComboBox(this);

    this->comboBoxManager->setComboBox(ui->verticalLayout_Course, this->comboBox_Course);
    this->comboBoxManager->setComboBox(ui->verticalLayout_Lesson, this->comboBox_Lessons);
    this->comboBoxManager->setComboBox(ui->verticalLayout_Exercise, this->comboBox_Exercises);
    this->comboBoxManager->setComboBox(ui->horizontalLayout_13, this->languageComboBox);

    ui->pushButton_reset->setFocusPolicy(Qt::NoFocus);
    ui->widget_whis_settings->setVisible(false);
    virtualKeybord = new Virtual_Keyboard(this);
    this->isTypingStarted = false;
    this->settings = new QSettings("MySoft", "Star Runner");
    this->showWindow = settings->value("showWindow").toBool();
    ui->checkBox->setChecked(showWindow);
    this->mainText = jsonParser->getCurrentMainText();
    ui->keyFieldInside_2->setText(this->mainText);
    this->keyboardLangControl->determineLocale(jsonParser->getCurrentCourseName());
    virtualKeybord->changeBorderButton(jsonParser->getCurrentMainText().at(0), whiteBorderForButton);
    virtualKeybord->changeButtonColorByText(extractUniqueLetters(jsonParser->getCurrentMainText()), Qt::black);
    virtualKeybord->setKeyboardCharacters(virtualKeybord->getMapDefaultPair());
    this->populateComboBoxes();
    this->typingTest = new TypingTestingPage(ui->testingTextEdit_tg, this, this->languageComboBox);
    this->signalAndSlots();
    this->currentLocaleLanguage = this->keyboardLangControl->determineLocale(jsonParser->getCurrentCourseName());
    this->showStartWindow(showWindow);
}

MainWindow::~MainWindow()
{
    jsonParser->saveIndexes();
    delete ui;
    delete db;
    delete treningTableOutPut;
    delete testingTableOutPut;
    delete typingSpeedCalculator;
    delete typingTest;

}
void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Shift ) {
        qDebug()<<"Shift_Release";
        virtualKeybord->setKeyboardCharacters(virtualKeybord->getMapDefaultPair());
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Shift ) {
        qDebug()<<"Shift_Press";
        virtualKeybord->setKeyboardCharacters(virtualKeybord->getMapShiftedPair());
    }
    if(ui->widget_2->isVisible()){
        processing_keyPressEvent(event,ui->keyFieldInside_2);
    }else{
        emit this->passingToTrening(event);
    }
}

void MainWindow::processing_keyPressEvent(QKeyEvent *event, QLabel *textlabel){
    if (!event->text().isEmpty()){
        if(this->keyboardLangControl->checkLanguageMatch(this->currentLocaleLanguage)){
            labelText = textlabel->text();
            if (!labelText.isEmpty()) {
                firstChar = labelText.at(0);
                if (event->text().at(0) == firstChar) {
                    if(labelText.size() > 1){
                        virtualKeybord->changeBorderButton(textlabel->text().at(1), whiteBorderForButton);
                    }
                   this->removeLetterFromLabel();
                } else if(event->text().at(0).isLetterOrNumber())this->processingIncorrectLetter(event->text().at(0), 100);
            } else qDebug() << "labelText is empty" ;
        }else this->keyboardLangControl->setIncorectKeyboardLauoutMessage(this->currentLocaleLanguage);
    }
}

void MainWindow::processingIncorrectLetter(const QString& str, int flashDurationMs) {
    this->error_counter++;
    ui->errorCounterLabel->setStyleSheet("color: red; background-color: rgb(85, 197, 255);");
    virtualKeybord->flashButtonBackground(str, Qt::red, 100);
    QTimer::singleShot(flashDurationMs, [=]() {
        ui->errorCounterLabel->setStyleSheet("background-color: rgb(85, 197, 255);");
    });
    ui->errorCounterLabel->setText(QString::number(error_counter));
}


void MainWindow::removeLetterFromLabel()
{
    if (!isTypingStarted) {
        startTime = QTime::currentTime();
        connect(this->timer, &QTimer::timeout, this, [=](){
            this->typingSpeed = this->typingSpeedCalculator->calculationTypingSpeed(this->startTime, this->correctElements);
            ui->sign_per_minute_counter->setText(QString::number(this->typingSpeed));
            });
        this->timer->start(2000);
        isTypingStarted = true;
    }
    this->labelText.remove(0, 1);
    ui->keyFieldInside_2->setText(labelText);
    ++correctElements;
    if (ui->keyFieldInside_2->text().isEmpty()) {
        this->timer->stop();
        QVariantList result;
        result << this->comboBox_Exercises->currentText() << this->typingSpeed << this->error_counter;
        this->db->saveResult(result);
        this->resultWindowForTrening(this->error_counter);
        qDebug()<<"Label is empty";
    }
}

void MainWindow::resultWindowForTrening(int errorCounter) {
    resultwindow *resultWindow = new resultwindow(this);
    connect(resultWindow, &resultwindow::nextSignal, this, &MainWindow::moveOnNextExercise);
    connect(resultWindow, &resultwindow::againSignal, this, &MainWindow::restart);
    resultWindow->setCounterTypingSpeed(this->typingSpeed);
    resultWindow->setErrorCounter(errorCounter);
    resultWindow->exec();
}

CustomComboBox *MainWindow::getComboBox_Exercises() const
{
    return comboBox_Exercises;
}

CustomComboBox *MainWindow::getComboBox_Lessons() const
{
    return comboBox_Lessons;
}

void MainWindow::restart()
{
    qDebug()<<"restart - is start";
    virtualKeybord->revertButtonTextColorBack(extractUniqueLetters(this->mainText));
    virtualKeybord->deleteBorderButton(whiteBorderForButton);
    this->mainText = jsonParser->getCurrentMainText();
    ui->keyFieldInside_2->setText(this->mainText);
    this->comboBox_Course->setCurrentIndex(jsonParser->getCurrentCourseIndex());
    this->comboBox_Lessons->setCurrentIndex(jsonParser->getCurrentLessonIndex());
    this->comboBox_Exercises->setCurrentIndex(jsonParser->getCurrentExercisIndex());
    this->resetCounters();
    this->resetLabelValues();
    isTypingStarted = false;
    this->currentLocaleLanguage = this->keyboardLangControl->determineLocale(jsonParser->getCurrentCourseName());
    virtualKeybord->setMapKeyboardLauout(jsonParser->getCurrentKeyboardLayout().keyboardSymbols, jsonParser->getCurrentKeyboardLayout().shiftKeyboardSymbols);
    virtualKeybord->changeBorderButton(this->mainText.at(0), whiteBorderForButton);
    virtualKeybord->changeButtonColorByText(this->extractUniqueLetters(this->mainText), Qt::black);
}

inline void MainWindow::resetCounters()
{
    this->error_counter = 0;
    this->typingSpeed = 0;
    correctElements = 0;
}

inline void MainWindow::resetLabelValues()
{
    ui->sign_per_minute_counter->setText("0");
    ui->errorCounterLabel->setText("0");
}

void MainWindow::showStartWindow(bool showWindow) //QShowEvent *event
{   if(showWindow){
        startwindow* startWindow = new startwindow(this);
        startWindow->setWindowModality(Qt::ApplicationModal);
        ui->pushButton_reset->setFocusPolicy(Qt::NoFocus);
        startWindow->show();
    }
}

void MainWindow::moveOnNextExercise(){
    jsonParser->moveToNextExercise(jsonParser->exercisesArray, jsonParser->getCurrentExercisIndex(), jsonParser->getCurrentLessonIndex());
    restart();
}


QSet<QChar> *MainWindow::extractUniqueLetters(QString text)
{
    QSet<QChar>* uniqueLetters = new QSet<QChar>;
    for (const QChar& c : text) {
        if(!c.isSpace()) {
           uniqueLetters->insert(c.toLower());
        }
    }
    return uniqueLetters;
}

// QLocale MainWindow::determineLocale(const QString &language)
// {
//     if (language.toLower().contains("english")) {
//         return QLocale(QLocale::English);
//     } else if (language.toLower().contains("ukrainian")) {
//         return QLocale(QLocale::Ukrainian);
//     } else {
//         return QLocale::system();
//     }
// }



// QString MainWindow::selectingFirstWordFromLine(const QString& str){
//     return str.section(' ', 0, 0);
// }

void MainWindow::populateComboBoxes(){
    this->blockSignalsComboBoxes(true);
        this->comboBoxManager->fillCourseComboBox(this->comboBox_Course, jsonParser->coursesArray);
        //Courses
        this->comboBoxManager->fillLessonsComboBox(comboBox_Lessons, jsonParser->lessonsArray, jsonParser->getMaxLessonIndex());
        //Lessons
        this->comboBoxManager->fillExercisesComboBox(this->comboBox_Exercises, jsonParser->exercisesArray,jsonParser->determinateMaxExerciseIndex());
        this->comboBox_Course->setCurrentIndex(jsonParser->getCurrentCourseIndex());
        this->comboBox_Lessons->setCurrentIndex(jsonParser->getCurrentLessonIndex());
        this->comboBox_Exercises->setCurrentIndex(jsonParser->getCurrentExercisIndex());
        this->blockSignalsComboBoxes(false);
        qDebug()<< "CurrentCourseIndex" << jsonParser->getCurrentCourseIndex();
        qDebug() << "CurrentLessonIndex" << jsonParser->getCurrentLessonIndex();
        qDebug() << "CurrentExercisIndex" << jsonParser->getCurrentExercisIndex();
        qDebug() << "MaxLessonIndex" << jsonParser->getMaxLessonIndex();
        qDebug() << "MaxExerciseIndex" << jsonParser->getMaxExerciseIndex();
}

inline void MainWindow::blockSignalsComboBoxes(bool state)
{
    this->comboBox_Course->blockSignals(state);
    this->comboBox_Lessons->blockSignals(state);
    this->comboBox_Exercises->blockSignals(state);
}
// inline void MainWindow::fillCourseComboBox_M(QComboBox* comboBox, QJsonArray &coursesArray)
// {
//     for (const QJsonValue &courseValue : coursesArray) {
//         QJsonObject courseObject = courseValue.toObject();
//         QString courseName = courseObject["course"].toString();
//         comboBox->addItem(courseName);
//     }
// }

// void MainWindow::fillLessonsComboBox_M(QComboBox *comboBox, const QJsonArray& lessonsArray)
// {
//     comboBox->blockSignals(true);
//     comboBox->clear();
//     comboBox->blockSignals(false);
//     for(const auto& lessonValue : lessonsArray) {
//         auto lessonObject = lessonValue.toObject();
//         QString lessonName = lessonObject["name"].toString();
//         comboBox->addItem(lessonName);
//     }
// }

// void MainWindow::fillExercisesComboBox_M(QComboBox *comboBox, QJsonArray &exercisesArray)
// {
//     comboBox->blockSignals(true);
//     comboBox->clear();
//     comboBox->blockSignals(false);
//     for(const QJsonValue &exercisesValue : exercisesArray) {
//         QString exerciseName = selectingFirstWordFromLine(exercisesValue.toString());
//         comboBox->addItem(exerciseName);
//     }
// }

void MainWindow::signalAndSlots()
{
    connect(ui->pushButton_reset,&QPushButton::clicked, this, &MainWindow::restart);
    connect(ui->RestartButton_ts, &QPushButton::clicked, typingTest, &TypingTestingPage::setMainText);
    connect(ui->coursesButton, &QPushButton::clicked, this, [this]() {
        ui->widget_whis_settings->setVisible(!ui->widget_whis_settings->isVisible());
    });


    connect(ui->stackedWidget, QOverload<int>::of(&QStackedWidget::currentChanged), this, [this](int index){
        bool state = index == 1;
        this->comboBox_Course->setEnabled(!state);
        this->comboBox_Lessons->setEnabled(!state);
        this->comboBox_Exercises->setEnabled(!state);
        ui->on_or_offVirtKeybordButton->setEnabled(!state);
        this->languageComboBox->setEnabled(state);
    });

    connect(ui->on_or_offVirtKeybordButton, &QCheckBox::toggled, this, [this]() {
        ui->widget_whis_keybord->setVisible(!ui->widget_whis_keybord->isVisible());
    });

    connect(ui->simulatorsButton, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->testingButton, &QPushButton::clicked, this, [this]()
    {
        ui->stackedWidget->setCurrentIndex(1);

        typingTest->fillLanguageComboBox(this->languageComboBox, typingTest->getLyricsArray());
        typingTest->setMainText();
        connect(this->languageComboBox, &CustomComboBox::currentIndexChanged, typingTest, &TypingTestingPage::changeLanguage);
        connect(typingTest, &TypingTestingPage::setAcyracyCounter, ui->procentLabel, &QLabel::setText);
        connect(typingTest, &TypingTestingPage::setSpeedCounter, ui->speedCounterLabel_tg, &QLabel::setText);
        connect(this, &MainWindow::passingToTrening, typingTest, &TypingTestingPage::keyEvent);
    });

    connect(ui->resultsButton,&QPushButton::clicked,this,[this](){
        ui->stackedWidget->setCurrentIndex(3);
        this->treningTableOutPut->setTable(this->db->getQuery());
        this->testingTableOutPut->setTable(this->typingTest->getQuery());
        ui->table_trening_verticalLayout->removeWidget(this->treningTableOutPut);
        ui->table_trening_verticalLayout->addWidget(this->treningTableOutPut);
        ui->verticalLayout_10->removeWidget(this->testingTableOutPut);
        ui->verticalLayout_10->addWidget(this->testingTableOutPut);
    });

    connect(ui->checkBox, &QCheckBox::toggled, this, [this](bool checked) {
        settings->setValue("showWindow", checked);
        qDebug()<< checked;
    });

    connect(this->comboBox_Course, QOverload<int>::of(&QComboBox::currentIndexChanged), this,[this](int index){
        jsonParser->setCourseIndex(index);
        jsonParser->setLessonsArray(index);
        jsonParser->saveIndexes();
        this->comboBoxManager->fillLessonsComboBox(this->comboBox_Lessons, jsonParser->lessonsArray, jsonParser->getMaxLessonIndex());
    });

    connect(this->comboBox_Lessons, QOverload<int>::of(&QComboBox::currentIndexChanged), this,[this](int index){
        if(index <= jsonParser->getMaxLessonIndex())
        {
            jsonParser->setExercisesArray(index);
            int tempIndex = jsonParser->getMaxExerciseIndex();
            if(index < jsonParser->getMaxLessonIndex()) {
                tempIndex = jsonParser->exercisesArray.size() - 1;
            }
            jsonParser->setLessonIndex(index);
            this->comboBoxManager->fillExercisesComboBox(this->comboBox_Exercises, jsonParser->exercisesArray, tempIndex);
            this->comboBox_Exercises->setCurrentIndex(jsonParser->getCurrentExercisIndex());
            this->restart();
        }else {
            this->comboBox_Lessons->blockSignals(true);
            this->comboBox_Lessons->setCurrentIndex(jsonParser->getCurrentLessonIndex());
            this->comboBox_Lessons->blockSignals(false);
        }
    });

    connect(this->comboBox_Exercises, QOverload<int>::of(&QComboBox::currentIndexChanged), this,[this](int index){
        jsonParser->setExerciseIndex(index);
        if(index <= jsonParser->getMaxExerciseIndex()){
            jsonParser->setExerciseIndex(index);
            restart();
        }else{
            this->comboBox_Exercises->blockSignals(true);
            this->comboBox_Exercises->setCurrentIndex(jsonParser->getMaxExerciseIndex());
            this->comboBox_Exercises->blockSignals(false);
        }
    });


    connect(jsonParser, QOverload<int>::of(&JsonConfigParser::reFillExercisesCommbobox), this,[this](int index){
        this->comboBox_Exercises->blockSignals(true);
        this->comboBoxManager->fillExercisesComboBox(this->comboBox_Exercises, jsonParser->exercisesArray, index);
        this->comboBox_Exercises->blockSignals(false);
    });

    connect(jsonParser, QOverload<int>::of(&JsonConfigParser::reFillLessonsCommbobox), this,[this](int index){
        this->comboBox_Lessons->blockSignals(true);
        this->comboBox_Lessons->setItemEnabled(index, true);
        this->comboBox_Lessons->blockSignals(false);
    });
}
