#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "CardEditor.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void on_actionExport_triggered();
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionParameters_triggered();
    void on_actionProperties_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();

private:
    Ui::MainWindowClass ui;
    CardEditor* editor;
};
