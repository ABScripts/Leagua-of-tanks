#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class QTimer;

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    enum class Size {
        Width = 10,
        Height = 40
    };

    enum class Speed {
        MoveSpeed = 4
    };

    Bullet(qreal x, qreal y, qreal mAnglel);

public slots:
    void move();

private:
    qreal mAngle;
    QTimer * mMotionTimer_ptr;
};

#endif // BULLET_H
