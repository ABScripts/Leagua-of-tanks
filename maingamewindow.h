#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QScreen;
class GameView;
class GameSceneViewModel;
QT_END_NAMESPACE

class MainGameWindow: public QMainWindow
{
public:
    MainGameWindow(QWidget * parent = nullptr);
private:
    GameView * mView_ptr;
    GameSceneViewModel * mScene_ptr;
    QScreen * currentScreen;

    static const int width = 1600;
    static const int height = 800;

    void setupWindow();
    void setWindowsSize();
};

#endif // MAINGAMEWINDOW_H
