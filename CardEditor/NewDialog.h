#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>
#include "ui_NewDialog.h"
#include "Enums.h"

class NewDialog : public QDialog
{
    Q_OBJECT

public:
    NewDialog(QWidget* parent = nullptr);
    ~NewDialog();
    std::string getCardName();
    CardType getCardType();

private:
    QMap<QString, CardType>* cardTypeMap;
    Ui::NewDialogForm ui;
};

#endif