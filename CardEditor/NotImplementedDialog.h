#ifndef NOTIMPLEMENTEDDIALOG_H
#define NOTIMPLEMENTEDDIALOG_H

#include <QDialog>
#include "ui_NotImplementedDialog.h"

class NotImplementedDialog : public QDialog
{
    Q_OBJECT

public:
    NotImplementedDialog(QWidget* parent = nullptr);
    ~NotImplementedDialog();

private:
    Ui::Form ui;
};

#endif // NOTIMPLEMENTEDDIALOG_H
