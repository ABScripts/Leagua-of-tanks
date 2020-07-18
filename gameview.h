#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>

class GameSceneViewModel;

// actually the view
class GameView: public QGraphicsView
{
    Q_OBJECT
public:
    GameView() = default;
    GameView(GameSceneViewModel * scene, QWidget * parent);

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
private:
    GameSceneViewModel * mviewModel_ptr;
signals:
    void mousePressEventOccured(QMouseEvent * event);
    void mouseMoveEventOccured(QMouseEvent * event);
    //void onUpKeyPressed(QKey * key);
};



#endif // GAMEVIEW_H
