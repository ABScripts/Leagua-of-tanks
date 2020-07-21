#include "tankviewmodel.h"

#include <QTimer>
#include <QKeyEvent>
#include <QFileInfo>
#include "Models/tankmodel.h"

TankViewModel::TankViewModel()
    : QObject(), mTankModel_ptr(new TankModel()),
      mMotionTimer_ptr(new QTimer(this))
{
    connect(mMotionTimer_ptr, &QTimer::timeout, this, &TankViewModel::emitTimerSignal);
}

TankViewModel::~TankViewModel()
{
    delete mTankModel_ptr;
}

void TankViewModel::keyPressEventOccuredSlot(QKeyEvent * event)
{
    MoveDir dir = distinguishDirection(event->key()); // get enum-value specified direction

    int moveSpeed = mTankModel_ptr->getMoveSpeed();
    int rotationSpeed = mTankModel_ptr->getRotationSpeed();

    if (dir != MoveDir::None) { // if it is actually a key
        for (QVector<MoveDir>::Iterator it = MoveDirectionBuffer.begin(); it != MoveDirectionBuffer.end(); ++it) {
            if (*it == dir) {
                return;
            }
        }

        MoveDirectionBuffer.push_back(dir);
        if (!mMotionTimer_ptr->isActive()) {
            mMotionTimer_ptr->start(10);
        }

        emit directionChanged(moveSpeed, rotationSpeed, MoveDirectionBuffer);
    }
}

void TankViewModel::keyReleaseEventOccuredSlot(QKeyEvent * event)
{
    if (event->isAutoRepeat()) {
        return;
    }

    int moveSpeed = mTankModel_ptr->getMoveSpeed();
    int rotationSpeed = mTankModel_ptr->getRotationSpeed();

    MoveDir dir = distinguishDirection(event->key());

    if (dir != MoveDir::None) {
        for (QVector<MoveDir>::Iterator it = MoveDirectionBuffer.begin(); it != MoveDirectionBuffer.end(); ++it) {
            if (*it == dir) {
                it = MoveDirectionBuffer.erase(it);
                break;
            }
        }

        if (MoveDirectionBuffer.isEmpty()) {
            mMotionTimer_ptr->stop(); // if it is empty just stop moving
        } else {
            emit directionChanged(moveSpeed, rotationSpeed, MoveDirectionBuffer); // if it isnt then notify view about changes
        }
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

void TankViewModel::emitTimerSignal()
{
    int moveSpeed = mTankModel_ptr->getMoveSpeed();
    int rotationSpeed = mTankModel_ptr->getRotationSpeed();

    emit directionChanged(moveSpeed, rotationSpeed, MoveDirectionBuffer);
}

MoveDir TankViewModel::distinguishDirection(int key)
{
    MoveDir dir;
    switch(key) {
    case Qt::Key_Left:
        dir = MoveDir::Left;
        break;
    case Qt::Key_Right:
        dir = MoveDir::Right;
        break;
    case Qt::Key_Up:
        dir = MoveDir::Up;
        break;
    case Qt::Key_Down:
        dir = MoveDir::Down;
        break;
    default:
        dir = MoveDir::None; // if it is not the key we track than do nothing
    }

    return dir;
}
