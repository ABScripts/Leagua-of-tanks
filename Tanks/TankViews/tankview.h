#ifndef TANK_VIEW
#define TANK_VIEW

#include <QObject>
#include <QGraphicsPixmapItem>
#include "movedirenum.h"

class TankViewModel;

class TankView : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    TankView(qreal x, qreal y, QGraphicsItem * parent = nullptr);
    virtual  ~TankView();
    void keyPressEvent(QKeyEvent * event) override;
    void keyReleaseEvent(QKeyEvent * event) override;
private:
    TankViewModel * mTankViewModel_ptr;
private:
    void setupTankView(int x, int y);
signals:
    void keyPressEventOccured(QKeyEvent * event);
    void keyReleaseEventOccured(QKeyEvent * event);
    void requestForImagePath();
public slots:
    void acceptImagePath(QString path);
    void directionChangedSlot(int moveSpeed, int rotationSpeed, QVector<MoveDir> dir);
};

#endif
