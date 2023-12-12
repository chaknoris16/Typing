#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QInputMethod>
#include <QKeyEvent>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>
#include <QPalette>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QList>
#include <QSet>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>
#include <QDateTime>
#include <QSettings>
#include <QJsonArray>
#include <QComboBox>
#include <QColor>
#include <QLocale>
#include <iterator>
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
    void setTypingTestText(const QString& text){
        ui->testingTextEdit_tg->setPlainText(text);
    }
    TypingTestingPage* typingTest;
    QInputMethod* inputMethod;
    int calculationTypingSpeed(QTime &startTime, int correctElements);
    JsonConfigParser* jsonParser = new JsonConfigParser(this);
    QComboBox * comboBox_Course;
    CustomComboBox * comboBox_Lessons;
    CustomComboBox * comboBox_Exercises;
protected:
   void showStartWindow(bool showWindow);
private:
    ComboBoxManager* comboBoxManager = new ComboBoxManager(this);
    void addStyledComboBox(QVBoxLayout *layout, QComboBox *comboBox);
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
    QPushButton* pastButton = 0;
    QString labelText;
    QChar firstChar;
    int typingSpeed = 0;
    int correctElements = 0;
    int error_counter = 0;
    bool isTypingStarted;
    bool showWindow;
public:
    int get_typingSpeed() const{
        return typingSpeed;
    }
    void set_typingSpeed(int value_typingSpeed){
        typingSpeed = value_typingSpeed;
    }
    int get_errorCounter() const{
        return error_counter;
    }
    void set_errorCounter(int value_errorCounter) {
        error_counter = value_errorCounter;
    }
    QString mainText;
    QString get_currentMainText(const QString &fileName);
    QSettings *settings;
    QSqlDatabase& getDatabase() {
        return dbs;
    }
    int selectedCourseIndex;
    int selectedLessonIndex;
    int selectedExercisesIndex;
    void setCurrentIndexInComboBox(int courseIndex, int lessonsIndex, int exercisesIndex, QComboBox *ComboBox_Courses, QComboBox *ComboBox_Lessons, QComboBox *ComboBox_Exercises);
    void transitionToNextElement(int exerciseIndex, int lessonIndex, QJsonArray &exercisesArray);
    QTextCursor cursor;
    void setColorTextButton(QPushButton *button);
    QPushButton* buttonSearchByText(const QString text);
    void changeButtonBorder(QPushButton *button);
    void changeButtonStyle(QPushButton *button,QString);
    void changeColorTextInSelectButton(const QString& str, bool set_or_remove);
    QSettings copysettins;
    QString selectingFirstWordFromLine(const QString &str);
    void populateComboBoxesFromJsonFile();
    inline void blockSignalsComboBoxes(bool state);
    inline void fillCourseComboBox_M(QComboBox *comboBox, QJsonArray& coursesArray);

    void fillLessonsComboBox_M(QComboBox *comboBox, const QJsonArray& lessonsArray);
    void fillExercisesComboBox_M(QComboBox *comboBox, QJsonArray &exercisesArray);
    QSet<QChar> *extractUniqueLetters(QString text);
    QLocale determineLocale(const QString &language);
private:
    KeyboardLayoutLanguageController* keyboardLangControl;
    void signalAndSlots();
    void removeLetterFromLabel();
    void keyEventForTesting(QKeyEvent *event);
    void processingIncorrectLetter(const QString &, int flashDurationMs);
    void TimeOut(void (*foo), int interval);
    void callreadingFromFile();
    QTimer* timer = new QTimer(this);

    void createDb();

    void callingResultOutputTableForTrening();
    QSqlDatabase dbs;
    QTime startTime;
    QTimer *qtimer = new QTimer(this);
    int temp;
    int var;

    inline void setIncorectKeyboardLauoutMessage(QLocale locale);
    QLocale currentLocaleLanguage;
    inline void setQueryTyping(const QString& queryName);
    inline void setQueryTesting(const QString& queryName);
signals:
    void passingToTrening(QKeyEvent* event);
};

#endif // MAINWINDOW_H
