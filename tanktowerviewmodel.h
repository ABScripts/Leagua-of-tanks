#ifndef TANKTOWERVIEWMODEL_H
#define TANKTOWERVIEWMODEL_H

#include <QObject>

class TankTowerModel;

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
