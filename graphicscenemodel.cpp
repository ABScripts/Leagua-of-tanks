#include "graphicscenemodel.h"
#include <QGraphicsRectItem>

#include "Tanks/tank.h"
#include "Tanks/enemytank.h"
#include "Tanks/teammatetank.h"

GameSceneViewModel::GameSceneViewModel(int x, int y, int width, int height, QObject * parent)
    : QGraphicsScene(x, y, width, height, parent)
{
    setupScene();
}

void GameSceneViewModel::setupScene()
{
    addItem(new Tank(0, 0));
    QGraphicsRectItem * rectTest = new QGraphicsRectItem(100,100,100, 100);
    QGraphicsScene::addItem(rectTest);    // do some work related with setting a background or erading data from the model
}

void GameSceneViewModel::addItem(Tank *tank)
{
    selfTanks.insert(tank);
    // should connect some signals and slots
    QGraphicsScene::addItem(tank);
}

// Рівень моделей - комунікують між собою, не знають про вю та вю моделі.
// Вю модель реагує на зміни на рівні моделей. Так само й повинна реагувати на зміни на екрані.
//
