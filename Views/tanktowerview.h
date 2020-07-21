#ifndef TANKTOWERVIEW_H
#define TANKTOWERVIEW_H

#include <QObject>
#include <QGraphicsPixmapItem>

QT_BEGIN_NAMESPACE
class TankView;
class QMouseEvent;
class TankTowerViewModel;
QT_END_NAMESPACE

class TankTowerView : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit TankTowerView(QGraphicsItem * parent);
    ~TankTowerView();
signals:
    void requestForImagePath();
public slots:
    void acceptImagePath(const QString & path);
    void mouseMoveEventSlot(QMouseEvent *event, TankView * tank);
    void mousePressEventSlot(QMouseEvent *event, TankView * tank);
private:
    void setupTankTower(qreal x, qreal y);
private:
    TankTowerViewModel * mTowerViewModel_ptr;
};

#endif // TANKTOWERVIEW_H
