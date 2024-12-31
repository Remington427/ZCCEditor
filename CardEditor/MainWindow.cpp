#include "MainWindow.h"
#include "NotImplementedDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Affiche la fenetre en mode maximise
    showMaximized();
}

MainWindow::~MainWindow()
{}

void MainWindow::on_actionOpen_triggered()
{
    NotImplementedDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_actionSave_triggered()
{
    NotImplementedDialog dialog(this);
    dialog.exec();
}