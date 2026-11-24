#include <iostream>
#include <memory>

#include "Hero.h"
#include "Monster.h"
#include "Constant.h"

int main() {
    std::cout << "输入英雄属性：" << std::endl;
    double hero_hp;
    double hero_attack;
    double hero_mp;
    std::cin >> hero_hp >> hero_attack >> hero_mp;
    Hero hero{hero_hp, hero_attack, hero_mp};

    std::cout << "输入怪物属性" << std::endl;
    double monster_hp;
    double monster_attack;
    std::cin >> monster_hp >> monster_attack;
    Monster monster{monster_hp, monster_attack};

    std::string instruction;
    bool monster_survival = true;
    bool hero_survival = true;
    while (true) {
        std::cout << "是否使用技能？ 使用技能输入要是用的技能序号 1 2 3 4，不使用输入 0 （输入 q 退出）：" << std::endl;
        std::cin >> instruction;
        if (instruction != "0" && instruction != "1" && instruction != "2" && instruction != "3" && instruction != "4")
            break;

        int skill_number = std::stoi(instruction);
        switch (skill_number) {
            case 1:
                monster_survival = hero.skill_1(monster);
            break;
            case 2:
                monster_survival = hero.skill_2(monster);
            break;
            case 3:
                monster_survival = hero.skill_3(monster);
            break;
            case 4:
                hero.skill_4();
            break;
            default:
                monster_survival = hero.attack(monster);
        }
        hero_survival = monster.attack(hero);
        if (!monster_survival || !hero_survival) {
            if (monster_survival) {
                std::cout << "怪物获胜！";
            } else {
                std::cout << "英雄获胜！";
            }
            break;
        }
        double recovered_mp = hero.getMP() + ONE_TURN_MP_RECOVERY > hero.getMP_max()
                                  ? hero.getMP_max()
                                  : hero.getMP() + ONE_TURN_MP_RECOVERY;
        hero.setMP(recovered_mp);
    }
    return 0;
}
