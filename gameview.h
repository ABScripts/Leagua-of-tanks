#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsItem>
#include <qmath.h>
#include <QDebug>
#include "standarttank.h"

class GameView: public QGraphicsView
{
private:
    StandartTank * tank;
public:
    GameView();

    GameView(QGraphicsScene * scene)
        : QGraphicsView(scene) {
        setMouseTracking(true);
        installEventFilter(this);

        tank = new StandartTank(scene->width() / 2 - StandartTank::width / 2, scene->height() / 2 - StandartTank::height / 2);
        tank->setFlag(QGraphicsItem::ItemIsFocusable);
        tank->setFocus();

        StandartTank * enemyTank = new StandartTank(100, 100, StandartTank::enemy);
        this->scene()->addItem(enemyTank);

        this->scene()->addItem(tank);


    }

    virtual void mousePressEvent(QMouseEvent *event) override {
    //This part should be fixed!!!

//        // getting the tank`s tower
//        TankTower * tower = tank->getTower();
//        //actually the top left corner where the bullet will appear


//        int angle = tower->rotation();

//        qDebug() << tower->rotation();

//        double si = qSin(angle);
//        double co = qCos(angle);

//        QPoint currentMiddle = tower->middle;
//        QPoint center = QPoint(tank->x() + tank->rect().width() / 2, tank->y() + tank->rect().height() / 2);


//        X = x0 + (x - x0) * cos(a) - (y - y0) * sin(a);

//       Y = y0 + (y - y0) * cos(a) + (x - x0) * sin(a);

//        QGraphicsRectItem * dot = new QGraphicsRectItem(0,0,5,5);
//        dot->setPos(tower->middle.x(), tower->middle.y());

//        this->scene()->addItem(dot);

//        Bullet * bull = new Bullet(0, 0, tower->rotation() + tank->rotation());
// bull->setPos(f.x(), f.y());
//        bull->setTransformOriginPoint(bull->rect().width() / 2, bull->rect().height() / 2);
//        this->scene()->addItem(bull);
    }

    virtual void mouseMoveEvent(QMouseEvent *event) override {
    TankTower * tower = tank->getTower();

        // point where the projectile explode
        QPointF projectileStartPosition = {tank->x() + tank->rect().width() / 2, tank->y() + tank->rect().height()};
        // actually the point where the mouse currently is
        QPointF mousePosition = event->pos();

        double angle = atan2(mousePosition.y() - projectileStartPosition.y(),
                             mousePosition.x() - projectileStartPosition.x());

        tank->setTrackMousePoint(QPoint(event->x(), event->y()));

        tower->setRotation(qRadiansToDegrees(angle) + 90 - tank->rotation());


        angle = tower->rotation();

        qDebug() << tower->rotation();

        double si = qSin(qDegreesToRadians(angle));
        double co = qCos(qDegreesToRadians(angle));
        QPoint currentMiddle = tower->middle;
        QPoint center = QPoint(tank->x() + tank->rect().width() / 2, tank->y() + tank->rect().height() / 2);

        tower->middle = QPoint(center.x() + (currentMiddle.x() - center.x()) * co - (currentMiddle.y() - center.y()) * si,
                               center.y() + (currentMiddle.y() - center.y()) * co + (currentMiddle.x() - center.x()) * si);


        QGraphicsRectItem * dot = new QGraphicsRectItem(0,0,5,5);
        dot->setPos(tower->middle.x(), tower->middle.y());

        this->scene()->addItem(dot);
        // + 90 becouse this func means:
        //      90
        //   180 + 0
        //      270
        // At the same time in our coordinate system 90 is replaced with 0 and all left numbers go all the way down.
    }

};



#endif // GAMEVIEW_H
