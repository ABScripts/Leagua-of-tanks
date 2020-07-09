#ifndef TANKTOWER_H
#define TANKTOWER_H

#include <QGraphicsRectItem>

class TankTower: public QGraphicsRectItem
{
public:
    TankTower();
    TankTower(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent);
protected:
    double rotationSpeed;
};

#endif // TANKTOWER_H
