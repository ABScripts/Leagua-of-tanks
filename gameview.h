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
        // getting the tank`s tower
        TankTower * tower = tank->getTower();

        // determines the top left point in which the bullet shiuld spawn
        QPoint spawnPoint = pointOnCircle(tank, fabs(tank->rect().center().y() - tower->y()) + Bullet::height,
                                                                     tower->rotation()-90 + tank->rotation());

        Bullet * bull = new Bullet(0, 0, tower->rotation() + tank->rotation());
        bull->setPos(spawnPoint.x(), spawnPoint.y());
        this->scene()->addItem(bull);
    }

    virtual void mouseMoveEvent(QMouseEvent *event) override {
    TankTower * tower = tank->getTower();

        // point where the projectile explode
        QPointF projectileStartPosition = {tank->x() + tank->rect().width() / 2, tank->y() + tank->rect().height()};
        // actually the point where the mouse currently is
        QPointF mousePosition = event->pos();

        double angle = atan2(mousePosition.y() - projectileStartPosition.y() + 5,
                             mousePosition.x() - projectileStartPosition.x() + 5);

        // remembers the last position of mouse when it was moved (products a slight movements)
        tank->setTrackMousePoint(QPoint(event->x(), event->y()));

        tower->setRotation(qRadiansToDegrees(angle) + 90 - tank->rotation());
        // + 90 becouse this func means:
        //      90
        //   180 + 0
        //      270
        // At the same time in our coordinate system 90 is replaced with 0 and all left numbers go all the way down.
    }

    // consider moving it in another file
    QPoint pointOnCircle(const StandartTank * const tank, double circleRadius, double angle) {
        double radAngle = qDegreesToRadians(angle);

        return QPoint( circleRadius * qCos(radAngle) + tank->x() + tank->rect().width() / 2  ,
                       circleRadius * qSin(radAngle) + tank->y() + tank->rect().height() / 2 );
    }

};



#endif // GAMEVIEW_H
