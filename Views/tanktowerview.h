#ifndef TANKTOWERVIEW_H
#define TANKTOWERVIEW_H

#include <QObject>
#include <QGraphicsPixmapItem>

class TankView;
class QMouseEvent;
class TankTowerViewModel;

class TankTowerView : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit TankTowerView(QGraphicsItem * parent);
    ~TankTowerView();
signals:
    void requestForImagePath();
public slots:
    void acceptImagePath(QString path);
    void mouseMoveEventSlot(QMouseEvent *event, TankView * tank);
    void mousePressEventSlot(QMouseEvent *event, TankView * tank);
private:
    void setupTankTower(qreal x, qreal y);
private:
    TankTowerViewModel * mTowerViewModel_ptr;
};

#endif // TANKTOWERVIEW_H
