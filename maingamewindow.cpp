#include "maingamewindow.h"

#include <QScreen>
#include <QGuiApplication>
#include "gameview.h"
#include "graphicscenemodel.h"
namespace {

}

MainGameWindow::MainGameWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupWindow();

    mScene_ptr = new GameSceneViewModel(0, 0, width, height, this);

    mView_ptr = new GameView(mScene_ptr, this);
}

void MainGameWindow::setupWindow()
{
    setFixedSize(width, height);
    // setWindowsSize();
    // connect(currentScreen, &QScreen::geometryChanged, this, &MainGameWindow::setWindowsSize);
}

void MainGameWindow::setWindowsSize() // deprecated for a while
{
    QList<QScreen *> systemScreens = QGuiApplication::screens();
    currentScreen = systemScreens[0];
    // searching for the "biggest monitor"
    for (auto screen: systemScreens) {
        if (screen->geometry().width() > currentScreen->geometry().width() &&
                screen->geometry().height() > currentScreen->geometry().height()) {
            currentScreen = screen;
        }
    }

    setFixedSize(currentScreen->geometry().width(), currentScreen->geometry().height());
}
