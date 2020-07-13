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
    enum size {
        width = 10,
        height = 40
    };

    Bullet(qreal x, qreal y, double angle);
    ~Bullet();

public slots:
    void move();

private:
    double angle;
    QTimer * timer;
};

#endif // BULLET_H
