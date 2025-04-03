#include "MainWindow.h"
#include "NotImplementedDialog.h"
#include "NewDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Affiche la fenetre en mode maximise
    showMaximized();
}

MainWindow::~MainWindow()
{
    delete editor;
}

void MainWindow::on_actionExit_triggered()
{
    // TODO
    NotImplementedDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_actionExport_triggered()
{
    // TODO
    NotImplementedDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_actionNew_triggered()
{
    // TODO Remplacez par New Dialogue
    NewDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        std::string card_name = dialog.getCardName();
        CardType card_type = dialog.getCardType();

        // Supprimer l'ancien widget si nécessaire
        if (editor) {
            delete editor;
        }

        // Créer et afficher le nouveau widget Editor
        editor = new CardEditor(card_name, card_type, this);
        setCentralWidget(editor);
    }
}

void MainWindow::on_actionOpen_triggered()
{
    // TODO
    NotImplementedDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_actionParameters_triggered()
{
    // TODO
    NotImplementedDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_actionProperties_triggered()
{
    // TODO
    NotImplementedDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_actionSave_triggered()
{
    // TODO
    NotImplementedDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_actionSaveAs_triggered()
{
    // TODO
    NotImplementedDialog dialog(this);
    dialog.exec();
}
