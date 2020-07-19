#ifndef GRAPHICSCENEMODEL_H
#define GRAPHICSCENEMODEL_H

#include <QGraphicsScene>
#include <QVector>
#include <QEvent>
class TankView;

// view`s view model
class GameSceneViewModel: public QGraphicsScene
{
    Q_OBJECT
public:
    GameSceneViewModel(int x, int y, int width, int height, QObject * parent);

    void setupScene();

    void addItem(TankView * tank);

signals:
    void mouseMoveEventOccured(QEvent *event);
    void mousePressEventOccured(QEvent *event);
    void keyPressEventOccured(QEvent *event);
    void keyReleaseEventOccured(QEvent *event);
public slots:
    void eventHandledSlot(QEvent *event);

private:
    QVector<TankView *> selfTanks; //actually the tanks you play with. Maybe the multi tanks` control system would be implemented,
                            // or the system, when you could switch bettween the tanks in real time
};

#endif // GRAPHICSCENEMODEL_H
