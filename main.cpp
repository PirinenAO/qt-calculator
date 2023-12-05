#include "app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName( QString("My Application") );
    QApplication a(argc, argv);

    app w;
    w.show();
    return a.exec();
}
