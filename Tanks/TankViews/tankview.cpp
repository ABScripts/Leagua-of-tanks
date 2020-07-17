#include "tankview.h"

#include "../TankViewModels/tankviewmodel.h"

TankView::TankView(qreal x, qreal y, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
    mTankViewModel_ptr = new TankViewModel();


}

TankView::~TankView()
{
    delete mTankViewModel_ptr;
}

void TankView::keyPressEvent(QKeyEvent *event)
{
    emit keyPressEventOccured(event);
}

void TankView::keyReleaseEvent(QKeyEvent *event)
{
    emit keyReleaseEventOccured(event);
}
