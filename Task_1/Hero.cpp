#include "Hero.h"
#include "Constant.h"

Hero::Hero() : Character(), mp(1.0), mp_max(mp) {
}

Hero::Hero(double hp, double atk, double mp) : Character(hp, atk), mp(mp), mp_max(mp) {
}

double Hero::getMP() const {
    return mp;
}

void Hero::setMP(double mp) {
    this->mp = mp;
}

double Hero::getMP_max() const {
    return mp_max;
}

bool Hero::skill_1(Character &attacked_target) {
    if (mp >= HERO_SKILL_1_MPCOST) {
        attacked_target.setHP(attacked_target.getHP() - HERO_SKILL_1_DAMAGE);
        mp -= HERO_SKILL_1_MPCOST;
    }
    return attacked_target.getHP() > 0;
}

bool Hero::skill_2(Character &attacked_target) {
    if (mp >= HERO_SKILL_2_MPCOST) {
        attacked_target.setHP(attacked_target.getHP() - HERO_SKILL_2_DAMAGE);
        mp -= HERO_SKILL_2_MPCOST;
    }
    return attacked_target.getHP() > 0;
}

bool Hero::skill_3(Character &attacked_target) {
    if (mp >= HERO_SKILL_3_MPCOST) {
        attacked_target.setHP(attacked_target.getHP() - HERO_SKILL_3_DAMAGE);
        mp -= HERO_SKILL_3_MPCOST;
    }
    return attacked_target.getHP() > 0;
}

void Hero::skill_4() {
    if (mp >= HERO_SKILL_4_MPCOST) {
        HP = HP + HERO_SKILL_4_HP_RECOVERY > HP_max ? HP_max : HP + HERO_SKILL_4_HP_RECOVERY;
        mp = mp - HERO_SKILL_4_MPCOST + HERO_SKILL_4_MP_RECOVERY > mp_max
                 ? mp_max
                 : mp - HERO_SKILL_4_MPCOST + HERO_SKILL_4_MP_RECOVERY;
    }
}
