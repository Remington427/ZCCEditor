#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "ScalableItem.h"
#include "ui_CardEditor.h"
#include "Enums.h"

class CardEditor : public QWidget
{
    Q_OBJECT

public:
    CardEditor(std::string card_name, CardType type, QWidget* parent = nullptr);
    ~CardEditor();

private slots:
    void cardNameChanged(const QString& text);
    void cardTypeChanged(int index);
    void uploadImageClicked(bool checked = false);
    void blueLevelChanged(int index);
    void yellowLevelChanged(int index);
    void orange_first_LevelChanged(int index);
    void orange_second_LevelChanged(int index);
    void red_first_LevelChanged(int index);
    void red_second_LevelChanged(int index);
    void red_third_LevelChanged(int index);
    void equipmentTypeChanged(int index);
    void numberOfAttackModeChanged(Qt::CheckState state);

private:
    QMap<QString, EquipmentbackgroundType>* equipmentbackgroundTypeMap;
    QMap<QString, CardType>* cardTypeMap;
    QMap<QString, EquipmentType>* equipementTypeMap;
    QMap<QString, Skills>* skillsMap;
    Ui::editorForm ui;
    QPixmap backgroundPM;
    QPixmap imagePM;
    QGraphicsScene *scene;
    ScalableItem* cardImage;
    QGraphicsTextItem* survivorTextItemBack;
    QGraphicsTextItem* survivorTextItem;
    QGraphicsTextItem *blueLevelTextItem;
    QGraphicsTextItem* yellowLevelTextItem;
    QGraphicsTextItem* orange_first_LevelTextItem;
    QGraphicsTextItem* orange_second_LevelTextItem;
    QGraphicsTextItem* red_first_LevelTextItem;
    QGraphicsTextItem* red_second_LevelTextItem;
    QGraphicsTextItem* red_third_LevelTextItem;
};

#endif // EDITOR_H