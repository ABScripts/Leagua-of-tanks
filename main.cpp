#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include "standarttank.h"
#include "gameview.h"

namespace window{ // should be fixed
    const int width = 1600;
    const int height = 800;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene(&a);
    scene->setSceneRect(QRectF(0, 0, window::width, window::height));

    GameView * view = new GameView(scene);

    view->setFixedSize(window::width, window::height);

    view->show();

    return a.exec();
}
