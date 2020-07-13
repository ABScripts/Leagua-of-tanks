#include <QList>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include "bullet.h"
#include "standarttank.h"
#include <qmath.h>

Bullet::Bullet(qreal x, qreal y, double angle) // qreal is just a typedef of double
    : QGraphicsRectItem(0, 0, size::width, size::height)
{
    timer = new QTimer();

    this->setRotation(angle);

    this->setPos(x, y);

    timer->start(5);

    connect(timer, &QTimer::timeout, this, &Bullet::move);
}

Bullet::~Bullet()
{
    delete timer;
}

void Bullet::move()
{
    QList<QGraphicsItem *> collideItems = this->collidingItems();

    for (int i = 0; i < collideItems.length(); ++i) {
        if (typeid (*collideItems[i]) == typeid(StandartTank)) {
                if ( dynamic_cast<StandartTank*>(collideItems[i])->typei == StandartTank::enemy) {
                    scene()->removeItem(collideItems[i]);
                    scene()->removeItem(this);
                    delete this;
                    return;
                }

            }
        }

    double angle = rotation();
    double dx = 4 * qSin(qDegreesToRadians(angle));
    double dy = 4 * qCos(qDegreesToRadians(angle));

    this->setPos(x() + dx, y() - dy);

    if ( pos().y() + this->rect().height() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}
