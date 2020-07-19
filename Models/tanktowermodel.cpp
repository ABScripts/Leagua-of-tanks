#include "tanktowermodel.h"

TankTowerModel::TankTowerModel()
{

}

QString TankTowerModel::towerImagePath() const
{
    return mTowerImagePath;
}

qreal TankTowerModel::rotationSpeed() const
{
    return mRotationSpeed;
}
