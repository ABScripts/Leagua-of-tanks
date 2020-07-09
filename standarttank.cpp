#include <QKeyEvent>
#include <qmath.h>
#include "standarttank.h"

StandartTank::StandartTank(qreal x, qreal y)
    : QGraphicsRectItem(0, 0, width, height) {

    // setting speeds:
    moveSpeed = standartTankMoveSpeed;
    rotationSpeed = standartTankrotationSpeed;

    // rev this
    this->setPos(x, y);

     tower = new TankTower(this->rect().width()/2 - (this->rect().width()-50) /2, this->rect().height() - (this->rect().height() + 40),
                           this->rect().width()-50, this->rect().height() + 40, this);

     setTransformOriginPoint(rect().width() / 2, rect().height() / 2);

     tower->setTransformOriginPoint(rect().width() / 2, rect().height() / 2);

     // hold it here just to distinguish the front side of the tank - should be deleted when the graphics are added
     QGraphicsRectItem * front = new QGraphicsRectItem(0, 0, this->rect().width(), this->rect().height() * 0.1, this);

     connect(&this->motionTimer, &QTimer::timeout, this, &StandartTank::move);
}

void StandartTank::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left) {
        dir = left;
        setRotation(rotation() - rotationSpeed);
    } else if (event->key() == Qt::Key_Right) {
        dir = right;
        setRotation(rotation() + rotationSpeed);
    } else if (event->key() == Qt::Key_Down) {
        dir = down;
    } else if (event->key() == Qt::Key_Up) {
        dir = up;
    }

    motionTimer.start(10);
}

void StandartTank::keyReleaseEvent(QKeyEvent * event)
{
    if (event->isAutoRepeat()) {
        return;
    }
    motionTimer.stop();

}

void StandartTank::move()
{
    double angle = rotation();

    double dx = moveSpeed * qSin(qDegreesToRadians(angle));
    double dy = moveSpeed * qCos(qDegreesToRadians(angle));

    if (dir == down) {
        this->setPos(x() - dx, y() + dy);
    } else if (dir == up) {
        this->setPos(x() + dx, y() - dy);
    }
}

StandartTank::~StandartTank()
{

}

TankTower *StandartTank::getTower() const
{
    return tower;
}
