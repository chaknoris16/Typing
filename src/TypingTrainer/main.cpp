#include "mainwindow.h"
#include "ResourceCopier.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ResourceCopier copier;
    copier.copyResourceToLocal("course.json");

    MainWindow w;
    w.show();
    return a.exec();

}
