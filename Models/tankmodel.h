#ifndef TANK_MODEL
#define TANK_MODEL

#include <QObject>

#include "ViewModels/tankviewmodel.h"

class TankModel: public QObject {
    Q_OBJECT

    enum MoveSpeed {
        MoveSpeed = 3, // the speed the tank is moving wit
        RotationSpeed = 1 // the tank`s body rotation speed
    };

    enum Size {
        Width = 100,
        Height = 100
    };

public:
    TankModel();
    QString bodyImagePath() const;
    qreal getMoveSpeed() const;
    qreal getRotationSpeed() const;

signals:
    void directionsChanged(int moveSpeed, int rotationSpeed);
public slots:
    void timerSlot();

private:
    const QString BodyImagePath { ":/tankimages/resources/tankbody.png" };
    qreal mMoveSpeed;
    qreal mRotationSpeed;      // determines how fast the body of vehicle could be rotated
    QString mBodyImagePath;
};

#endif
