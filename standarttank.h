#ifndef TANK_H
#define TANK_H

#include <QTimer>
#include <QObject>
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include "bullet.h"
#include "tanktower.h"

class StandartTank: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    enum Speed {
        MoveSpeed = 3,
        RotationSpeed = 1
    };

    enum Size {
        Width = 100,
        Height = 100
    };

    enum class TankType {
        Enemy = 0,
        Teammate,
        Self
    };

    enum class MoveDir {
        Left = 0,
        Right,
        Up,
        Down
    };

    StandartTank() = default;
    StandartTank(qreal x, qreal y, TankType type = TankType::Self);
    virtual ~StandartTank();

    TankTower *getTower() const;
    void setTrackMousePoint(const QPointF &value);
    TankType getTankType() const;

public slots:
    virtual void move();

protected:
    TankTower * mTower_ptr; // each vehicle in game has a tower
    QTimer mMotionTimer; // timer which helps to move the vehicle smoothly
    qreal mMoveSpeed;
    qreal mRotationSpeed;  // determines how fast the body of vehicle could be rotated
    std::vector<MoveDir> mMoveDirectionBuffer; // vector pf rotation which enables multi key pressings
    TankType mTankType; // tank`s type to distinguish enemies and allies
    QPointF mTrackMousePoint;  // the last position of mouse cursor

private:
    void keyPressEvent(QKeyEvent * event) override;
    void keyReleaseEvent(QKeyEvent * event) override;
    void applyRotation(MoveDir dir);
    void applyKeyPress(MoveDir dir, qreal dx, qreal dy);
};

#endif // TANK_H
