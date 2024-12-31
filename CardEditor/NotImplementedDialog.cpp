#pragma execution_character_set("utf-8")
#include "NotImplementedDialog.h"

NotImplementedDialog::NotImplementedDialog(QWidget* parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    this->setWindowTitle("Warning");

    ui.label->setText("This functionnality does not exist yet.");

    // Connecter le signal accepted() du QDialogButtonBox au slot accept() du QDialog
    connect(ui.buttonBox, &QDialogButtonBox::accepted, this, &NotImplementedDialog::accept);
}

NotImplementedDialog::~NotImplementedDialog()
{
}

