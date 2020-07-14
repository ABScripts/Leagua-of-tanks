#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <qmath.h>

#include "standarttank.h"

class GameView: public QGraphicsView
{
private:
    StandartTank * tank;
public:
    GameView();
    GameView(QGraphicsScene * scene);

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};



#endif // GAMEVIEW_H
