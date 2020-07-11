#include <QKeyEvent>
#include <qmath.h>
#include <vector>
#include "standarttank.h"

StandartTank::StandartTank(qreal x, qreal y, type tankType)
    : QGraphicsRectItem(0, 0, width, height) {
    typei = tankType;
    // setting speeds:
    moveSpeed = standartTankMoveSpeed;
    rotationSpeed = standartTankrotationSpeed;

    // rev this
    this->setPos(x, y);

//     tower = new TankTower(this->rect().width()/2 - (this->rect().width()-50) /2, this->rect().height() - (this->rect().height() + 40),
//                           this->rect().width()-50, this->rect().height() + 40, this);

    tower = new TankTower(0, 0, this->rect().width()-50, this->rect().height() + 40, this);

     tower->setPos(this->rect().width()/2 - tower->rect().width() / 2, -40);

     setTransformOriginPoint(rect().width() / 2, rect().height() / 2);

     // origin point is setted within this item`s coordinate system (not a parent!);
     tower->setTransformOriginPoint(tower->rect().width() / 2, tower->rect().height() / 2 + (tower->rect().height() - rect().height()) / 2);

     // hold it here just to distinguish the front side of the tank - should be deleted when the graphics are added
     QGraphicsRectItem * front = new QGraphicsRectItem(0, 0, this->rect().width(), this->rect().height() * 0.1, this);

     connect(&this->motionTimer, &QTimer::timeout, this, &StandartTank::move);
}

void StandartTank::keyPressEvent(QKeyEvent * event)
{
        moveDir pressed;
        switch(event->key()) {
            case Qt::Key_Left: pressed = left; break;
            case Qt::Key_Right: pressed = right; break;
            case Qt::Key_Up: pressed = up; break;
            case Qt::Key_Down: pressed = down; break;
            default: return; // if it is not the key we track than do nothing
        }

        for (auto it = dirv.begin(); it != dirv.end(); ++it) {
            // if we have this key already we will do nothing
            qDebug() << *it;
            if (*it == pressed) {
                return;
            }
        }

        dirv.push_back(pressed);
        motionTimer.start(10);
}

void StandartTank::keyReleaseEvent(QKeyEvent * event)
{
    if (event->isAutoRepeat()) {
        return;
    }

    moveDir released;
    switch(event->key()) {
        case Qt::Key_Left: released = left; break;
        case Qt::Key_Right: released = right; break;
        case Qt::Key_Up: released = up; break;
        case Qt::Key_Down: released = down; break;
        default: return;
    }


    for (auto it = dirv.begin(); it != dirv.end();) {
        // if was released the key that was pressed we will remove it
        if (*it == released) {
              it = dirv.erase(it);
        } else {
            ++it;
        }
    }
}

void StandartTank::applyKeyPress(StandartTank::moveDir dir, double dx, double dy)
{
    if (dir == down) {
        this->setPos(x() - dx, y() + dy);
    } else if (dir == up) {
        this->setPos(x() + dx, y() - dy);
    } else if (dir == left) {
        setRotation(rotation() - rotationSpeed);
        // prevents tower rotation while the tank`s body is rotating
        this->tower->setRotation(this->tower->rotation() + rotationSpeed);
    } else if (dir == right) {
        setRotation(rotation() + rotationSpeed);
        this->tower->setRotation(this->tower->rotation() - rotationSpeed);
    }
}

void StandartTank::move()
{
    double angle = rotation();

    double dx = moveSpeed * qSin(qDegreesToRadians(angle));
    double dy = moveSpeed * qCos(qDegreesToRadians(angle));

    // going through all of the keys and applying actions according to the dir-s
    std::for_each(dirv.begin(), dirv.end(), [&](moveDir & dir){
        applyKeyPress(dir, dx, dy);
    });

    //QGraphicsRectItem * tower = tank->getTower();

        // point where the projectile explode
        QPointF projectileStartPosition = {x() + rect().width() / 2, y() + rect().height()};
        // actually the point where the mouse currently is
        QPointF mousePosition = trackMousePoint;

         angle = atan2(mousePosition.y() - projectileStartPosition.y(),
                             mousePosition.x() - projectileStartPosition.x());

        tower->setRotation(qRadiansToDegrees(angle) + 90 - rotation());

}

void StandartTank::setTrackMousePoint(const QPointF &value)
{
    trackMousePoint = value;
}

StandartTank::~StandartTank()
{
    // Nevertheless tower var is created using "new", thanks to the parent-child reletions it`s deleted auto-lly
}

TankTower *StandartTank::getTower() const
{
    return tower;
}
