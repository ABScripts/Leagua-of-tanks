#ifndef TANK_VIEW_MODEL
#define TANK_VIEW_MODEL

#include <QPointF>
#include <QObject>
#include <QVector>
#include "movedirenum.h"

QT_BEGIN_NAMESPACE
class QTimer;
class TankModel;
class QKeyEvent;
class QGraphicsItem;
QT_END_NAMESPACE

class TankViewModel: public QObject {
    Q_OBJECT
public:
    TankViewModel();
    ~TankViewModel();
signals:
    void imagePathFetched(const QString & path);
    void directionChanged(int moveSpeed, int rotationSpeed, QVector<MoveDir> dirs);
public slots:
    virtual void keyPressEventOccuredSlot(QKeyEvent * event);
    virtual void keyReleaseEventOccuredSlot(QKeyEvent * event);
    void requestForImagePathSlot();
    void emitTimerSignal();
private:
    TankModel * mTankModel_ptr;
    QTimer * mMotionTimer_ptr;
    QVector<MoveDir> MoveDirectionBuffer; // vector pf rotation which enables multi key pressings
    MoveDir distinguishDirection(int key);
    QPointF mTrackMousePoint;  // the last position of the mouse cursor
};

#endif

