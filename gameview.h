#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsItem>
#include <qmath.h>
#include "standarttank.h"

namespace tank {
    enum size {
      width = 100, height = 100
    };
}

class GameView: public QGraphicsView
{
private:
    StandartTank * tank;
public:
    GameView();

    GameView(QGraphicsScene * scene)
        : QGraphicsView(scene) {
        setMouseTracking(true);
        tank = new StandartTank(scene->width() / 2 - tank::width / 2, scene->height() / 2 - tank::height / 2);
        tank->setFlag(QGraphicsItem::ItemIsFocusable);
        tank->setFocus();

        this->scene()->addItem(tank);
    }

    virtual void mousePressEvent(QMouseEvent *event) override {
        // getting the tank`s tower
        QGraphicsRectItem * tower = tank->getTower();
        //actually the top left corner where the bullet will appear

        QPointF bulletAppearPoint = {tank->x() + tank->rect().width() / 2 - Bullet::width / 2,
                                     tank->y() + tank->rect().height() / 2 - Bullet::height /2};

        Bullet * bull = new Bullet(bulletAppearPoint.x(), bulletAppearPoint.y(), tower->rotation() + tank->rotation());
        bull->setTransformOriginPoint(bull->rect().width() / 2, bull->rect().height() / 2);
        this->scene()->addItem(bull);
    }

    virtual void mouseMoveEvent(QMouseEvent *event) override {
    QGraphicsRectItem * tower = tank->getTower();

        // point where the projectile explode
        QPointF projectileStartPosition = {tank->x() + tank->rect().width() / 2, tank->y() + tank->rect().height()};
        // actually the point where the mouse currently is
        QPointF mousePosition = event->pos();

        double angle = atan2(mousePosition.y() - projectileStartPosition.y(),
                             mousePosition.x() - projectileStartPosition.x());

        tower->setRotation(qRadiansToDegrees(angle) + 90 - tank->rotation());
        // + 90 becouse this func means:
        //      90
        //   180 + 0
        //      270
        // At the same time in our coordinate system 90 is replaced with 0 and all left numbers go all the way down.
    }
};

#endif // GAMEVIEW_H
