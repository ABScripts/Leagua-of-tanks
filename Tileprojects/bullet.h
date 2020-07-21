#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

QT_BEGIN_NAMESPACE
class QTimer;
QT_END_NAMESPACE

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

    enum class Speed {
        MoveSpeed = 6
    };

    enum class Size {
        Width = 5,
        Height = 20
    };

    Bullet(qreal x, qreal y, qreal mAnglel);

public slots:
    void move();

private:
    qreal mAngle;
    QTimer * mMotionTimer_ptr;
};

#endif // BULLET_H
