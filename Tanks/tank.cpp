#include "tank.h"

#include <QKeyEvent>
#include <qmath.h>
#include <vector>

Tank::Tank(qreal x, qreal y, QGraphicsItem * parent)
    : QGraphicsPixmapItem(QPixmap(":/tankimages/resources/tankbody.png"), parent) {
    // setting scale coefficient
    this->setScale(qreal(Tank::Width + Tank::Height) / (pixmap().size().width() + pixmap().size().height()));

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    // setting speeds:
    mMoveSpeed = Speed::MoveSpeed;
    mRotationSpeed = Speed::RotationSpeed;

    // rev this
    this->setPos(x, y);

//    mTower_ptr = new TankTower(0, 0, this->rect().width()-50, this->rect().height() + 40, this);
    mTower_ptr = new TankTower(0, 0, this);

    mTower_ptr->setPos(Tank::Width / 2 + TankTower::Size::Width / 2, -40); // -40 should be removed later

    setTransformOriginPoint(pixmap().size().width() / 2, pixmap().size().height() / 2);

//    // origin point is setted within this item`s coordinate system (not a parent!);
    mTower_ptr->setTransformOriginPoint(TankTower::Size::Width * scale() / 2,
                                        TankTower::Size::Height* scale() / 2 + (TankTower::Size::Height* scale() - Tank::Height* scale()) / 2);


    // hold it here just to distinguish the front side of the tank - should be deleted when the graphics are added
    //QGraphicsRectItem * front = new QGraphicsRectItem(0, 0, this->rect().width(), this->rect().height() * 0.1, this);

    connect(&this->mMotionTimer, &QTimer::timeout, this, &Tank::move);
}

void Tank::keyPressEvent(QKeyEvent * event)
{
//    MoveDir pressed;
//    switch(event->key()) {
//    case Qt::Key_Left:
//        pressed = MoveDir::Left;
//        break;
//    case Qt::Key_Right:
//        pressed = MoveDir::Right;
//        break;
//    case Qt::Key_Up:
//        pressed = MoveDir::Up;
//        break;
//    case Qt::Key_Down:
//        pressed = MoveDir::Down;
//        break;
//    default:
//        return; // if it is not the key we track than do nothing
//    }

    for (auto it = mMoveDirectionBuffer.begin(); it != mMoveDirectionBuffer.end(); ++it) {
        // if we have this key already we will do nothing
        if (*it == pressed) {
            return;
        }
    }

    mMoveDirectionBuffer.push_back(pressed);
    mMotionTimer.start(10);
}

void Tank::keyReleaseEvent(QKeyEvent * event)
{
    if (event->isAutoRepeat()) {
        return;
    }

    MoveDir released;
    switch(event->key()) {
    case Qt::Key_Left:
        released = MoveDir::Left;
        break;
    case Qt::Key_Right:
        released = MoveDir::Right;
        break;
    case Qt::Key_Up:
        released = MoveDir::Up;
        break;
    case Qt::Key_Down:
        released = MoveDir::Down;
        break;
    default:
        return;
    }


    for (auto it = mMoveDirectionBuffer.begin(); it != mMoveDirectionBuffer.end(); ) {
        // if was released the key that was pressed we will remove it
        if (*it == released) {
            it = mMoveDirectionBuffer.erase(it);
        } else {
            ++it;
        }
    }
}

void Tank::applyKeyPress(MoveDir dir, qreal dx, qreal dy)
{
    if (dir == MoveDir::Down) {
        setPos(x() - dx, y() + dy);
    } else if (dir == MoveDir::Up) {
        setPos(x() + dx, y() - dy);
    } else if (dir == MoveDir::Left) {
        setRotation(rotation() - mRotationSpeed);
        //mTower_ptr->setRotation(this->mTower_ptr->rotation() + mRotationSpeed);  // prevents tower rotation while the tank`s body is rotating
    } else if (dir == MoveDir::Right) {
        setRotation(rotation() + mRotationSpeed);
        //mTower_ptr->setRotation(this->mTower_ptr->rotation() - mRotationSpeed);
    }
}

void Tank::move()
{
    qreal angle = rotation();

    qreal dx = mMoveSpeed * qSin(qDegreesToRadians(angle));
    qreal dy = mMoveSpeed * qCos(qDegreesToRadians(angle));

    // going through all of the keys and applying actions according to the dir-s
    std::for_each(mMoveDirectionBuffer.begin(), mMoveDirectionBuffer.end(), [&](MoveDir & dir){
        applyKeyPress(dir, dx, dy);
    });
    // point where the projectile explode
    QPointF projectileStartPosition = {x() + Tank::Width / 2, y() + Tank::Height / 2};
    // actually the point where the mouse currently is
    QPointF mousePosition = mTrackMousePoint;

    angle = atan2(mousePosition.y() - projectileStartPosition.y(),
                  mousePosition.x() - projectileStartPosition.x());

    //mTower_ptr->setRotation(qRadiansToDegrees(angle) + 90 - rotation());
}

void Tank::setTrackMousePoint(const QPointF &value)
{
    mTrackMousePoint = value;
}

//QRectF Tank::boundingRect() const
//{
//    return QRectF(0,0,276, 352);
//}

Tank::~Tank()
{
    // Nevertheless tower var is created using "new", thanks to the parent-child reletions it`s deleted auto-lly
}

TankTower *Tank::getTower() const
{
    return mTower_ptr;
}
