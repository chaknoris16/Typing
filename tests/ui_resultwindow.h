/********************************************************************************
** Form generated from reading UI file 'resultwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTWINDOW_H
#define UI_RESULTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_resultwindow
{
public:
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3_sw;
    QLabel *speed_typing_label_sw;
    QLabel *label_4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2_sw;
    QLabel *counter_Label;
    QLabel *text_under_counter;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_sw;
    QLabel *main_label;
    QLabel *instruct_label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *againButton;
    QPushButton *nextLevelButton;

    void setupUi(QDialog *resultwindow)
    {
        if (resultwindow->objectName().isEmpty())
            resultwindow->setObjectName("resultwindow");
        resultwindow->resize(520, 357);
        resultwindow->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(255, 255, 255);"));
        frame = new QFrame(resultwindow);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 120, 520, 124));
        frame->setStyleSheet(QString::fromUtf8("border-radius: 0px;\n"
"background-color: rgb(234, 216, 24);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(310, 30, 101, 77));
        verticalLayout_3_sw = new QVBoxLayout(layoutWidget);
        verticalLayout_3_sw->setObjectName("verticalLayout_3_sw");
        verticalLayout_3_sw->setContentsMargins(0, 0, 0, 0);
        speed_typing_label_sw = new QLabel(layoutWidget);
        speed_typing_label_sw->setObjectName("speed_typing_label_sw");
        QFont font;
        font.setPointSize(30);
        speed_typing_label_sw->setFont(font);
        speed_typing_label_sw->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        speed_typing_label_sw->setAlignment(Qt::AlignCenter);

        verticalLayout_3_sw->addWidget(speed_typing_label_sw);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3_sw->addWidget(label_4);

        layoutWidget1 = new QWidget(frame);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(110, 30, 101, 77));
        verticalLayout_2_sw = new QVBoxLayout(layoutWidget1);
        verticalLayout_2_sw->setObjectName("verticalLayout_2_sw");
        verticalLayout_2_sw->setContentsMargins(0, 0, 0, 0);
        counter_Label = new QLabel(layoutWidget1);
        counter_Label->setObjectName("counter_Label");
        counter_Label->setFont(font);
        counter_Label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        counter_Label->setAlignment(Qt::AlignCenter);

        verticalLayout_2_sw->addWidget(counter_Label);

        text_under_counter = new QLabel(layoutWidget1);
        text_under_counter->setObjectName("text_under_counter");
        text_under_counter->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        text_under_counter->setAlignment(Qt::AlignCenter);

        verticalLayout_2_sw->addWidget(text_under_counter);

        layoutWidget2 = new QWidget(resultwindow);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(0, 30, 521, 77));
        verticalLayout_sw = new QVBoxLayout(layoutWidget2);
        verticalLayout_sw->setObjectName("verticalLayout_sw");
        verticalLayout_sw->setContentsMargins(0, 0, 0, 0);
        main_label = new QLabel(layoutWidget2);
        main_label->setObjectName("main_label");
        QFont font1;
        font1.setPointSize(21);
        main_label->setFont(font1);
        main_label->setStyleSheet(QString::fromUtf8("color: rgb(41, 69, 85);"));
        main_label->setScaledContents(false);
        main_label->setAlignment(Qt::AlignCenter);

        verticalLayout_sw->addWidget(main_label);

        instruct_label = new QLabel(layoutWidget2);
        instruct_label->setObjectName("instruct_label");
        instruct_label->setStyleSheet(QString::fromUtf8("color: rgb(148, 162, 170);"));
        instruct_label->setAlignment(Qt::AlignCenter);

        verticalLayout_sw->addWidget(instruct_label);

        widget = new QWidget(resultwindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 280, 521, 46));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        againButton = new QPushButton(widget);
        againButton->setObjectName("againButton");
        againButton->setMinimumSize(QSize(97, 44));
        againButton->setMaximumSize(QSize(97, 44));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Verdana")});
        font2.setPointSize(11);
        font2.setBold(false);
        againButton->setFont(font2);
        againButton->setCursor(QCursor(Qt::PointingHandCursor));
        againButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(255, 222, 14);\n"
"border: 3px solid rgb(170, 255, 255);\n"
"color: rgb(85, 85, 255);\n"
"border-radius: 5px;\n"
"}\n"
"QPushButton:hover{\n"
"border: 3px solid rgb(168, 168, 168);\n"
"}"));

        horizontalLayout->addWidget(againButton);

        nextLevelButton = new QPushButton(widget);
        nextLevelButton->setObjectName("nextLevelButton");
        nextLevelButton->setEnabled(true);
        nextLevelButton->setMinimumSize(QSize(78, 44));
        nextLevelButton->setMaximumSize(QSize(78, 44));
        QFont font3;
        font3.setPointSize(11);
        nextLevelButton->setFont(font3);
        nextLevelButton->setCursor(QCursor(Qt::PointingHandCursor));
        nextLevelButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 3px solid  rgb(163, 245, 245);\n"
"border-radius: 5px;\n"
"color: rgb(85, 170, 255);\n"
"background-color: rgb(255, 222, 14);\n"
"}\n"
"QPushButton:hover{\n"
"border: 3px solid rgb(168, 168, 168);\n"
"}"));

        horizontalLayout->addWidget(nextLevelButton);


        retranslateUi(resultwindow);

        QMetaObject::connectSlotsByName(resultwindow);
    } // setupUi

    void retranslateUi(QDialog *resultwindow)
    {
        resultwindow->setWindowTitle(QCoreApplication::translate("resultwindow", "Result", nullptr));
        speed_typing_label_sw->setText(QCoreApplication::translate("resultwindow", "123", nullptr));
        label_4->setText(QCoreApplication::translate("resultwindow", "\320\227\320\235./\320\245\320\222", nullptr));
        counter_Label->setText(QCoreApplication::translate("resultwindow", "5", nullptr));
        text_under_counter->setText(QCoreApplication::translate("resultwindow", "\320\237\320\236\320\234\320\230\320\233\320\236\320\232", nullptr));
        main_label->setText(QCoreApplication::translate("resultwindow", "\320\222\320\277\321\200\320\260\320\262\321\203 \320\267\320\260\320\262\320\265\321\200\321\210\320\265\320\275\320\276!", nullptr));
        instruct_label->setText(QString());
        againButton->setText(QCoreApplication::translate("resultwindow", "\320\251\320\225 \320\240\320\220\320\227", nullptr));
        nextLevelButton->setText(QCoreApplication::translate("resultwindow", "\320\224\320\220\320\233\320\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class resultwindow: public Ui_resultwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTWINDOW_H
