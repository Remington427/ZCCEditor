#include "NewDialog.h"


NewDialog::NewDialog(QWidget* parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    this->setWindowTitle("New card");

    cardTypeMap = new QMap<QString, CardType>;

    cardTypeMap->insert("Survivor", CardType::Survivor);
    cardTypeMap->insert("Equipment", CardType::Equipment);

    ui.cardType_cb->addItems(QStringList(cardTypeMap->keys()));

    // Connecter le signal accepted() du QDialogButtonBox au slot accept() du QDialog
    connect(ui.buttonBox, &QDialogButtonBox::accepted, this, &NewDialog::accept);
}

NewDialog::~NewDialog()
{
    delete cardTypeMap;
}

std::string NewDialog::getCardName()
{
    return ui.cardName_le->text().toStdString();
}

CardType NewDialog::getCardType()
{
    return cardTypeMap->value(ui.cardType_cb->currentText());
}
