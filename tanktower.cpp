#include "tanktower.h"
#include <QAbstractGraphicsShapeItem>

TankTower::TankTower()
{

}

TankTower::TankTower(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, width, height, parent)
{
    middle = QPoint(scenePos().x() + 25, scenePos().y());
}
