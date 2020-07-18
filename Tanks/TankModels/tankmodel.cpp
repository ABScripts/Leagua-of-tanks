#include "tankmodel.h"

#include <QTimer>

TankModel::TankModel()
    : mMoveSpeed(MoveSpeed),
      mRotationSpeed(RotationSpeed),
      mBodyImagePath(BodyImagePath)
{
    mMotionTimer_ptr = new QTimer(this);

    connect(mMotionTimer_ptr, &QTimer::timeout, this, &TankModel::timerSlot);
}

QString TankModel::bodyImagePath() const
{
    return mBodyImagePath;
}

const QVector<MoveDir> & TankModel::getDirections() const
{
    return mMoveDirectionBuffer;
}

void TankModel::setNewDirectionSlot(MoveDir direction)
{
    for (auto it = mMoveDirectionBuffer.begin(); it != mMoveDirectionBuffer.end(); ++it) {
        // if we have this key already we will do nothing
        if (*it == direction) {
            return;
        }
    }

    mMoveDirectionBuffer.push_back(direction);

    if (!mMotionTimer_ptr->isActive()) {
        mMotionTimer_ptr->start(10);
    }

    emit directionsChanged(mMoveSpeed, mRotationSpeed);
}

void TankModel::unsetDirectionSlot(MoveDir direction)
{
    for (auto it = mMoveDirectionBuffer.begin(); it != mMoveDirectionBuffer.end(); ) {
        // if was released the key that was pressed we will remove it
        if (*it == direction) {
            it = mMoveDirectionBuffer.erase(it);

            if (mMoveDirectionBuffer.size() == 0) {
                mMotionTimer_ptr->stop();
            }

            emit directionsChanged(mMoveSpeed, mRotationSpeed);

            return;
        } else {
            ++it;
        }
    }
}

void TankModel::timerSlot()
{
    emit directionsChanged(mMoveSpeed, mRotationSpeed);
}
