#ifndef GRAPHICSCENEMODEL_H

#define GRAPHICSCENEMODEL_H

#include <QGraphicsScene>
#include <QSet>

class Tank;
class EnemyTank;
class TeammateTank;

// view`s view model
class GameSceneViewModel: public QGraphicsScene
{
    Q_OBJECT
public:
    GameSceneViewModel(int x, int y, int width, int height, QObject * parent);

    void setupScene();

    void addItem(Tank * tank);

private:
    QSet<EnemyTank *> enemyTanks;
    QSet<TeammateTank *> teammateTanks;
    QSet<Tank *> selfTanks; //actually the tanks you play with. Maybe the multi tanks` control system would be implemented,
                            // or the system, when you could switch bettween the tanks in real time
};

#endif // GRAPHICSCENEMODEL_H
