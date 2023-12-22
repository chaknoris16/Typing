#ifndef RESOURCECOPIER_H
#define RESOURCECOPIER_H

#include <QFile>
#include <QCoreApplication>
#include <QDir>
#include <QObject>
class ResourceCopier :public QObject
{
public:
    void copyResourceToLocal(const QString& fileName)
    {
        QString localDir = QCoreApplication::applicationDirPath();
        Q_ASSERT_X(!fileName.isEmpty(), "vcopyResourceToLocal", "The file name must not be empty");
        QString localJsonFilePath = localDir + "/" + fileName;

        if (!QFile::exists(localJsonFilePath)) {
            QFile jsonFile(":/fails/course.json");
            if (jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QFile localJsonFile(localJsonFilePath);
                if (localJsonFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QByteArray jsonData = jsonFile.readAll();
                    localJsonFile.write(jsonData);

                    localJsonFile.close();
                    jsonFile.close();
                }
            }
        }
    }
};

#endif // RESOURCECOPIER_H
