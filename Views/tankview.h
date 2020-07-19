#ifndef TANK_VIEW
#define TANK_VIEW

#include <QObject>
#include <QGraphicsPixmapItem>
#include "tanktowerview.h"
#include "movedirenum.h"

class TankViewModel;

class TankView : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    explicit TankView(qreal x, qreal y, QGraphicsItem * parent = nullptr);
    ~TankView();
private:
    TankViewModel * mTankViewModel_ptr;
    TankTowerView * mTankTowerView_ptr;

private:
    void setupTankView(int x, int y);
signals:
    void keyPressEventOccured(QKeyEvent * event);
    void keyReleaseEventOccured(QKeyEvent * event);
    void mouseMoveEventOccured(QMouseEvent *event, TankView * tank); // shitty, should be changed (pointer to tank)
    void mouseButtonPressEventOccured(QMouseEvent *event, TankView * tank);// shitty, should be changed (pointer to tank)
    void requestForImagePath();
public slots:
    void acceptImagePath(QString path);
    void directionChangedSlot(int moveSpeed, int rotationSpeed, QVector<Movement::MoveDir> dir);
    void mouseMoveEventSlot(QEvent *event);
    void mouseButtonPressEventSlot(QEvent *event);
    void keyPressEventSlot(QEvent *event);
    void keyReleaseEventSlot(QEvent *event);
};

#endif
