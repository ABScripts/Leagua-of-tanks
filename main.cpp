#include <QApplication>

#include "maingamewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainGameWindow window;
    window.show();

    return a.exec();
}
