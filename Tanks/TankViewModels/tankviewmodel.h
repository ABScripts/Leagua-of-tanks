#ifndef TANK_VIEW_MODEL
#define TANK_VIEW_MODEL

#include <QObject>

class TankModel;
class QKeyEvent;

class TankViewModel: public QObject {
    Q_OBJECT

public:

    enum class MoveDir {
        Left = 0,
        Right,
        Up,
        Down,
        None
    };

    TankViewModel();
    ~TankViewModel();
public slots:
    //virtual void move();
    virtual void keyPressEventOccuredSlot(QKeyEvent * event);
    virtual void keyReleaseEventOccuredSlot(QKeyEvent * event);
signals:
    void newDirectionWasSetted(MoveDir direction);
    void DirectionWasUnsetted(MoveDir direction);
private:
    TankModel * mTankModel_ptr;

    void distinguishDirection(int key, MoveDir & resDir);
};

#endif
