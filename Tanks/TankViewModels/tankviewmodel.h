#ifndef TANK_VIEW_MODEL
#define TANK_VIEW_MODEL

#include <QObject>
#include "movedirenum.h"

class TankModel;
class QKeyEvent;
class QGraphicsItem;

class TankViewModel: public QObject {
    Q_OBJECT

public:
    TankViewModel();
    ~TankViewModel();
signals:
    void newDirectionWasSetted(MoveDir direction);
    void DirectionWasUnsetted(MoveDir direction);
    void imagePathFetched(QString path);
    void directionChanged(int moveSpeed, int rotationSpeed, QVector<MoveDir> dirs);
public slots:
    virtual void keyPressEventOccuredSlot(QKeyEvent * event);
    virtual void keyReleaseEventOccuredSlot(QKeyEvent * event);
    void requestForImagePathSlot();
    void directionChangedSlot(int moveSpeed, int rotationSpeed);
private:
    TankModel * mTankModel_ptr;

    void distinguishDirection(int key, MoveDir & resDir);
};

#endif

