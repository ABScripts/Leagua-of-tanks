#include "tankmodel.h"

#include <QTimer>

TankModel::TankModel()
    : mMoveSpeed(MoveSpeed::MoveSpeed),
      mRotationSpeed(MoveSpeed::RotationSpeed),
      mBodyImagePath(BodyImagePath)
{

}

QString TankModel::bodyImagePath() const
{
    return mBodyImagePath;
}

void TankModel::timerSlot()
{
    emit directionsChanged(mMoveSpeed, mRotationSpeed);
}

qreal TankModel::getRotationSpeed() const
{
    return mRotationSpeed;
}

qreal TankModel::getMoveSpeed() const
{
    return mMoveSpeed;
}
