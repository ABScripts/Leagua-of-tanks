#ifndef TANKTOWER_H
#define TANKTOWER_H

#include <QGraphicsPixmapItem>
#include "bullet.h"

class TankTower: public QGraphicsPixmapItem
{
public:
    enum Size {
        Width = 50,
        Height = 140
    };

    TankTower() = default;
    TankTower(qreal x, qreal y, QGraphicsItem *parent);

protected:
    qreal mRotationSpeed;
};

#endif // TANKTOWER_H
