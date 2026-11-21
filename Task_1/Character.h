#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
protected:
    double HP;
    double HP_max;
    double ATK;

public:
    Character();

    Character(double, double);

    double getHP() const;

    double getATK() const;

    void setHP(double);

    bool attack(Character &) const;
};


#endif //CHARACTER_H
