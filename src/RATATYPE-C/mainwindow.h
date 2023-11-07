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
#include <QSqlQuery>
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
#include "blindtypingtest.h"
#include "startwindow.h"
#include "jsonconfigparser.h"
#include "virtual_keyboard.h"
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
   // void recordSelectedIndex();
public:
    Ui::MainWindow *ui;
    blindTypingTest* typingTesting = new blindTypingTest(this);
    QInputMethod* inputMethod;
    int calculationTypingSpeed(QTime &startTime, int correctElements);
    bool get_echo();
    JsonConfigParser* jsonParser = new JsonConfigParser(this);
protected:
   void showStartWindow(bool showWindow);
private:
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
        return db;
    }
    int selectedCourseIndex;
    int selectedLessonIndex;
    int selectedExercisesIndex;
    void setCurrentIndexInComboBox(int courseIndex, int lessonsIndex, int exercisesIndex, QComboBox *ComboBox_Courses, QComboBox *ComboBox_Lessons, QComboBox *ComboBox_Exercises);
    void transitionToNextElement(int exerciseIndex, int lessonIndex, QJsonArray &exercisesArray);
    QTextCursor cursor;
    QVector<QPushButton *> buttons;
    void removeTextColor(QPushButton *button, const QString& color);
    void setColorTextButton(QPushButton *button);
    QPushButton* buttonSearchByText(const QString text);
    void changeButtonBorder(QPushButton *button);
    void changeButtonStyle(QPushButton *button,QString);
    void changeColorTextInSelectButton(const QString& str, bool set_or_remove);
    QSettings copysettins;
    QString selectingFirstWordFromLine(const QString &str, int courseIndex);
    void populateComboBoxesFromJsonFile();
    inline void blockSignalsComboBoxes(bool state);
    inline void fillCourseComboBox(QComboBox *comboBox, QJsonArray& coursesArray);
    void fillLessonsComboBox(QComboBox *comboBox, QJsonArray &lessonsArray);
    void fillExercisesComboBox(QComboBox *comboBox, QJsonArray &exercisesArray);
    QSet<QChar> *extractUniqueLetters(QString text);
    const QString &TYPING_QUERY_NAME = "typing_results";
    const QString &TESTING_QUERY_NAME = "testing_results";
    QLocale determineLocale(const QString &language);
private:
    void signalAndSlots();
    void removeLetterFromLabel();
    void keyEventForTesting(QKeyEvent *event);
    void processingIncorrectLetter(const QString &, int flashDurationMs);
    void TimeOut(void (*foo), int interval);
    void callreadingFromFile();
    QTimer* timer = new QTimer(this);
    void createDb();

    void callingResultOutputTableForTrening();
    QSqlDatabase db;
    QTime startTime;
    QTimer *qtimer = new QTimer(this);
    int temp;
    int var;

    inline void setIncorectKeyboardLauoutMessage(QLocale locale);
    QLocale currentLocaleLanguage;
    inline void setQueryTyping(const QString& queryName);
    inline void setQueryTesting(const QString& queryName);
};

#endif // MAINWINDOW_H
