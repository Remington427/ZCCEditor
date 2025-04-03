#include "CardEditor.h"
#include "ui_CardEditor.h"
#include <QFontDatabase>
#include <QPixmap>
#include <QFileDialog>

CardEditor::CardEditor(std::string card_name, CardType type, QWidget* parent) :
    QWidget(parent)
{

    // ScrollBarPolicy
    
    // Déclaration des maps
    cardTypeMap = new QMap<QString, CardType>;
    equipementTypeMap = new QMap<QString, EquipmentType>;
    equipmentbackgroundTypeMap = new QMap<QString, EquipmentbackgroundType>;
    skillsMap = new QMap<QString, Skills>;

    // Déclaration image
    cardImage = new ScalableItem;

    // Déclaration des items textuels
    survivorTextItemBack = new QGraphicsTextItem(QString::fromStdString(card_name));
    survivorTextItemBack->setPos(0, -85);
    survivorTextItemBack->setRotation(-5);
    int id = QFontDatabase::addApplicationFont("C:/Users/Utilisateur/Documents/GitHub/ZCCEditor/CardEditor/data/fonts/Cracked.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont crackhouse(family);
    crackhouse.setPointSize(228);
    crackhouse.setBold(true);
    survivorTextItemBack->setFont(crackhouse);
    QColor background_gray(211, 209, 222);
    survivorTextItemBack->setDefaultTextColor(background_gray);

    survivorTextItem = new QGraphicsTextItem(QString::fromStdString(card_name));
    survivorTextItem->setPos(100, 50);
    survivorTextItem->setRotation(-5);
    crackhouse.setPointSize(72);
    crackhouse.setBold(true);
    survivorTextItem->setFont(crackhouse);
    survivorTextItem->setDefaultTextColor(Qt::black);

    int x = 95, y = 255, offset = 91;
    QFont f;
    f.setPointSize(18);
    f.setBold(true);

    blueLevelTextItem = new QGraphicsTextItem;
    blueLevelTextItem->setPos(x, y);
    blueLevelTextItem->setFont(f);
    blueLevelTextItem->setDefaultTextColor(Qt::black);

    y += offset;
    yellowLevelTextItem = new QGraphicsTextItem;
    yellowLevelTextItem->setPos(x, y);
    yellowLevelTextItem->setFont(f);
    yellowLevelTextItem->setDefaultTextColor(Qt::black);

    y += offset;
    orange_first_LevelTextItem = new QGraphicsTextItem;
    orange_first_LevelTextItem->setPos(x, y);
    orange_first_LevelTextItem->setFont(f);
    orange_first_LevelTextItem->setDefaultTextColor(Qt::black);

    y += offset;
    orange_second_LevelTextItem = new QGraphicsTextItem;
    orange_second_LevelTextItem->setPos(x, y);
    orange_second_LevelTextItem->setFont(f);
    orange_second_LevelTextItem->setDefaultTextColor(Qt::black);

    y += offset;
    red_first_LevelTextItem = new QGraphicsTextItem;
    red_first_LevelTextItem->setPos(x, y);
    red_first_LevelTextItem->setFont(f);
    red_first_LevelTextItem->setDefaultTextColor(Qt::black);

    y += offset;
    red_second_LevelTextItem = new QGraphicsTextItem;
    red_second_LevelTextItem->setPos(x, y);
    red_second_LevelTextItem->setFont(f);
    red_second_LevelTextItem->setDefaultTextColor(Qt::black);

    y += offset;
    red_third_LevelTextItem = new QGraphicsTextItem;
    red_third_LevelTextItem->setPos(x, y);
    red_third_LevelTextItem->setFont(f);
    red_third_LevelTextItem->setDefaultTextColor(Qt::black);

    // UI

    ui.setupUi(this);

    // Initialisation des maps
    cardTypeMap->insert("Survivor", CardType::Survivor);
    cardTypeMap->insert("Equipment", CardType::Equipment);
    equipementTypeMap->insert("Tool", EquipmentType::Tool);
    equipementTypeMap->insert("Weapon", EquipmentType::Weapon);
    equipmentbackgroundTypeMap->insert("PimpWeapon", EquipmentbackgroundType::PimpWeapon);
    equipmentbackgroundTypeMap->insert("SearchDeck", EquipmentbackgroundType::SearchDeck);
    equipmentbackgroundTypeMap->insert("Starter", EquipmentbackgroundType::Starter);
    skillsMap->insert("+1 ACTION", Skills::PlusOneAction);
    skillsMap->insert("+1 DAMAGE: COMBAT", Skills::PlusOneDamageCombat);
    skillsMap->insert("+1 DAMAGE: MELEE", Skills::PlusOneDamageMelee);
    skillsMap->insert("+1 DAMAGE: RANGED", Skills::PlusOneDamageRanged);
    skillsMap->insert("+1 DIE: COMBAT", Skills::PlusOneDieCombat);
    skillsMap->insert("+1 DIE: MELEE", Skills::PlusOneDieMelee);
    skillsMap->insert("+1 DIE: RANGED", Skills::PlusOneDieRanged);
    skillsMap->insert("+1 FREE COMBAT ACTION", Skills::PlusOneFreeCombatAction);
    skillsMap->insert("+1 FREE MELEE ACTION", Skills::PlusOneFreeMeleeAction);
    skillsMap->insert("+1 FREE MOVE ACTION", Skills::PlusOneFreeMoveAction);
    skillsMap->insert("+1 FREE RANGED ACTION", Skills::PlusOneFreeRangedAction);
    skillsMap->insert("+1 FREE SEARCH ACTION", Skills::PlusOneFreeSearchAction);
    skillsMap->insert("+1 MAX RANGE", Skills::PlusOneMaxRange);
    skillsMap->insert("+1 ZONE PER MOVE", Skills::PlusOneZonePerMove);
    skillsMap->insert("+1 TO DICE ROLL: COMBAT", Skills::PlusOneToDiceRollCombat);
    skillsMap->insert("+1 TO DICE ROLL: MELEE", Skills::PlusOneToDiceRollMelee);
    skillsMap->insert("+1 TO DICE ROLL: RANGED", Skills::PlusOneToDiceRollRanged);
    skillsMap->insert("COMBAT: DAMAGE 2", Skills::DamageTwoCombat);
    skillsMap->insert("MELEE: DAMAGE 2", Skills::DamageTwoMelee);
    skillsMap->insert("RANGED: DAMAGE 2", Skills::DamageTwoRanged);
    skillsMap->insert("2 COCKTAILS ARE BETTER THAN 1", Skills::TwoCocktailsAreBetterThanOne);
    skillsMap->insert("AMBIDEXTROUS", Skills::Ambidextrous);
    skillsMap->insert("BARBARIAN", Skills::Barbarian);
    skillsMap->insert("BLITZ", Skills::Blitz);
    skillsMap->insert("BLOODLUST: COMBAT", Skills::BloodlustCombat);
    skillsMap->insert("BLOODLUST: MELEE", Skills::BloodlustMelee);
    skillsMap->insert("BLOODLUST: RANGED", Skills::BloodlustRanged);
    skillsMap->insert("BORN LEADER", Skills::BornLeader);
    skillsMap->insert("BREAK-IN", Skills::BreakIn);
    skillsMap->insert("BROTHER IN ARMS:", Skills::BrotherInArms);
    skillsMap->insert("CAN SEARCH MORE THAN ONCE", Skills::CanSearchMoreThanOnce);
    skillsMap->insert("CHARGE", Skills::Charge);
    skillsMap->insert("COMBAT REFLEXES", Skills::CombatReflexes);
    skillsMap->insert("DESTINY", Skills::Destiny);
    skillsMap->insert("DISTRIBUTOR", Skills::Distributor);
    skillsMap->insert("DREADNOUGH: BRUTES", Skills::DreadnoughtBrutes);
    skillsMap->insert("DREADNOUGH: RUNNERS", Skills::DreadnoughtRunners);
    skillsMap->insert("DREADNOUGH: WALKERS", Skills::DreadnoughtWalkers);
    skillsMap->insert("DUAL EXPERT", Skills::DualExpert);
    skillsMap->insert("ESCALATION: COMBAT", Skills::EscalationCombat);
    skillsMap->insert("ESCALATION: MELEE", Skills::EscalationMelee);
    skillsMap->insert("ESCALATION: RANGED", Skills::EscalationRanged);
    skillsMap->insert("FIELD MEDIC", Skills::FieldMedic);
    skillsMap->insert("FREE RELOAD", Skills::FreeReload);
    skillsMap->insert("FULL AUTO", Skills::FullAuto);
    skillsMap->insert("GUNSLINGER", Skills::Gunslinger);
    skillsMap->insert("HIT&RUN", Skills::HitAndRun);
    skillsMap->insert("HOARD", Skills::Hoard);
    skillsMap->insert("HOLD YOUR NOSE", Skills::HoldYourNose);
    skillsMap->insert("HOME DEFENDER", Skills::HomeDefender);
    skillsMap->insert("IMPROVISED: MELEE", Skills::ImprovisedWeaponMelee);
    skillsMap->insert("IMPROVISED: RANGED", Skills::ImporvisedWeaponRanged);
    skillsMap->insert("IS THAT ALL YOU'VE GOT?", Skills::IsThatAllYouGot);
    skillsMap->insert("JUMP", Skills::Jump);
    skillsMap->insert("LIFE SAVER", Skills::LifeSaver);
    skillsMap->insert("LOW PROFILE", Skills::LowProfile);
    skillsMap->insert("LUCKY", Skills::Lucky);
    skillsMap->insert("MATCHING SET", Skills::MatchingSet);
    skillsMap->insert("MEDIC", Skills::Medic);
    skillsMap->insert("POINT-BLANK", Skills::PointBlank);
    skillsMap->insert("REAPER: COMBAT", Skills::ReaperCombat);
    skillsMap->insert("REAPER: MELEE", Skills::ReaperMelee);
    skillsMap->insert("REAPER: RANGED", Skills::ReaperRanged);
    skillsMap->insert("REGENERATION", Skills::Regeneration);
    skillsMap->insert("ROLL 6: +1 DAMAGE: COMBAT", Skills::RollSixPlusOneDamageCombat);
    skillsMap->insert("ROLL 6: +1 DAMAGE: MELEE", Skills::RollSixPlusOneDamageMelee);
    skillsMap->insert("ROLL 6: +1 DAMAGE: RANGED", Skills::RollSixPlusOneDamageRanged);
    skillsMap->insert("ROLL 6: +1 DIE: COMBAT", Skills::RollSixPlusOneDieCombat);
    skillsMap->insert("ROLL 6: +1 DIE: MELEE", Skills::RollSixPlusOneDieMelee);
    skillsMap->insert("ROLL 6: +1 DIE: RANGED", Skills::RollSixPlusOneDieRanged);
    skillsMap->insert("SCAVENGER", Skills::Scavenger);
    skillsMap->insert("SEARCH: 2 CARDS", Skills::SearchTwoCards);
    skillsMap->insert("SHOVE", Skills::Shove);
    skillsMap->insert("SIDESTEP", Skills::SideStep);
    skillsMap->insert("SLIPPERY", Skills::Slippery);
    skillsMap->insert("SNIPER", Skills::Sniper);
    skillsMap->insert("SPRINT", Skills::Sprint);
    skillsMap->insert("STARTS WITH EQUIPMENT: ", Skills::StartsWithEquipement);
    skillsMap->insert("STARTS WITH X AP", Skills::StartsWithXAP);
    skillsMap->insert("STARTS WITH X HEALTH", Skills::StartsWithXHealth);
    skillsMap->insert("STEADY HAND", Skills::SteadyHand);
    skillsMap->insert("SUPER STRENGTH", Skills::SuperStrength);
    skillsMap->insert("SWORDMASTER", Skills::Swordmaster);
    skillsMap->insert("TACTICIAN", Skills::Tactician);
    skillsMap->insert("TAUNT", Skills::Taunt);
    skillsMap->insert("TOUGH", Skills::Tough);
    skillsMap->insert("WEBBING", Skills::Webbing);
    skillsMap->insert("ZOMBIE LINK", Skills::ZombieLink);



    ui.cardType_cb->addItems(QStringList(cardTypeMap->keys()));
    ui.cardType_cb->setCurrentText(cardTypeMap->key(type));

    ui.cardName_le->setText(QString::fromStdString(card_name));

    ui.backgroundType_cb->addItems(QStringList(equipmentbackgroundTypeMap->keys()));
    ui.equipmentType_cb->addItems(QStringList(equipementTypeMap->keys()));

    ui.blueLevel_cb->addItems(QStringList(skillsMap->keys()));
    ui.yellowLevel_cb->addItems(QStringList(skillsMap->keys()));
    ui.orangeLevel_cb->addItems(QStringList(skillsMap->keys()));
    ui.orangeLevel_cb_2->addItems(QStringList(skillsMap->keys()));
    ui.redLevel_cb->addItems(QStringList(skillsMap->keys()));
    ui.redLevel_cb_2->addItems(QStringList(skillsMap->keys()));
    ui.redLevel_cb_3->addItems(QStringList(skillsMap->keys()));

    // Pas une arme par défaut
    ui.groupBox_4->hide();
    // Une seule attaque par défaut
    ui.secondAttack_gb->hide();

    // Slider taille de l'image
    ui.imageSize_hsl->setValue(10);
    ui.imageSize_hsl->setMinimum(1);
    ui.imageSize_hsl->setMaximum(20);

    scene = new QGraphicsScene(this);

    switch (type) {
        case CardType::Survivor:
            // Masque les composants équipements
            ui.groupBox_3->hide();
            backgroundPM.load("C:/Users/Utilisateur/Documents/GitHub/ZCCEditor/CardEditor/data/background/Template_ID_Card.png");
            scene->addPixmap(backgroundPM);
            blueLevelTextItem->setPlainText(ui.blueLevel_cb->currentText());
            yellowLevelTextItem->setPlainText(ui.yellowLevel_cb->currentText());
            orange_first_LevelTextItem->setPlainText(ui.orangeLevel_cb->currentText());
            orange_second_LevelTextItem->setPlainText(ui.orangeLevel_cb_2->currentText());
            red_first_LevelTextItem->setPlainText(ui.redLevel_cb->currentText());
            red_second_LevelTextItem->setPlainText(ui.redLevel_cb_2->currentText());
            red_third_LevelTextItem->setPlainText(ui.redLevel_cb_3->currentText());
            scene->addItem(survivorTextItemBack);
            scene->addItem(survivorTextItem);
            scene->addItem(blueLevelTextItem);
            scene->addItem(yellowLevelTextItem);
            scene->addItem(orange_first_LevelTextItem);
            scene->addItem(orange_second_LevelTextItem);
            scene->addItem(red_first_LevelTextItem);
            scene->addItem(red_second_LevelTextItem);
            scene->addItem(red_third_LevelTextItem);
            scene->addItem(cardImage);
            break;
        case CardType::Equipment:
            // Masque les composants survivants
            ui.groupBox_2->hide();
            backgroundPM.load("C:/Users/Utilisateur/Documents/GitHub/ZCCEditor/CardEditor/data/background/bleu.png");
            scene->addPixmap(backgroundPM);
            break;
    }
    // Image de fond
    ui.graphicsView->setScene(scene);
    QRect rcontent = ui.graphicsView->contentsRect();
    ui.graphicsView->setSceneRect(0, 0, rcontent.width(), rcontent.height());
    ui.graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // SIGNAUX
    connect(ui.cardName_le, SIGNAL(textChanged(const QString)), this, SLOT(cardNameChanged(const QString)));
    connect(ui.cardType_cb, SIGNAL(currentIndexChanged(int)), this, SLOT(cardTypeChanged(int)));
    connect(ui.uploadImage_pb, SIGNAL(clicked(bool)), this, SLOT(uploadImageClicked(bool)));
    connect(ui.imageSize_hsl, SIGNAL(valueChanged(int)), this, SLOT(updateImageZoom(int)));
    connect(ui.equipmentType_cb, SIGNAL(currentIndexChanged(int)), this, SLOT(equipmentTypeChanged(int)));
    connect(ui.doubleAttack_cb, SIGNAL(checkStateChanged(Qt::CheckState)), this, SLOT(numberOfAttackModeChanged(Qt::CheckState)));
    connect(ui.blueLevel_cb, SIGNAL(currentIndexChanged(int)), this, SLOT(blueLevelChanged(int)));
    connect(ui.yellowLevel_cb, SIGNAL(currentIndexChanged(int)), this, SLOT(yellowLevelChanged(int)));
    connect(ui.orangeLevel_cb, SIGNAL(currentIndexChanged(int)), this, SLOT(orange_first_LevelChanged(int)));
    connect(ui.orangeLevel_cb_2, SIGNAL(currentIndexChanged(int)), this, SLOT(orange_second_LevelChanged(int)));
    connect(ui.redLevel_cb, SIGNAL(currentIndexChanged(int)), this, SLOT(red_first_LevelChanged(int)));
    connect(ui.redLevel_cb_2, SIGNAL(currentIndexChanged(int)), this, SLOT(red_second_LevelChanged(int)));
    connect(ui.redLevel_cb_3, SIGNAL(currentIndexChanged(int)), this, SLOT(red_third_LevelChanged(int)));

}

CardEditor::~CardEditor()
{
    delete cardTypeMap;
    delete equipementTypeMap;
    delete equipmentbackgroundTypeMap;
    delete skillsMap;
    delete cardImage;
    delete survivorTextItemBack;
    delete survivorTextItem;
    delete blueLevelTextItem;
    delete yellowLevelTextItem;
    delete orange_first_LevelTextItem;
    delete orange_second_LevelTextItem;
    delete red_first_LevelTextItem;
    delete red_second_LevelTextItem;
    delete red_third_LevelTextItem;
    delete scene;
}

void CardEditor::cardNameChanged(const QString& text)
{
    survivorTextItemBack->setPlainText(text);
    survivorTextItem->setPlainText(text);
}

void CardEditor::numberOfAttackModeChanged(Qt::CheckState state)
{
    switch (state)
    {
        case Qt::Unchecked:
            ui.secondAttack_gb->hide();
            break;
        case Qt::PartiallyChecked:
            break;
        case Qt::Checked:
            ui.secondAttack_gb->show();
            break;
    }
}

void CardEditor::blueLevelChanged(int index)
{
    blueLevelTextItem->setPlainText(ui.blueLevel_cb->currentText());
}

void CardEditor::yellowLevelChanged(int index)
{
    yellowLevelTextItem->setPlainText(ui.yellowLevel_cb->currentText());
}

void CardEditor::orange_first_LevelChanged(int index)
{
    orange_first_LevelTextItem->setPlainText(ui.orangeLevel_cb->currentText());
}

void CardEditor::orange_second_LevelChanged(int index)
{
    orange_second_LevelTextItem->setPlainText(ui.orangeLevel_cb_2->currentText());
}

void CardEditor::red_first_LevelChanged(int index)
{
    red_first_LevelTextItem->setPlainText(ui.redLevel_cb->currentText());
}

void CardEditor::red_second_LevelChanged(int index)
{
    red_second_LevelTextItem->setPlainText(ui.redLevel_cb_2->currentText());
}

void CardEditor::red_third_LevelChanged(int index)
{
    red_third_LevelTextItem->setPlainText(ui.redLevel_cb_3->currentText());
}

void CardEditor::equipmentTypeChanged(int index)
{
    EquipmentType type = equipementTypeMap->value(ui.equipmentType_cb->currentText());
    switch (type) {
    case EquipmentType::Tool:
        // Masque les composants armes
        ui.groupBox_4->hide();
        break;
    case EquipmentType::Weapon:
        // Affiche les composants armes
        ui.groupBox_4->show();
        break;
    }
}

void CardEditor::cardTypeChanged(int index)
{
    CardType cardType = cardTypeMap->value(ui.cardType_cb->currentText());
    EquipmentType equipmentType = equipementTypeMap->value(ui.equipmentType_cb->currentText());
    switch (cardType) {
    case CardType::Survivor:
        // Masque les composants équipements
        ui.groupBox_3->hide();
        ui.groupBox_4->hide();
        // Affiche les composants survivants
        ui.groupBox_2->show();
        backgroundPM.load("C:/Users/Utilisateur/Documents/GitHub/ZCCEditor/CardEditor/data/background/Template_ID_Card.png");
        break;
    case CardType::Equipment:
        // Masque les composants survivants
        ui.groupBox_2->hide();
        // Affiche les composants équipement
        ui.groupBox_3->show();
        switch (equipmentType) {
            case EquipmentType::Tool:
                // Masque les composants armes
                ui.groupBox_4->hide();
                break;
            case EquipmentType::Weapon:
                // Affiche les composants armes
                ui.groupBox_4->show();
                break;
        }
        backgroundPM.load("C:/Users/Utilisateur/Documents/GitHub/ZCCEditor/CardEditor/data/background/bleu.png");
        break;
    }
}

void CardEditor::uploadImageClicked(bool checked)
{
    QString image_file = QFileDialog::getOpenFileName(this, "Choose card image", "C://", "Images (*.png *.xpm *.jpg)");
    imagePM.load(image_file);
    cardImage->setPixmap(imagePM);
}

void CardEditor::updateImageZoom(int value)
{
    cardImage->updateImageZoom(0.1f * value);
}
