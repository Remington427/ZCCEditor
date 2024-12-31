#include "MainToolbar.h"

MainToolbar::MainToolbar(QWidget* parent) :
    QToolBar(parent)
{
    actionOpen = new QAction(tr("Open"), this);
    actionSave = new QAction(tr("Save"), this);

    addAction(actionOpen);
    addAction(actionSave);

    connect(actionOpen, &QAction::triggered, this, &MainToolbar::openTriggered);
    connect(actionSave, &QAction::triggered, this, &MainToolbar::saveTriggered);
}
