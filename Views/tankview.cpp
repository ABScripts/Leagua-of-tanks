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
    connect(mTankViewModel_ptr, SIGNAL(imagePathFetched(QString)), this, SLOT(acceptImagePath(QString)));     // used this syntax of signals and slots because this one is with parameters
    connect(this, SIGNAL(keyPressEventOccured(QKeyEvent*)), mTankViewModel_ptr, SLOT(keyPressEventOccuredSlot(QKeyEvent*)));
    connect(this, SIGNAL(keyReleaseEventOccured(QKeyEvent*)), mTankViewModel_ptr, SLOT(keyReleaseEventOccuredSlot(QKeyEvent*)));
    connect(mTankViewModel_ptr, SIGNAL(directionChanged(int, int, QVector<Movement::MoveDir>)), this, SLOT(directionChangedSlot(int, int, QVector<Movement::MoveDir>)));
    connect(this, SIGNAL(mouseMoveEventOccured(QMouseEvent *, TankView *)), mTankTowerView_ptr, SLOT(mouseMoveEventSlot(QMouseEvent *, TankView *)));
    connect(this, SIGNAL(mouseButtonPressEventOccured(QMouseEvent *, TankView *)), mTankTowerView_ptr, SLOT(mousePressEventSlot(QMouseEvent *, TankView *)));
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

void TankView::acceptImagePath(QString path)
{
    if (path == "") {
        // if this image is missing from the folder just brush it with some default colors
    } else {
        setPixmap(QPixmap(path)); // otherwise just set the fetched image
    }
}


void TankView::directionChangedSlot(int moveSpeed, int rotationSpeed, QVector<Movement::MoveDir> direction)
{
    qreal angle = rotation();

    qreal dx = moveSpeed * qSin(qDegreesToRadians(angle));
    qreal dy = moveSpeed * qCos(qDegreesToRadians(angle));

    for (auto dir: direction) {
        if (dir == Movement::MoveDir::Down) {
            setPos(x() - dx, y() + dy);
        } else if (dir == Movement::MoveDir::Up) {
            setPos(x() + dx, y() - dy);
        } else if (dir == Movement::MoveDir::Left) {
            setRotation(rotation() - rotationSpeed);
            //mTower_ptr->setRotation(this->mTower_ptr->rotation() + mRotationSpeed);  // prevents tower rotation while the tank`s body is rotating
        } else if (dir == Movement::MoveDir::Right) {
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
