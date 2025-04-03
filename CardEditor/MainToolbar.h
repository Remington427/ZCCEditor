#ifndef MAINTOOLBAR_H
#define MAINTOOLBAR_H

#include <QToolBar>
#include <QAction>

class MainToolbar : public QToolBar
{
    Q_OBJECT

public:
    explicit MainToolbar(QWidget* parent = nullptr);

signals:
    void openTriggered();
    void saveTriggered();
    void saveAsTriggered();

private:
    QAction* actionOpen;
    QAction* actionSave;
    QAction* actionSaveAs;
};

#endif // MAINTOOLBAR_H
