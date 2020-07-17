#ifndef TANK_MODEL
#define TANK_MODEL

#include <QObject>
#include <QPointF>

#include "../TankViewModels/tankviewmodel.h"

class TankModel: public QObject {
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

private:
    qreal mMoveSpeed;
    qreal mRotationSpeed;  // determines how fast the body of vehicle could be rotated
    std::vector<TankViewModel::MoveDir> mMoveDirectionBuffer; // vector pf rotation which enables multi key pressings
    QPointF mTrackMousePoint;  // the last position of mouse cursor

    struct Description {
        QString BodyImagePath { ":/tankimages/resources/tankbody.png" };

        qreal MoveSpeed; // the speed the tank is moving with

        qreal RotationSpeed; // the tank`s body rotation speed
    };
};

#endif
