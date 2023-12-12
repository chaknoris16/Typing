#ifndef COMBOBOXMANAGER_H
#define COMBOBOXMANAGER_H
#include <QObject>
#include <QComboBox>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QVariant>
#include "CostomComboBox.h"
class ComboBoxManager : public QObject
{
    Q_OBJECT
public:
    ComboBoxManager(QObject *parent = nullptr) : QObject{parent}
    {

    }
    virtual ~ComboBoxManager() = default;

    template <typename ComboBoxType>
    void fillCourseComboBox(ComboBoxType* comboBox, const QJsonArray &coursesArray)
    {

        for (const auto& courseValue : coursesArray) {
            auto courseObject = courseValue.toObject();
            QString courseName = courseObject["course"].toString();
            comboBox->addItem(courseName);
        }
    }

    template <typename ComboBoxType>
    void fillLessonsComboBox(ComboBoxType *comboBox, const QJsonArray &lessonsArray, int def_index)
    {
        auto iter = lessonsArray.begin();
        comboBox->blockSignals(true);
        comboBox->clear();
        comboBox->blockSignals(false);
        for(const auto& lessonValue : lessonsArray) {
            auto lessonObject = lessonValue.toObject();
            QString lessonName = lessonObject["name"].toString();
            comboBox->addItem(lessonName);
            if(std::is_base_of<CustomComboBox, ComboBoxType>::value)
            {
                int currentIndex = iter - lessonsArray.begin();
                comboBox->setItemEnabled(currentIndex, currentIndex <= def_index);
            }
            ++iter;
        }
    }

    template <typename ComboBoxType>
    void fillExercisesComboBox(ComboBoxType *comboBox, const QJsonArray &exercisesArray, int def_index)
    {
        auto iter = exercisesArray.begin();
        comboBox->blockSignals(true);
        comboBox->clear();
        comboBox->blockSignals(false);
        for(const auto& exercisesValue : exercisesArray) {
            QString exerciseName = selectingFirstWordFromLine(exercisesValue.toString());
            comboBox->addItem(exerciseName);
            if(std::is_base_of<CustomComboBox, ComboBoxType>::value)
            {
                int currentIndex = iter - exercisesArray.begin();
                comboBox->setItemEnabled(currentIndex, currentIndex <= def_index);
            }
            ++iter;

        }
    }

    QString selectingFirstWordFromLine(const QString& str){
        return str.section(' ', 0, 0);
    }
};
#endif // COMBOBOXMANAGER_H
