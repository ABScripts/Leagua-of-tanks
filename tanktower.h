#ifndef TANKTOWER_H
#define TANKTOWER_H
#include <QGraphicsRectItem>
#include "bullet.h"

class TankTower: public QGraphicsRectItem
{
public:
    TankTower();
    TankTower(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent);

    QPoint middle;

    Bullet *bull;

protected:
    double rotationSpeed;
};

#endif // TANKTOWER_H
