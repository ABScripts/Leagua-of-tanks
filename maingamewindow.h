#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QMainWindow>

class QScreen;
class GameView;
class GameSceneViewModel;

class MainGameWindow: public QMainWindow
{
public:
    MainGameWindow(QWidget * parent = nullptr);
private:
    GameView * mView_ptr;
    GameSceneViewModel * mScene_ptr;
    QScreen * currentScreen;

    void setupWindow();
    void setWindowsSize();
};

#endif // MAINGAMEWINDOW_H
