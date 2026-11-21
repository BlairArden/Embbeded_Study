#ifndef HERO_H
#define HERO_H
#include "Character.h"


class Hero : virtual public Character {
    double mp;
    double mp_max;

public:
    Hero();

    Hero(double hp, double attack, double mp);

    double getMP() const;

    void setMP(double mp);

    double getMP_max() const;

    bool skill_1(Character &);

    bool skill_2(Character &);

    bool skill_3(Character &);

    void skill_4();
};


#endif //HERO_H
