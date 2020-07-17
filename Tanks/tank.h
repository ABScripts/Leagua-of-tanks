#ifndef TANK_H
#define TANK_H

#include <QTimer>
#include <QObject>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "bullet.h"
#include "TankTowers/tanktower.h"

class Tank: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
//    enum Speed {
//        MoveSpeed = 3,
//        RotationSpeed = 1
//    };

//    enum Size {
//        Width = 100,
//        Height = 100
//    };

//    enum class TankType {
//        Enemy = 0,
//        Teammate,
//        Self
//    };

//    enum class MoveDir {
//        Left = 0,
//        Right,
//        Up,
//        Down
//    };

    Tank() = default;
    Tank(qreal x, qreal y, QGraphicsItem * parent = nullptr);
    virtual ~Tank();

    TankTower *getTower() const;
    void setTrackMousePoint(const QPointF &value);

    //QRectF boundingRect() const override;

public slots:
    virtual void move();

protected:
    TankTower * mTower_ptr; // each vehicle in game has a tower
    QTimer mMotionTimer; // timer which helps to move the vehicle smoothly
//    qreal mMoveSpeed;
//    qreal mRotationSpeed;  // determines how fast the body of vehicle could be rotated
//    std::vector<MoveDir> mMoveDirectionBuffer; // vector pf rotation which enables multi key pressings
//    QPointF mTrackMousePoint;  // the last position of mouse cursor

private:
//    void keyPressEvent(QKeyEvent * event) override;
//    void keyReleaseEvent(QKeyEvent * event) override;
    void applyRotation(MoveDir dir);
    void applyKeyPress(MoveDir dir, qreal dx, qreal dy);
};

#endif // TANK_H
