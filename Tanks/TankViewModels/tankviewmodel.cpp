#include "tankviewmodel.h"

#include <QKeyEvent>
#include "../TankModels/tankmodel.h"

TankViewModel::TankViewModel()
{
    mTankModel_ptr = new TankModel();
}

TankViewModel::~TankViewModel()
{
    delete mTankModel_ptr;
}

void TankViewModel::keyPressEventOccuredSlot(QKeyEvent * event)
{
    MoveDir direction;
    distinguishDirection(event->key(), direction);

    if (direction == MoveDir::None) {
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
