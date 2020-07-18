#ifndef TANK_MODEL
#define TANK_MODEL

#include <QPointF>
#include <QObject>

#include "../TankViewModels/tankviewmodel.h"
#include "movedirenum.h"

class QTimer;

class TankModel: public QObject {
    Q_OBJECT

    enum MoveSpeed {
        MoveSpeed = 3, // the speed the tank is moving wit
        RotationSpeed = 1 // the tank`s body rotation speed
    };

    enum Size {
        Width = 100, // consider those two properties to move to the enum
        Height = 100 // this as well
    };

public:
    TankModel();
    QString bodyImagePath() const;
    const QVector<MoveDir> & getDirections() const;
signals:
    void directionsChanged(int moveSpeed, int rotationSpeed);
public slots:
    void setNewDirectionSlot(MoveDir direction);
    void unsetDirectionSlot(MoveDir direction);
    void timerSlot();

private:
    const QString BodyImagePath { ":/tankimages/resources/tankbody.png" };
    QTimer * mMotionTimer_ptr;
    qreal mMoveSpeed;
    qreal mRotationSpeed;  // determines how fast the body of vehicle could be rotated
    QString mBodyImagePath;
    QVector<MoveDir> mMoveDirectionBuffer; // vector pf rotation which enables multi key pressings
    QPointF mTrackMousePoint;  // the last position of the mouse cursor
};

#endif
