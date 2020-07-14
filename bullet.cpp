#include <QList>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include "bullet.h"
#include "standarttank.h"
#include <qmath.h>

Bullet::Bullet(qreal x, qreal y, double angle) // qreal is just a typedef of double
    : QGraphicsRectItem(0, 0, Bullet::Size::Width, Bullet::Size::Height)
{
    this->setRotation(angle);
    this->setPos(x, y);

    mMotionTimer_ptr = new QTimer();
    mMotionTimer_ptr->start(5);
    connect(mMotionTimer_ptr, &QTimer::timeout, this, &Bullet::move);
}

Bullet::~Bullet()
{
    delete mMotionTimer_ptr;
}

void Bullet::move()
{
    QList<QGraphicsItem *> collideItems = this->collidingItems();

    // checking for collidings
    for (int i = 0; i < collideItems.length(); ++i) {
        if (typeid (*collideItems[i]) == typeid(StandartTank)) {
            if ( dynamic_cast<StandartTank*>(collideItems[i])->getTankType() == StandartTank::TankType::Enemy) {
                scene()->removeItem(collideItems[i]);
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }

    double angle = rotation();
    double dx = Bullet::Speed::MoveSpeed * qSin(qDegreesToRadians(angle));
    double dy = Bullet::Speed::MoveSpeed * qCos(qDegreesToRadians(angle));

    this->setPos(x() + dx, y() - dy);

    if ( pos().y() + this->rect().height() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}
