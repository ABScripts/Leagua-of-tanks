#ifndef TANK_VIEW_MODEL
#define TANK_VIEW_MODEL

#include <QPointF>
#include <QObject>
#include <QVector>
#include "movedirenum.h"

class QTimer;
class TankModel;
class QKeyEvent;
class QGraphicsItem;

class TankViewModel: public QObject {
    Q_OBJECT

public:
    TankViewModel();
    ~TankViewModel();
signals:
    void imagePathFetched(QString path);
    void directionChanged(int moveSpeed, int rotationSpeed, QVector<Movement::MoveDir> dirs);
public slots:
    virtual void keyPressEventOccuredSlot(QKeyEvent * event);
    virtual void keyReleaseEventOccuredSlot(QKeyEvent * event);
    void requestForImagePathSlot();
    void emitTimerSignal();
private:
    TankModel * mTankModel_ptr;
    QTimer * mMotionTimer_ptr;
    QVector<Movement::MoveDir> MoveDirectionBuffer; // vector pf rotation which enables multi key pressings
    Movement::MoveDir distinguishDirection(int key);
    QPointF mTrackMousePoint;  // the last position of the mouse cursor
};

#endif

