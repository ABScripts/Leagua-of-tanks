#include "gameview.h"

#include "graphicscenemodel.h"

class QMouseEvent;

GameView::GameView(GameSceneViewModel *scene, QWidget * parent)
    : QGraphicsView(scene, parent), mviewModel_ptr(scene) {
    setFixedSize(scene->width(), scene->height());

    setMouseTracking(true);

//    tank = new Tank(scene->width() / 2 - Tank::Size::Width / 2,
//                            scene->height() / 2 - Tank::Size::Height / 2);
//    tank->setFlag(QGraphicsItem::ItemIsFocusable);
//    tank->setFocus();

//   StandartTank * enemyTank = new StandartTank(100, 100, StandartTank::TankType::Enemy);
//    this->scene()->addItem(enemyTank);
//    this->scene()->addItem(tank);
}

void GameView::mousePressEvent(QMouseEvent *event)
{
//    // getting the tank`s tower
//    TankTower * tower = tank->getTower();

//    // determines the top left point in which the bullet should spawn
//    QPoint spawnPoint = MathCore::pointOnCircle(tank,
//                                                fabs(tank->rect().center().y() - tower->y()) + static_cast<int>(Bullet::Size::Height),
//                                                tower->rotation()-90 + tank->rotation());

//    Bullet * bull = new Bullet(0, 0, tower->rotation() + tank->rotation());
//    bull->setPos(spawnPoint.x(), spawnPoint.y());
//    this->scene()->addItem(bull);
    emit mousePressEventOccured(event);
}

void GameView::mouseMoveEvent(QMouseEvent *event)
{
//    TankTower * tower = tank->getTower();

//    // point where the projectile explode
//    QPointF bulletStartPosition = {tank->x() + tank->rect().width() / 2, tank->y() + tank->rect().height()};
//    // actually the point where the mouse currently is
//    QPointF mousePosition = event->pos();

//    qreal angle = atan2(mousePosition.y() - bulletStartPosition.y() + static_cast<int>(Bullet::Size::Width) / 2,
//                         mousePosition.x() - bulletStartPosition.x() + static_cast<int>(Bullet::Size::Width) / 2);

//    // remembers the last position of mouse when it was moved (products a slight movements)
//    tank->setTrackMousePoint(QPoint(event->x(), event->y()));

//    tower->setRotation(qRadiansToDegrees(angle) + 90 - tank->rotation());
//    // + 90 becouse this func means:
//    //      90
//    //   180 + 0
//    //      270
//    // At the same time in our coordinate system 90 is replaced with 0 and all left numbers go all the way down.
    emit mouseMoveEventOccured(event);
}
