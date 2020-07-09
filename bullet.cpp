#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include "bullet.h"
#include <qmath.h>

Bullet::Bullet(qreal x, qreal y, double angle) // qreal is just a typedef of double
    : QGraphicsRectItem(0, 0, size::width, size::height)
{
    QTimer * timer = new QTimer();

    this->setRotation(angle);

    this->setPos(x, y);

    connect(timer, &QTimer::timeout, this, &Bullet::move);

    timer->start(5);
}

void Bullet::move()
{
    double angle = rotation();
    double dx = 4 * qSin(qDegreesToRadians(angle));
    double dy = 4 * qCos(qDegreesToRadians(angle));

    this->setPos(x() + dx, y() - dy);

    if ( pos().y() + this->rect().height() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}
