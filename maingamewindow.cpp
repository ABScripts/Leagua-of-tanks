#include "maingamewindow.h"

#include <QScreen>
#include <QGuiApplication>
#include <QDesktopWidget>
#include "gameview.h"
#include "graphicscenemodel.h"

namespace { // temporary settings for screen resolution
    enum class Resolution {
        Width = 1600,
        Height = 800
    };
}

MainGameWindow::MainGameWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupWindow();

    mScene_ptr = new GameSceneViewModel(0,
                                   0,
                                   static_cast<int>(Resolution::Width),
                                   static_cast<int>(Resolution::Height),
                                   this);

    mView_ptr = new GameView(mScene_ptr, this);
}

void MainGameWindow::setupWindow()
{
    setWindowsSize();
    connect(currentScreen, &QScreen::geometryChanged, this, &MainGameWindow::setWindowsSize);
}

void MainGameWindow::setWindowsSize()
{
    QList<QScreen *> systemScreens = QGuiApplication::screens();
    currentScreen = systemScreens[0];
    // searching for the "biggest monitor"
    for (QList<QScreen *>::Iterator it = std::next(systemScreens.begin()); it != systemScreens.end(); ++it) {
        if ((*it)->geometry().width() > currentScreen->geometry().width() &&
                (*it)->geometry().height() > currentScreen->geometry().height()) {
            currentScreen = *it;
        }
    }

    setFixedSize(currentScreen->geometry().width(), currentScreen->geometry().height());
}
