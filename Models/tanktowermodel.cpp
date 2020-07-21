#include "tanktowermodel.h"

TankTowerModel::TankTowerModel(QObject *parent)
    : QObject(parent)
{

}

QString TankTowerModel::towerImagePath() const
{
    return mTowerImagePath;
}

void TankTowerModel::setTowerImagePath(const QString &towerImagePath)
{
    mTowerImagePath = towerImagePath;
}

qreal TankTowerModel::rotationSpeed() const
{
    return mRotationSpeed;
}
