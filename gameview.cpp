#include "gameview.h"

#include <QEvent>
#include <QInputEvent>
#include "graphicscenemodel.h"

GameView::GameView(GameSceneViewModel *scene, QWidget * parent)
    : QGraphicsView(scene, parent),
      mViewModel_ptr(scene)
{
    setupView(scene);

    connect(this, SIGNAL(eventHandled(QEvent*)), mViewModel_ptr, SLOT(eventHandledSlot(QEvent*)));
}

void GameView::mouseMoveEvent(QMouseEvent *event)
{
    emit eventHandled(event); // think of it and consider move it somehow to the event() method
}

bool GameView::event(QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress || // make this work better, consider change to signal signal model
            event->type() == QEvent::KeyPress ||
            event->type() == QEvent::KeyRelease )
    {
        emit eventHandled(event);
        return true;
    }
    return QGraphicsView::event(event);
}

void GameView::setupView(GameSceneViewModel *scene)
{
    setMouseTracking(true);
    setFixedSize(scene->width(), scene->height());
}
