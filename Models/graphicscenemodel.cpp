#include "graphicscenemodel.h"
#include <QGraphicsRectItem>

#include <QEvent>
#include "Views/tankview.h"

GameSceneViewModel::GameSceneViewModel(int x, int y, int width, int height, QObject * parent)
    : QGraphicsScene(x, y, width, height, parent)
{
    setupScene();
}

void GameSceneViewModel::setupScene()
{
    addItem(new TankView(0, 0));
//    QGraphicsRectItem * rectTest = new QGraphicsRectItem(100, 100, 100, 100); // this is just for tests
//    QGraphicsScene::addItem(rectTest);    // do some work related with setting a background or erading data from the model
}

void GameSceneViewModel::addItem(TankView *tank)
{
    connect(this, &GameSceneViewModel::mouseMoveEventOccured, tank, &TankView::mouseMoveEventSlot);
    connect(this, &GameSceneViewModel::mousePressEventOccured, tank, &TankView::mouseButtonPressEventSlot);
    connect(this, &GameSceneViewModel::keyPressEventOccured, tank, &TankView::keyPressEventSlot); // should try to simplify to signal to signal
    connect(this, &GameSceneViewModel::keyReleaseEventOccured, tank, &TankView::keyReleaseEventSlot);
    selfTanks.push_back(tank);
    // should connect some tank`s signals and slots
    QGraphicsScene::addItem(tank);
}

void GameSceneViewModel::eventHandledSlot(QEvent *event)
{
    switch(event->type()) {
    case QEvent::MouseMove:
        emit mouseMoveEventOccured(event);
        break;
    case QEvent::MouseButtonPress:
        emit mousePressEventOccured(event);
        break;
    case QEvent::KeyPress:
        emit keyPressEventOccured(event); // cast here to QKeyEvent
        break;
    case QEvent::KeyRelease:
        emit keyReleaseEventOccured(event);
        break;
    default:
        return;
    }
}

// Рівень моделей - комунікують між собою, не знають про вю та вю моделі.
// Вю модель реагує на зміни на рівні моделей. Так само й повинна реагувати на зміни на екрані.
//
