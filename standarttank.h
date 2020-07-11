#ifndef TANK_H
#define TANK_H
#include <QTimer>
#include <QObject>
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <iostream>
#include "bullet.h"
#include "tanktower.h"

namespace {
    constexpr double standartTankMoveSpeed = 5;
    constexpr double standartTankrotationSpeed = 1;
}

class StandartTank: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    enum type {
        enemy = 0,
        teammate,
        self
    };

    enum size {
        width = 100,
        height = 100
    };

    enum moveDir {
        left = 0,
        right,
        up,
        down,
        none
    };

    type typei;

    StandartTank() = default;

    StandartTank(qreal x, qreal y, type tankType = self);

    virtual ~StandartTank();

    TankTower *getTower() const;

    void setTrackMousePoint(const QPointF &value);

public slots:
    virtual void move();

protected:
    // when creating this in spec. classes pass "this" as a parameter so it`ll be freed by system auto-lly.
    TankTower * tower; // each vehicle in game has a tower
    QTimer motionTimer; // timer which helps to move the vehicle smoothly
    double moveSpeed;
    // determines how fast the body of vehicle could be rotated
    double rotationSpeed;
    // vector pf rotation which enables multi key pressings
    std::vector<moveDir> dirv;

    QPointF trackMousePoint;


private:
    virtual void keyPressEvent(QKeyEvent * event) override;
    virtual void keyReleaseEvent(QKeyEvent * event) override;

    void applyRotation(moveDir dir);
    void applyKeyPress(moveDir dir, double dx, double dy);
};

#endif // TANK_H
