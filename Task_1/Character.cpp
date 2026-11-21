#include "Character.h"

Character::Character() : HP(1.0), ATK(1.0), HP_max(HP) {
}

Character::Character(double hp, double atk) : HP(hp), ATK(atk), HP_max(HP) {
}

double Character::getHP() const { return HP; }
double Character::getATK() const { return ATK; }
void Character::setHP(double newValue) { HP = newValue; }

bool Character::attack(Character &attacked_target) const {
    attacked_target.setHP(attacked_target.getHP() - ATK);
    return attacked_target.getHP() > 0;
}
