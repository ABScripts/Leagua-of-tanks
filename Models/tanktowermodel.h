#ifndef TANKTOWERMODEL_H
#define TANKTOWERMODEL_H

#include <QObject>

class TankTowerModel : public QObject
{
    Q_OBJECT
public:

    enum Size {
        Width = 50,
        Height = 140
    };

    TankTowerModel();
    qreal rotationSpeed() const;
    QString towerImagePath() const;
private:
    qreal mRotationSpeed;
    const QString mTowerImagePath {":/tankimages/resources/tanktower.png"};
};

#endif // TANKTOWERMODEL_H

