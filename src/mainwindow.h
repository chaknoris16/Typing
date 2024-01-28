#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QString>
#include <QTimer>
#include <QElapsedTimer>
#include <QPalette>
#include <QTextCharFormat>
#include <QSettings>
#include <QJsonArray>
#include <QComboBox>
#include <QColor>
#include <QLocale>
#include "resultwindow.h"
#include "startwindow.h"
#include "startwindow.h"
#include "jsonconfigparser.h"
#include "virtual_keyboard.h"
#include "IDBManager.h"
#include "DBTreningQuery.h"
#include "tableoutput.h"
#include "ITypingSpeedCalculator.h"
#include "TypingSpeedCalculator.h"
#include "typingtestingpage.h"
#include "keyboardlayoutlanguagecontroller.h"
#include "CostomComboBox.h"
#include "ComboBoxManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void restart();
    void moveOnNextExercise();

public:
    Ui::MainWindow *ui;
    JsonConfigParser* jsonParser = new JsonConfigParser(this);
    CustomComboBox *getComboBox_Lessons() const;
    CustomComboBox *getComboBox_Exercises() const;
    void populateComboBoxes();
    inline void blockSignalsComboBoxes(bool state);
private:

    TypingTestingPage* typingTest;
    ComboBoxManager* comboBoxManager = new ComboBoxManager(this);
    void showStartWindow(bool showWindow);
    TableOutPut* treningTableOutPut = new TableOutPut();
    TableOutPut* testingTableOutPut = new TableOutPut();
    IDBManager* db = new DBTreningQuery("typing_result", "trening");
    ITypingSpeedCalculator* typingSpeedCalculator = new TypingSpeedCalculator();
    Virtual_Keyboard* virtualKeybord;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void processing_keyPressEvent(QKeyEvent *event,QLabel *textlabel);
    inline void resetCounters();
    inline void resetLabelValues();
    void resultWindowForTrening(int errorCounter);
    QString labelText;
    QChar firstChar;
    int typingSpeed = 0;
    int correctElements = 0;
    int error_counter = 0;
    bool isTypingStarted;
    bool showWindow = true;
    QComboBox* comboBox_Course;
    CustomComboBox* comboBox_Lessons;
    CustomComboBox* comboBox_Exercises;
    CustomComboBox* languageComboBox;
    QString mainText;
    QSettings *settings;
    QSet<QChar> *extractUniqueLetters(QString text);
    KeyboardLayoutLanguageController* keyboardLangControl;
    void signalAndSlots();
    void removeLetterFromLabel();
    void processingIncorrectLetter(const QString &, int flashDurationMs);
    QTimer* timer = new QTimer(this);
private:

    QSqlDatabase dbs;
    QTime startTime;
    QTimer *qtimer = new QTimer(this);
    QLocale currentLocaleLanguage;

signals:
    void passingToTrening(QKeyEvent* event);
};

#endif // MAINWINDOW_H
