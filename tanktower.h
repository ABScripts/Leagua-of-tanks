#ifndef TANKTOWER_H
#define TANKTOWER_H
#include <QGraphicsRectItem>
#include "bullet.h"

class TankTower: public QGraphicsRectItem
{
public:
    TankTower();
    TankTower(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent);

protected:
    double mRotationSpeed;
};

#endif // TANKTOWER_H
