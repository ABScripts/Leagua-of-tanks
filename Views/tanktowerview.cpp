#include "tanktowerview.h"

#include <QMouseEvent>
#include <qmath.h>
#include <QGraphicsScene>
#include "bullet.h"
#include "MathCore/mathcore.h"
#include "Views/tankview.h"
#include "ViewModels/tanktowerviewmodel.h"

TankTowerView::TankTowerView(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent),
      mTowerViewModel_ptr(new TankTowerViewModel())
{
    connect(this, &TankTowerView::requestForImagePath, mTowerViewModel_ptr, &TankTowerViewModel::requestForImagePathSlot);
    connect(mTowerViewModel_ptr, SIGNAL(imagePathFetched(QString)), this, SLOT(acceptImagePath(QString)));
    setupTankTower(pixmap().width() / 2 + 70, -40); // change it to no hard code values
}

TankTowerView::~TankTowerView()
{
    delete mTowerViewModel_ptr;
}

void TankTowerView::acceptImagePath(QString path)
{
    if (path == "") {
        // if this image is missing from the folder just brush it with some default colors
    } else {
        setPixmap(QPixmap(path)); // otherwise just set the fetched image
    }
}

void TankTowerView::mouseMoveEventSlot(QMouseEvent *event, TankView * tank)
{
    // point where the projectile explode
    QPointF bulletStartPosition = {tank->x() + tank->pixmap().width() * tank->scale() + tank->pixmap().width() * tank->scale() / 2
                                   ,tank->y() +  tank->pixmap().height() * tank->scale() + tank->pixmap().height() * tank->scale() / 2}; // wtf
    // actually the point where the mouse currently is

    QPointF mousePosition =  event->pos();

    qreal angle = atan2(mousePosition.y() - bulletStartPosition.y() + static_cast<int>(Bullet::Size::Width) / 2,
                        mousePosition.x() - bulletStartPosition.x() + static_cast<int>(Bullet::Size::Width) / 2);

    // remembers the last position of mouse when it was moved (products a slight movements)
    // tank->setTrackMousePoint(QPoint(event->x(), event->y()));

    setRotation(qRadiansToDegrees(angle) + 90 - tank->rotation());
    // + 90 becouse this func means:
    //      90
    //   180 + 0
    //      270
    // At the same time in our coordinate system 90 is replaced with 0 and all left numbers go all the way down.
}

void TankTowerView::mousePressEventSlot(QMouseEvent *event, TankView * tank)
{
    // determines the top left point in which the bullet should spaw
    QPoint spawnPoint = MathCore::pointOnCircle(tank,
                                               100,
                                                rotation()-90 + tank->rotation());

    Bullet * bull = new Bullet(0, 0, rotation() + tank->rotation());
    bull->setPos(spawnPoint.x(), spawnPoint.y());
    this->scene()->addItem(bull);
}

void TankTowerView::setupTankTower(qreal x, qreal y)
{

    emit requestForImagePath(); // sending signal to get the image path from the model

    setPos(x, y);

    setTransformOriginPoint(pixmap().width() * scale() / 2, pixmap().height() * scale() - 80); // 80 - wtf
}
