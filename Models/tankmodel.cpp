#include "tankmodel.h"

TankModel::TankModel(QObject *parent)
    : QObject(parent),
      mMoveSpeed(MoveSpeed::MoveSpeed),
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

void TankModel::setBodyImagePath(const QString &value)
{
    BodyImagePath = value;
}

qreal TankModel::getRotationSpeed() const
{
    return mRotationSpeed;
}

qreal TankModel::getMoveSpeed() const
{
    return mMoveSpeed;
}
