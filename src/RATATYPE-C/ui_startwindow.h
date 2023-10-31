/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startwindow
{
public:
    QPushButton *begin_button;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *lesson_label;
    QLabel *exercise_label;
    QComboBox *lessons_comboBox;
    QComboBox *exercisesComboBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *hint_label_1;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *startwindow)
    {
        if (startwindow->objectName().isEmpty())
            startwindow->setObjectName("startwindow");
        startwindow->resize(520, 325);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startwindow->sizePolicy().hasHeightForWidth());
        startwindow->setSizePolicy(sizePolicy);
        startwindow->setMinimumSize(QSize(520, 320));
        startwindow->setMaximumSize(QSize(520, 325));
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        startwindow->setFont(font);
        startwindow->setLayoutDirection(Qt::LeftToRight);
        startwindow->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(255, 255, 255);"));
        startwindow->setSizeGripEnabled(true);
        startwindow->setModal(true);
        begin_button = new QPushButton(startwindow);
        begin_button->setObjectName("begin_button");
        begin_button->setGeometry(QRect(210, 250, 104, 44));
        QFont font1;
        font1.setPointSize(11);
        font1.setStyleStrategy(QFont::PreferDefault);
        begin_button->setFont(font1);
        begin_button->setCursor(QCursor(Qt::PointingHandCursor));
        begin_button->setFocusPolicy(Qt::NoFocus);
        begin_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0.508288, y1:0.267, x2:0.519525, y2:1, stop:0.0994475 rgba(255, 222, 14, 255), stop:0.464088 rgba(227, 193, 0, 255));\n"
"}\n"
"QPushButton:hover{\n"
"border-radius: 5px;\n"
"border: 3px solid rgb(170, 255, 255);\n"
"}"));
        layoutWidget = new QWidget(startwindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(18, 30, 481, 55));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lesson_label = new QLabel(layoutWidget);
        lesson_label->setObjectName("lesson_label");
        lesson_label->setStyleSheet(QString::fromUtf8("color: rgb(111, 111, 111);"));
        lesson_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lesson_label);

        exercise_label = new QLabel(layoutWidget);
        exercise_label->setObjectName("exercise_label");
        QFont font2;
        font2.setPointSize(17);
        exercise_label->setFont(font2);
        exercise_label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        exercise_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(exercise_label);

        lessons_comboBox = new QComboBox(startwindow);
        lessons_comboBox->setObjectName("lessons_comboBox");
        lessons_comboBox->setGeometry(QRect(10, 190, 201, 24));
        lessons_comboBox->setCursor(QCursor(Qt::PointingHandCursor));
        exercisesComboBox = new QComboBox(startwindow);
        exercisesComboBox->setObjectName("exercisesComboBox");
        exercisesComboBox->setGeometry(QRect(310, 190, 191, 24));
        exercisesComboBox->setCursor(QCursor(Qt::PointingHandCursor));
        layoutWidget1 = new QWidget(startwindow);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(60, 110, 391, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        hint_label_1 = new QLabel(layoutWidget1);
        hint_label_1->setObjectName("hint_label_1");
        QFont font3;
        font3.setPointSize(11);
        hint_label_1->setFont(font3);
        hint_label_1->setStyleSheet(QString::fromUtf8("color: rgb(0, 141, 211);"));
        hint_label_1->setAlignment(Qt::AlignCenter);
        hint_label_1->setWordWrap(true);

        horizontalLayout->addWidget(hint_label_1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(startwindow);

        QMetaObject::connectSlotsByName(startwindow);
    } // setupUi

    void retranslateUi(QDialog *startwindow)
    {
        startwindow->setWindowTitle(QCoreApplication::translate("startwindow", "\320\237\320\276\321\207\320\260\321\202\320\270?", nullptr));
        begin_button->setText(QCoreApplication::translate("startwindow", "\320\237\320\236\320\247\320\220\320\242\320\230", nullptr));
        lesson_label->setText(QCoreApplication::translate("startwindow", "\320\243\320\240\320\236\320\232", nullptr));
        exercise_label->setText(QCoreApplication::translate("startwindow", "\320\222\320\277\321\200\320\260\320\262\320\260 9 \320\267 14", nullptr));
        hint_label_1->setText(QCoreApplication::translate("startwindow", "\320\237\321\226\321\201\320\273\321\217 \320\272\320\276\320\266\320\275\320\276\320\263\320\276 \320\275\320\260\321\202\320\270\321\201\320\272\320\260\320\275\320\275\321\217 \320\277\320\276\320\262\320\265\321\200\321\202\320\260\320\271 \320\277\320\260\320\273\321\214\321\206\321\226 \320\264\320\276 \320\276\321\201\320\275\320\276\320\262\320\275\320\276\321\227 \320\277\320\276\320\267\320\270\321\206\321\226\321\227 ASDF \342\200\223 JKL;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startwindow: public Ui_startwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
