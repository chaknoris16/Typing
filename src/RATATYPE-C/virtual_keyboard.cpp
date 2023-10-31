#include "virtual_keyboard.h"
#include "ui_mainwindow.h"
#include <QString>
#include <iterator>
#include "mainwindow.h"
class MainWindow;
Virtual_Keyboard::Virtual_Keyboard(MainWindow* mainWindow, QWidget *parent):
    QWidget(parent),
    mainWindow(mainWindow)
{
    fillMapWhisPair(stringToButtonMap);
    FillVector_ButtonNewCharPair(buttonNewCharPair);
    FillVector_ButtonCharPair(buttonCharPair);

}
void Virtual_Keyboard::fillMapWhisPair(QMap<QString, QPushButton *> *map)
{   qDebug()<< mainWindow->ui->A_Button_2->objectName();
    map->insert("`", mainWindow->ui->apostropheButton_2);
    map->insert("~", mainWindow->ui->apostropheButton_2);
    map->insert("1", mainWindow->ui->oneButton_2);
    map->insert("!", mainWindow->ui->oneButton_2);
    map->insert("2", mainWindow->ui->twoButton_2);
    map->insert("@", mainWindow->ui->twoButton_2);
    map->insert("3", mainWindow->ui->threeButton_2);
    map->insert("#", mainWindow->ui->threeButton_2);
    map->insert("4", mainWindow->ui->fourButton_2);
    map->insert("$", mainWindow->ui->fourButton_2);
    map->insert("5", mainWindow->ui->fiveButton_2);
    map->insert("%", mainWindow->ui->fiveButton_2);
    map->insert("6", mainWindow->ui->sixButton_2);
    map->insert("^", mainWindow->ui->sixButton_2);
    map->insert("7", mainWindow->ui->sevenButton_2);
    map->insert("&", mainWindow->ui->sevenButton_2);
    map->insert("8", mainWindow->ui->eightButton_2);
    map->insert("*", mainWindow->ui->eightButton_2);
    map->insert("9", mainWindow->ui->nineButton_2);
    map->insert("(", mainWindow->ui->nineButton_2);
    map->insert("0", mainWindow->ui->zeroButton_2);
    map->insert(")", mainWindow->ui->zeroButton_2);
    map->insert("-", mainWindow->ui->minus_underlineButton_2);
    map->insert("_", mainWindow->ui->minus_underlineButton_2);
    map->insert("=", mainWindow->ui->equal_plusButton_2);
    map->insert("+", mainWindow->ui->equal_plusButton_2);
    map->insert("q", mainWindow->ui->Q_Button_2);
    map->insert("w", mainWindow->ui->W_Button_2);
    map->insert("e", mainWindow->ui->E_Button_2);
    map->insert("r", mainWindow->ui->R_Button_2);
    map->insert("t", mainWindow->ui->T_Button_2);
    map->insert("y", mainWindow->ui->Y_Button_2);
    map->insert("u", mainWindow->ui->U_Button_2);
    map->insert("i", mainWindow->ui->I_Button_2);
    map->insert("o", mainWindow->ui->O_Button_2);
    map->insert("p", mainWindow->ui->P_Button_2);
    map->insert("[", mainWindow->ui->square_bracketButton_2);
    map->insert("{", mainWindow->ui->square_bracketButton_2);
    map->insert("]", mainWindow->ui->square_bracket1Button_2);
    map->insert("}", mainWindow->ui->square_bracket1Button_2);
    map->insert("|", mainWindow->ui->backslashButton_2);
    map->insert("a", mainWindow->ui->A_Button_2);
    map->insert("s", mainWindow->ui->S_Button_2);
    map->insert("d", mainWindow->ui->D_Button_2);
    map->insert("f", mainWindow->ui->F_Button_2);
    map->insert("g", mainWindow->ui->G_Button_2);
    map->insert("h", mainWindow->ui->H_Button_2);
    map->insert("j", mainWindow->ui->J_Button_2);
    map->insert("k", mainWindow->ui->K_Button_2);
    map->insert("l", mainWindow->ui->L_Button_2);
    map->insert(";", mainWindow->ui->semicolonButton_2);
    map->insert(":", mainWindow->ui->semicolonButton_2);
    map->insert("'", mainWindow->ui->quotation_marksButton_2);
    QChar cr = '"';
    QString str = QString(cr);
    map->insert(str, mainWindow->ui->quotation_marksButton_2);
    map->insert("z", mainWindow->ui->Z_Button_2);
    map->insert("x", mainWindow->ui->X_Button_2);
    map->insert("c", mainWindow->ui->C_Button_2);
    map->insert("v", mainWindow->ui->V_Button_2);
    map->insert("b", mainWindow->ui->B_Button_2);
    map->insert("n", mainWindow->ui->N_Button_2);
    map->insert("m", mainWindow->ui->M_Button_2);
    map->insert(",", mainWindow->ui->comaButton_2);
    map->insert("<", mainWindow->ui->comaButton_2);
    map->insert(".", mainWindow->ui->pointButton_2);
    map->insert(">", mainWindow->ui->pointButton_2);
    map->insert("/", mainWindow->ui->slashButton_2);
    map->insert("?", mainWindow->ui->slashButton_2);
    map->insert(" ", mainWindow->ui->spaceButton_2);
    qDebug()<<"Map whis button created nrmally";
}

void Virtual_Keyboard::changeButtonColorByText(QSet<QChar> *uniqueLetters, QColor color)
{
    *colorSelectTexts = color;
    for (const QChar& c : *uniqueLetters)
    {
       QPushButton* button = (*stringToButtonMap)[QString(c)];
       button->setStyleSheet(button->styleSheet() +("color:" + color.name()+ ";"));
    }
}
void Virtual_Keyboard::saveDefaultColor(QSet<QChar> *uniqueLetters)
{
    for (const QChar& c : *uniqueLetters)
    {
        QPushButton* button = (*stringToButtonMap)[QString(c)];
        if(button)qDebug()<<"button it is not null";
        originalColors->insert(button, button->palette());
    }
}
void Virtual_Keyboard::revertButtonTextColorBack(QSet<QChar> *uniqueLetters)
{
    for (const QChar& c : *uniqueLetters)
    {
        QPushButton* button = (*stringToButtonMap)[QString(c)];
        button->setStyleSheet(button->styleSheet().remove(("color:" + colorSelectTexts->name()+";")));
    }
}

void Virtual_Keyboard::changeBorderButton(const QChar& textButton, QString& QSS_Border)
{
    deleteBorderButton(QSS_Border);

    QPushButton* button = (*stringToButtonMap)[QString(textButton)];
    button->setStyleSheet(button->styleSheet() + QSS_Border);
    pastButton = button;
}

void Virtual_Keyboard::flashButtonBackground(const QString& textButton, QColor background, int flashDurationMs)
{
    QPushButton* button = (*stringToButtonMap)[textButton];
    QString style = button->styleSheet();

    button->setStyleSheet(style + "background-color:" + background.name() + ";");

    QTimer::singleShot(flashDurationMs, [=]() {
        button->setStyleSheet(style);
    });
}

void Virtual_Keyboard::deleteBorderButton(QString& QSS_Border)
{
    if(!pastButton->styleSheet().isEmpty())
    {
        pastButton->setStyleSheet(pastButton->styleSheet().remove(QSS_Border));
    }
}
void Virtual_Keyboard::FillVector_ButtonNewCharPair(QVector<ButtonCharPair>& vectorPair) {
    vectorPair.push_back({mainWindow->ui->apostropheButton_2,'~'});
    vectorPair.push_back({mainWindow->ui->oneButton_2,'!'});
    vectorPair.push_back({mainWindow->ui->twoButton_2,'@'});
    vectorPair.push_back({mainWindow->ui->threeButton_2,'#'});
    vectorPair.push_back({mainWindow->ui->fourButton_2,'$'});
    vectorPair.push_back({mainWindow->ui->fiveButton_2,'%'});
    vectorPair.push_back({mainWindow->ui->sixButton_2,'^'});
    vectorPair.push_back({mainWindow->ui->sevenButton_2,'&'});
    vectorPair.push_back({mainWindow->ui->eightButton_2,'*'});
    vectorPair.push_back({mainWindow->ui->nineButton_2,'('});
    vectorPair.push_back({mainWindow->ui->zeroButton_2,')'});
    vectorPair.push_back({mainWindow->ui->minus_underlineButton_2,'_'});
    vectorPair.push_back({mainWindow->ui->equal_plusButton_2,'+'});
    vectorPair.push_back({mainWindow->ui->square_bracketButton_2,'{'});
    vectorPair.push_back({mainWindow->ui->square_bracket1Button_2,'}'});
    vectorPair.push_back({mainWindow->ui->semicolonButton_2,':'});
    vectorPair.push_back({mainWindow->ui->quotation_marksButton_2,'"'});
    vectorPair.push_back({mainWindow->ui->comaButton_2,'<'});
    vectorPair.push_back({mainWindow->ui->pointButton_2,'>'});
    vectorPair.push_back({mainWindow->ui->slashButton_2,'?'});

    qDebug()<< "buttonNewCharPair creeted normali";
}

void Virtual_Keyboard::FillVector_ButtonCharPair(QVector<ButtonCharPair>& vectorPair) {
    vectorPair.push_back({mainWindow->ui->apostropheButton_2,'`'});
    vectorPair.push_back({mainWindow->ui->oneButton_2,'1'});
    vectorPair.push_back({mainWindow->ui->twoButton_2,'2'});
    vectorPair.push_back({mainWindow->ui->threeButton_2,'3'});
    vectorPair.push_back({mainWindow->ui->fourButton_2,'4'});
    vectorPair.push_back({mainWindow->ui->fiveButton_2,'5'});
    vectorPair.push_back({mainWindow->ui->sixButton_2,'6'});
    vectorPair.push_back({mainWindow->ui->sevenButton_2,'7'});
    vectorPair.push_back({mainWindow->ui->eightButton_2,'8'});
    vectorPair.push_back({mainWindow->ui->nineButton_2,'9'});
    vectorPair.push_back({mainWindow->ui->zeroButton_2,'0'});
    vectorPair.push_back({mainWindow->ui->minus_underlineButton_2,'-'});
    vectorPair.push_back({mainWindow->ui->equal_plusButton_2,'='});
    vectorPair.push_back({mainWindow->ui->square_bracketButton_2,'['});
    vectorPair.push_back({mainWindow->ui->square_bracket1Button_2,']'});
    vectorPair.push_back({mainWindow->ui->semicolonButton_2,';'});
    vectorPair.push_back({mainWindow->ui->quotation_marksButton_2,'"'});
    vectorPair.push_back({mainWindow->ui->comaButton_2,','});
    vectorPair.push_back({mainWindow->ui->pointButton_2,'.'});
    vectorPair.push_back({mainWindow->ui->slashButton_2,'/'});

    qDebug()<< "buttonCharPair creeted normali";
}

void Virtual_Keyboard::changeShiftedCharacters(const QVector<ButtonCharPair> &vectorPair) {
    for (const auto& pair : vectorPair) {
        pair.button->setText(pair.character);
    }
}

