#include "tankviewmodel.h"

#include <QKeyEvent>
#include <QFileInfo>
#include "../TankModels/tankmodel.h"

TankViewModel::TankViewModel()
{
    mTankModel_ptr = new TankModel();

    connect(this, SIGNAL(newDirectionWasSetted(MoveDir)), mTankModel_ptr, SLOT(setNewDirectionSlot(MoveDir)));
    connect(this, SIGNAL(DirectionWasUnsetted(MoveDir)), mTankModel_ptr, SLOT(unsetDirectionSlot(MoveDir)));
    connect(mTankModel_ptr, SIGNAL(directionsChanged(int, int)), this, SLOT(directionChangedSlot(int, int)));
}

TankViewModel::~TankViewModel()
{
    delete mTankModel_ptr;
}

void TankViewModel::keyPressEventOccuredSlot(QKeyEvent * event)
{
    MoveDir direction;
    distinguishDirection(event->key(), direction);

    if (direction != MoveDir::None) {
        emit newDirectionWasSetted(direction);
    }

}

void TankViewModel::keyReleaseEventOccuredSlot(QKeyEvent * event)
{
    if (event->isAutoRepeat()) {
        return;
    }

    MoveDir direction;
    distinguishDirection(event->key(), direction);

    if (direction != MoveDir::None) {
        emit DirectionWasUnsetted(direction);
    }

}

void TankViewModel::requestForImagePathSlot()
{
    QString imageFilePath = mTankModel_ptr->bodyImagePath();
    QFileInfo check(imageFilePath);
    // if file does not exist or it is not  file, or it is not a png image
    if (!(check.exists() && check.isFile() && check.completeSuffix() == "png")) {
        imageFilePath = "";
    }

    emit imagePathFetched(imageFilePath); // send this path to the view to set the image there...
}

void TankViewModel::directionChangedSlot(int moveSpeed, int rotationSpeed)
{
    QVector<MoveDir> directions = mTankModel_ptr->getDirections();

    emit directionChanged(moveSpeed, rotationSpeed, directions);
}

void TankViewModel::distinguishDirection(int key, MoveDir & resDir)
{
    switch(key) {
    case Qt::Key_Left:
        resDir = MoveDir::Left;
        break;
    case Qt::Key_Right:
        resDir = MoveDir::Right;
        break;
    case Qt::Key_Up:
        resDir = MoveDir::Up;
        break;
    case Qt::Key_Down:
        resDir = MoveDir::Down;
        break;
    default:
        resDir = MoveDir::None; // if it is not the key we track than do nothing
    }
}
