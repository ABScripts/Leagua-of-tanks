#include "bullet.h"

#include <QTimer>
#include <qmath.h>

Bullet::Bullet(qreal x, qreal y, qreal angle) // qreal is just a typedef of qreal
    : QGraphicsRectItem(0, 0, static_cast<int>(Bullet::Size::Width),
                              static_cast<int>(Bullet::Size::Height))
{
    setRotation(angle);
    setPos(x, y);

    mMotionTimer_ptr = new QTimer(this);
    mMotionTimer_ptr->start(5);
    connect(mMotionTimer_ptr, &QTimer::timeout, this, &Bullet::move);
}

void Bullet::move()
{
    QList<QGraphicsItem *> collideItems = this->collidingItems();
    qreal angle = rotation();
    qreal dx = static_cast<int>(Bullet::Speed::MoveSpeed) * qSin(qDegreesToRadians(angle));
    qreal dy = static_cast<int>(Bullet::Speed::MoveSpeed) * qCos(qDegreesToRadians(angle));

    this->setPos(x() + dx, y() - dy);

    if ( pos().y() + this->rect().height() < 0) {
        delete this; // gavnokod vsudy:)
    }
}
