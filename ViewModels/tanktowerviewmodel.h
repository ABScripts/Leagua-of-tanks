#ifndef TANKTOWERVIEWMODEL_H
#define TANKTOWERVIEWMODEL_H

#include <QObject>

QT_BEGIN_NAMESPACE
class TankTowerModel;
QT_END_NAMESPACE

class TankTowerViewModel : public QObject
{
    Q_OBJECT
public:
    TankTowerViewModel();
    ~TankTowerViewModel();
signals:
    void imagePathFetched(QString path);
public slots:
    void requestForImagePathSlot();
private:
    TankTowerModel * mTankTowerModel_ptr;
};

#endif // TANKTOWERVIEWMODEL_H
