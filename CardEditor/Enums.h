#ifndef ENUMS_H
#define ENUMS_H

// Exemple d'une classe enum pour des types d'images
enum class ImageType {
    JPEG,
    PNG,
    BMP,
    TIFF
};

// Classe enum pour type de carte
enum class CardType {
    Survivor,
    Equipment
};

// Classe enum pour type d'equipement
enum class EquipmentType {
    Tool,
    Weapon
};

// Type de fond (pour la couleur)
enum class EquipmentbackgroundType {
    Starter,
    SearchDeck,
    PimpWeapon
};

enum class AttackType
{
    Melee,
    Ranged
};

enum class NoiseType {
    Silent,
    Noisy
};

enum class AmmoType
{
    Bullet,
    Shotshell,
};

enum class DoorBreach {
    Yes,
    No
};

enum class SurvivorClass
{
    NoneByDefault,
    Kid,
    CopDriver
};

enum class Skills
{
    PlusOneAction,
    PlusOneDamageCombat,
    PlusOneDamageMelee,
    PlusOneDamageRanged,
    PlusOneDieCombat,
    PlusOneDieMelee,
    PlusOneDieRanged,
    PlusOneFreeCombatAction,
    PlusOneFreeMeleeAction,
    PlusOneFreeMoveAction,
    PlusOneFreeRangedAction,
    PlusOneFreeSearchAction,
    PlusOneMaxRange,
    PlusOneZonePerMove,
    PlusOneToDiceRollCombat,
    PlusOneToDiceRollMelee,
    PlusOneToDiceRollRanged,
    DamageTwoCombat,
    DamageTwoMelee,
    DamageTwoRanged,
    TwoCocktailsAreBetterThanOne,
    Ambidextrous,
    Barbarian,
    Blitz,
    BloodlustCombat,
    BloodlustMelee,
    BloodlustRanged,
    BornLeader,
    BreakIn,
    BrotherInArms,
    CanSearchMoreThanOnce,
    Charge,
    CombatReflexes,
    Destiny,
    Distributor,
    DreadnoughtBrutes,
    DreadnoughtRunners,
    DreadnoughtWalkers,
    DualExpert,
    EscalationCombat,
    EscalationMelee,
    EscalationRanged,
    FieldMedic,
    FreeReload,
    FullAuto,
    Gunslinger,
    HitAndRun,
    Hoard,
    HoldYourNose,
    HomeDefender,
    ImprovisedWeaponMelee,
    ImporvisedWeaponRanged,
    IsThatAllYouGot,
    Jump,
    LifeSaver,
    LowProfile,
    Lucky,
    MatchingSet,
    Medic,
    PointBlank,
    ReaperCombat,
    ReaperMelee,
    ReaperRanged,
    Regeneration,
    RollSixPlusOneDamageCombat,
    RollSixPlusOneDamageMelee,
    RollSixPlusOneDamageRanged,
    RollSixPlusOneDieCombat,
    RollSixPlusOneDieMelee,
    RollSixPlusOneDieRanged,
    Scavenger,
    SearchTwoCards,
    Shove,
    SideStep,
    Slippery,
    Sniper,
    Sprint,
    StartsWithXHealth,
    StartsWithXAP,
    StartsWithEquipement,
    SteadyHand,
    SuperStrength,
    Swordmaster,
    Tactician,
    Taunt,
    Tough,
    Webbing,
    ZombieLink,
};

#endif // ENUMS_H