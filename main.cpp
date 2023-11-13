#include "app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName( QString("My Application") );
    QApplication a(argc, argv);

    app w;
    //w.setWindowFlag(Qt::FramelessWindowHint); // This removes the title bar
    w.show();
    return a.exec();
}
