#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_startwindow.h"
#include "resultwindow.h"
#include "vector_of_exercises.h"
#include "text_for_print_json.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_reset->setFocusPolicy(Qt::NoFocus);
    ui->widget_whis_settings->setVisible(false);
    virtualKeybord = new Virtual_Keyboard(this);
    this->createDb();

    this->isTypingStarted = false;
    this->settings = new QSettings("MySoft", "Star Runner");
    this->showWindow = settings->value("showWindow").toBool();
    ui->checkBox->setChecked(showWindow);
    virtualKeybord = new Virtual_Keyboard(this);
    this->mainText = jsonParser->getCurrentMainText();
    ui->keyFieldInside_2->setText(this->mainText);
    virtualKeybord->changeBorderButton(jsonParser->getCurrentMainText().at(0), whiteBorderForButton);
    virtualKeybord->changeButtonColorByText(extractUniqueLetters(jsonParser->getCurrentMainText()), Qt::black);
    virtualKeybord->setKeyboardCharacters(virtualKeybord->getMapDefaultPair());
    this->inputMethod = QGuiApplication::inputMethod();
    this->populateComboBoxesFromJsonFile();
    this->signalAndSlots();
    this->currentLocaleLanguage = this->determineLocale(jsonParser->getCurrentCourseName());
    this->showStartWindow(showWindow);

}

MainWindow::~MainWindow()
{
    QSqlDatabase::database().close();
    delete ui;
}
bool MainWindow::get_echo()
{
    return true;
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
        typingTesting->keyEvent(event);
    }
}

void MainWindow::processing_keyPressEvent(QKeyEvent *event, QLabel *textlabel){
    if (!event->text().isEmpty()){
        if(inputMethod->locale() == this->currentLocaleLanguage){
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
        }else this->setIncorectKeyboardLauoutMessage(this->currentLocaleLanguage);
    }
}

inline void MainWindow::setIncorectKeyboardLauoutMessage(QLocale locale)
{
    QMessageBox incorrectkeyboardlayout;
    incorrectkeyboardlayout.setText("Incorrect keyboard layout");
    incorrectkeyboardlayout.setInformativeText("Please change the keyboard layout to " + QLocale::languageToString(locale.language()) +" layout.");
    incorrectkeyboardlayout.exec();
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


void MainWindow::removeLetterFromLabel() {
    if (!isTypingStarted) {
        startTime = QTime::currentTime();
        connect(this->timer, &QTimer::timeout, this, [=](){
            set_typingSpeed(this->calculationTypingSpeed(this->startTime, this->correctElements));
            ui->sign_per_minute_counter->setText(QString::number(get_typingSpeed()));
            });
        this->timer->start(2000);
        isTypingStarted = true;
    }
    this->labelText.remove(0, 1);
    ui->keyFieldInside_2->setText(labelText);
    ++correctElements;
    if (ui->keyFieldInside_2->text().isEmpty()) {
        this->timer->stop();
        this->callingResultOutputTableForTrening();
        this->resultWindowForTrening(get_errorCounter());
        qDebug()<<"Label is empty";
    }

}
void MainWindow::resultWindowForTrening(int errorCounter) {
    resultwindow *resultWindow = new resultwindow(this);
    resultWindow->setCounterTypingSpeed(get_typingSpeed());
    resultWindow->setErrorCounter(errorCounter);
    resultWindow->exec();
}



int MainWindow::calculationTypingSpeed(QTime& startTime, int correctElements)
{
    QTime currentTime = QTime::currentTime();
    int timeElapsed = startTime.msecsTo(currentTime);
    double minutesElapsed = timeElapsed / 60000.0;

    unsigned int typingSpeed = correctElements / minutesElapsed;
    qDebug()<<"typingSpeed"<< typingSpeed;
    return typingSpeed;
}
void MainWindow::restart()
{
    qDebug()<<"restart - is start";
    virtualKeybord->revertButtonTextColorBack(extractUniqueLetters(this->mainText));
    virtualKeybord->deleteBorderButton(whiteBorderForButton);
    this->mainText = jsonParser->getCurrentMainText();
    ui->keyFieldInside_2->setText(this->mainText);
    this->setCurrentIndexInComboBox(jsonParser->getCurrentCourseIndex(),jsonParser->getCurrentLessonIndex(),jsonParser->getCurrentExercisIndex(),ui->comboBox_Course,ui->comboBox_Lessons,ui->comboBox_Exercises);
    this->resetCounters();
    this->resetLabelValues();
    isTypingStarted = false;
    this->currentLocaleLanguage = this->determineLocale(jsonParser->getCurrentCourseName());
    virtualKeybord->setMapKeyboardLauout(jsonParser->getCurrentKeyboardLayout().keyboardSymbols, jsonParser->getCurrentKeyboardLayout().shiftKeyboardSymbols);
    virtualKeybord->changeBorderButton(this->mainText.at(0), whiteBorderForButton);
    virtualKeybord->changeButtonColorByText(this->extractUniqueLetters(this->mainText), Qt::black);
}
inline void MainWindow::resetCounters()
{
    this->set_errorCounter(0);
    this->set_typingSpeed(0);
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

QLocale MainWindow::determineLocale(const QString &language)
{
    if (language.toLower().contains("english")) {
        return QLocale(QLocale::English);
    } else if (language.toLower().contains("ukrainian")) {
        return QLocale(QLocale::Ukrainian);
    } else {
        return QLocale::system();
    }
}

void MainWindow::createDb(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("typing_data.db");
    if (!db.open()) {
        qDebug() << "Error: Could not open database.";
    }
    this->setQueryTyping(this->TYPING_QUERY_NAME);
    this->setQueryTesting(this->TESTING_QUERY_NAME);
}
inline void MainWindow::setQueryTyping(const QString &queryName)
{
    QSqlQuery typingResultQuery;
    typingResultQuery.exec("CREATE TABLE IF NOT EXISTS " + queryName + " ("
                           "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                           "exercise TEXT,"
                           "typing_speed INTEGER,"
                           "number_of_mistakes INTEGER,"
                           "datetime TEXT)");

    if (typingResultQuery.isActive()) {
        qDebug() << "Table" << queryName << "created successfully.";
    } else qDebug() << "Error: Could not create table " << queryName + ".";
}

inline void MainWindow::setQueryTesting(const QString &queryName)
{
    QSqlQuery testingResultQuery;
    testingResultQuery.exec("CREATE TABLE IF NOT EXISTS " + queryName + " ("
                 "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                 "typing_speed INTEGER,"
                 "accuracy INTEGER,"
                 "datetime TEXT)");
    if (testingResultQuery.isActive()) {
        qDebug() << "Table" << queryName << "created successfully.";
    } else qDebug() << "Error: Could not create table " << queryName + ".";
}
void MainWindow::callingResultOutputTableForTrening() {
    QString exercise = ui->comboBox_Exercises->currentText();
    QString dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QSqlQuery query;
    query.prepare("INSERT INTO typing_results (exercise, typing_speed, number_of_mistakes, datetime) "
                  "VALUES (:exercise, :typingSpeed, :numberOfMistakes, :dateTime)");
    query.bindValue(":exercise", exercise);
    query.bindValue(":typingSpeed", get_typingSpeed());
    query.bindValue(":numberOfMistakes", get_errorCounter());
    query.bindValue(":dateTime", dateTime);

    if (query.exec()) {
        qDebug() << "Data inserted successfully.";
    } else {
        qDebug() << "Error: Could not insert data.";
    }
}

QString MainWindow::selectingFirstWordFromLine(const QString& str, int courseIndex){
    int spaceIndex = str.indexOf(" ");
    if(str.left(spaceIndex) != str.mid(spaceIndex + 1,spaceIndex) && courseIndex == 1){
        return "Repetition";
    }
    if (spaceIndex != -1) {
        QString extractedString = str.left(spaceIndex);
        return extractedString;
    }
    return "";
}

void MainWindow::populateComboBoxesFromJsonFile(){
    this->blockSignalsComboBoxes(true);
        this->fillCourseComboBox(ui->comboBox_Course, jsonParser->coursesArray);
        //Courses
        this->fillLessonsComboBox(ui->comboBox_Lessons, jsonParser->lessonsArray);
        //Lessons
        this->fillExercisesComboBox(ui->comboBox_Exercises, jsonParser->exercisesArray);
        this->setCurrentIndexInComboBox(jsonParser->getCurrentCourseIndex(), jsonParser->getCurrentLessonIndex(), jsonParser->getCurrentExercisIndex(), ui->comboBox_Course, ui->comboBox_Lessons, ui->comboBox_Exercises);
    this->blockSignalsComboBoxes(false);
}
inline void MainWindow::blockSignalsComboBoxes(bool state)
{
    ui->comboBox_Course->blockSignals(state);
    ui->comboBox_Lessons->blockSignals(state);
    ui->comboBox_Exercises->blockSignals(state);
}
inline void MainWindow::fillCourseComboBox(QComboBox* comboBox, QJsonArray &coursesArray)
{
    for (const QJsonValue &courseValue : coursesArray) {
        QJsonObject courseObject = courseValue.toObject();
        QString courseName = courseObject["course"].toString();
        comboBox->addItem(courseName);
    }
}
void MainWindow::fillLessonsComboBox(QComboBox *comboBox, QJsonArray &lessonsArray)
{
    comboBox->blockSignals(true);
    comboBox->clear();
    comboBox->blockSignals(false);
    for(const QJsonValue &lessonValue : lessonsArray) {
        QJsonObject lessonObject = lessonValue.toObject();
        QString lessonName = lessonObject["name"].toString();
        comboBox->addItem(lessonName);
    }
}

void MainWindow::fillExercisesComboBox(QComboBox *comboBox, QJsonArray &exercisesArray)
{
    comboBox->blockSignals(true);
    comboBox->clear();
    comboBox->blockSignals(false);
    for(const QJsonValue &exercisesValue : exercisesArray) {
        QString exerciseName = selectingFirstWordFromLine(exercisesValue.toString(), selectedCourseIndex);
        comboBox->addItem(exerciseName);
    }
}
void MainWindow::setCurrentIndexInComboBox(int courseIndex, int lessonsIndex, int exercisesIndex, QComboBox *ComboBox_Courses, QComboBox *ComboBox_Lessons, QComboBox *ComboBox_Exercises)
{
    ComboBox_Courses->setCurrentIndex(courseIndex);
    ComboBox_Lessons->setCurrentIndex(lessonsIndex);
    ComboBox_Exercises->setCurrentIndex(exercisesIndex);
}

void MainWindow::transitionToNextElement(int exerciseIndex, int lessonIndex, QJsonArray &exercisesArray){
    if(exerciseIndex + 2 <= exercisesArray.size()){
        this->settings->setValue("selectedExercisesIndex",this->selectedExercisesIndex + 1);
        qDebug()<<"Next exercises"<<this->selectedExercisesIndex + 1;
    }else {
            this->settings->setValue("selectedLessonIndex", this->selectedLessonIndex + 1);
            qDebug() << "Next lesson" << this->selectedLessonIndex + 1;
    }
}

QString MainWindow::get_currentMainText(const QString &fileName)
{
    QFile jsonFile(fileName);
    if (jsonFile.open(QIODevice::ReadOnly)) {
        QByteArray jsonData = jsonFile.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
        QJsonObject coursesObject = jsonDoc.object();


        QJsonObject selectedCourse = coursesObject["courses"].toArray()[this->selectedCourseIndex].toObject();
        QJsonObject selectedLesson = selectedCourse["lessons"].toArray()[this->selectedLessonIndex].toObject();
        return selectedLesson["exercises"].toArray()[this->selectedExercisesIndex].toString();

        } else qWarning() << "Помилка при відкритті JSON файлу для читання.";
    return "";
}

void MainWindow::signalAndSlots()
{
    connect(ui->pushButton_reset,SIGNAL(clicked()),this,SLOT(restart()));
    connect(ui->RestartButton_ts,&QPushButton::clicked,this,&MainWindow::restart);

    connect(ui->coursesButton, &QPushButton::clicked, this, [this]() {
        ui->widget_whis_settings->setVisible(!ui->widget_whis_settings->isVisible());
    });
    connect(ui->stackedWidget, QOverload<int>::of(&QStackedWidget::currentChanged), this, [this](int index){
        bool state = index == 1;
        ui->comboBox_Course->setEnabled(!state);
        ui->comboBox_Lessons->setEnabled(!state);
        ui->comboBox_Exercises->setEnabled(!state);
        ui->on_or_offVirtKeybordButton->setEnabled(!state);
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
                ui->testingTextEdit_tg->setPlainText(tempTextForTesting);
                ui->testingTextEdit_tg->setReadOnly(true);
                ui->testingTextEdit_tg->setTextInteractionFlags(Qt::TextSelectableByMouse);
                cursor = ui->testingTextEdit_tg->textCursor();
                typingTesting->colorizeCurrentCharacter(cursor, QColor(0, 255, 0));
                qDebug()<<"Testing is on";
            });

    connect(ui->resultsButton,&QPushButton::clicked,this,[this](){
        ui->stackedWidget->setCurrentIndex(3);
        typingTesting->setupTestingTable("testing_results");
        QSqlTableModel *model_trening = new QSqlTableModel(this);
        model_trening->setTable("typing_results");
        model_trening->select();
        ui->tableView_whis_result->setModel(model_trening);
        ui->tableView_whis_result->hideColumn(model_trening->fieldIndex("id"));
        ui->tableView_whis_result->verticalHeader()->setVisible(false);
        int columnCount = model_trening->columnCount();
        for (int col = 0; col < columnCount; ++col) {
            ui->tableView_whis_result->horizontalHeader()->setSectionResizeMode(col, QHeaderView::Stretch);
            }

        });
    connect(ui->checkBox, &QCheckBox::toggled, this, [this](bool checked) {
        settings->setValue("showWindow", checked);
        qDebug()<< checked;
    });
    connect(ui->comboBox_Course, QOverload<int>::of(&QComboBox::currentIndexChanged), this,[this](int index){
        jsonParser->setCourseIndex(index);
        jsonParser->setLessonsArray(index);

        qDebug()<<jsonParser->getCurrentKeyboardLayout().keyboardSymbols;
        this->fillLessonsComboBox(ui->comboBox_Lessons, jsonParser->lessonsArray);

    });
    connect(ui->comboBox_Lessons, QOverload<int>::of(&QComboBox::currentIndexChanged), this,[this](int index){
        jsonParser->setLessonIndex(index);
        jsonParser->setExercisesArray(index);
        this->fillExercisesComboBox(ui->comboBox_Exercises, jsonParser->exercisesArray);
    });
    connect(ui->comboBox_Exercises, QOverload<int>::of(&QComboBox::currentIndexChanged), jsonParser, &JsonConfigParser::setExerciseIndex);
    connect(ui->comboBox_Exercises, &QComboBox::currentIndexChanged, this, &MainWindow::restart);
    //connect(ui->comboBox_Course, &QComboBox::currentIndexChanged, virtualKeybord, &Virtual_Keyboard::setMapKeyboardLauout);
}
