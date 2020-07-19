#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>

QT_BEGIN_NAMESPACE
class GameSceneViewModel;
QT_END_NAMESPACE

// actually the view
class GameView: public QGraphicsView
{
    Q_OBJECT
public:
    GameView() = default;
    explicit GameView(GameSceneViewModel * scene, QWidget * parent);
protected:
    bool event(QEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
private:
   GameSceneViewModel * mViewModel_ptr;
private:
    void setupView(GameSceneViewModel *scene);
signals:
    void mousePressEventOccured(QMouseEvent * event);
    void mouseMoveEventOccured(QMouseEvent * event);
    void eventHandled(QEvent * event);
};



#endif // GAMEVIEW_H
