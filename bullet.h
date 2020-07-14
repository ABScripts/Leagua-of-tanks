#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QEvent>
#include <QDebug>

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    enum Size {
        Width = 10,
        Height = 40
    };

    enum Speed {
        MoveSpeed = 4
    };

    Bullet(qreal x, qreal y, double mAngle);
    ~Bullet();

public slots:
    void move();

private:
    double mAngle;
    QTimer * mMotionTimer_ptr;
};

#endif // BULLET_H
