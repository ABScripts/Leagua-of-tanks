#include "tankview.h"

#include <QKeyEvent>
#include <qmath.h>
#include <QVector>
#include "ViewModels/tankviewmodel.h"

TankView::TankView(qreal x, qreal y, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent),
      mTankViewModel_ptr(new TankViewModel()),
      mTankTowerView_ptr(new TankTowerView(this))
{
    connect(this, &TankView::requestForImagePath, mTankViewModel_ptr, &TankViewModel::requestForImagePathSlot);
    connect(mTankViewModel_ptr, &TankViewModel::imagePathFetched, this, &TankView::acceptImagePath);
    connect(this, &TankView::keyPressEventOccured, mTankViewModel_ptr, &TankViewModel::keyPressEventOccuredSlot);
    connect(this, &TankView::keyReleaseEventOccured, mTankViewModel_ptr, &TankViewModel::keyReleaseEventOccuredSlot);
    connect(mTankViewModel_ptr, &TankViewModel::directionChanged, this, &TankView::directionChangedSlot);
    connect(this, &TankView::mouseMoveEventOccured, mTankTowerView_ptr, &TankTowerView::mouseMoveEventSlot);
    connect(this, &TankView::mouseButtonPressEventOccured, mTankTowerView_ptr, &TankTowerView::mousePressEventSlot);
    setupTankView(x, y);
}

TankView::~TankView()
{
    delete mTankViewModel_ptr;
}

void TankView::setupTankView(int x, int y)
{
    setPos(x, y);

    emit requestForImagePath(); // fetching image for our tank

    this->setScale(qreal(100 + 100) / (pixmap().size().width() + pixmap().size().height())); // scaling image according to the tank`s size ??

    setTransformOriginPoint(pixmap().size().width() / 2, pixmap().size().height() / 2);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void TankView::acceptImagePath(const QString & path)
{
    if (path == "") {
        // if this image is missing from the folder just brush it with some default colors
    } else {
        setPixmap(QPixmap(path)); // otherwise just set the fetched image
    }
}


void TankView::directionChangedSlot(int moveSpeed, int rotationSpeed, QVector<MoveDir> direction)
{
    qreal angle = rotation();

    qreal dx = moveSpeed * qSin(qDegreesToRadians(angle));
    qreal dy = moveSpeed * qCos(qDegreesToRadians(angle));

    for (auto dir: direction) {
        if (dir == MoveDir::Down) {
            setPos(x() - dx, y() + dy);
        } else if (dir == MoveDir::Up) {
            setPos(x() + dx, y() - dy);
        } else if (dir == MoveDir::Left) {
            setRotation(rotation() - rotationSpeed);
            //mTower_ptr->setRotation(this->mTower_ptr->rotation() + mRotationSpeed);  // prevents tower rotation while the tank`s body is rotating
        } else if (dir == MoveDir::Right) {
            setRotation(rotation() + rotationSpeed);
            //mTower_ptr->setRotation(this->mTower_ptr->rotation() - mRotationSpeed);
        }
    }
    // Тут ще треба буде назад в модель слати одну херню.
}

void TankView::mouseMoveEventSlot(QEvent *event)
{
    emit mouseMoveEventOccured(dynamic_cast<QMouseEvent *>(event), this);
}

void TankView::mouseButtonPressEventSlot(QEvent *event)
{
    emit mouseButtonPressEventOccured(dynamic_cast<QMouseEvent *>(event), this);
}

void TankView::keyPressEventSlot(QEvent *event)
{
    emit keyPressEventOccured(dynamic_cast<QKeyEvent *>(event)); // check first?
}

void TankView::keyReleaseEventSlot(QEvent *event)
{
    emit keyReleaseEventOccured(dynamic_cast<QKeyEvent *>(event));
}
