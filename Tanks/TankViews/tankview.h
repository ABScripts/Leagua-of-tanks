#ifndef TANK_VIEW
#define TANK_VIEW

#include <QObject>
#include <QGraphicsPixmapItem>

class TankViewModel;

class TankView : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    TankView(qreal x, qreal y, QGraphicsItem * parent);
    virtual  ~TankView();
    void keyPressEvent(QKeyEvent * event) override;
    void keyReleaseEvent(QKeyEvent * event) override;
private:
    TankViewModel * mTankViewModel_ptr;
signals:
    void keyPressEventOccured(QKeyEvent * event);
    void keyReleaseEventOccured(QKeyEvent * event);
};

#endif
