#include "tanktowerviewmodel.h"

#include <QFileInfo>
#include "tanktowermodel.h"

TankTowerViewModel::TankTowerViewModel()
   : mTankTowerModel_ptr(new TankTowerModel())
{

}

TankTowerViewModel::~TankTowerViewModel()
{
    delete mTankTowerModel_ptr;
}

void TankTowerViewModel::requestForImagePathSlot()
{
    QString imageFilePath = mTankTowerModel_ptr->towerImagePath();
    QFileInfo check(imageFilePath);
    // if file does not exist or it is not  file, or it is not a png image
    if (!(check.exists() && check.isFile() && check.completeSuffix() == "png")) {
        imageFilePath = "";
    }

    emit imagePathFetched(imageFilePath); // send this path to the view to set the image there...
}
