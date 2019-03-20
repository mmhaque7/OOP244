/*
 * Mehedi Haque
 * 154908172
 * Workshop 6 in-lab
 * March 14 2019
 * */

#include <iostream>
#include <cstring>

#include "Hero.h"

using namespace std;
namespace sict {


    Hero::Hero() {
        name[0] = '\0';
        health = 0;
        strength = 0;
    }

    Hero::Hero(const char *p_name, int p_health, int p_strength) {
        bool flag = false;
        if (p_name != nullptr) {
            if (p_health > 0) {
                if (p_strength > 0) {
                    strncpy(name, p_name, 40);
                    name[40] = '\0';
                    health = p_health;
                    strength = p_strength;
                    flag = true;
                }
            }
        }
        if (!flag) {
            name[0] = '\0';
            health = 0;
            strength = 0;
        }

    }

    void Hero::operator-=(int attack) {
        if (attack > 0) {
            health - attack <= 0 ? (health = 0) : (health -= attack);
        }
    }

    bool Hero::isAlive() const {
        bool flag = false;
        if (health > 0) {
            flag = true;//you are alive
        }


        return flag;

    }

    int Hero::attackStrength() const {
        return strength;
    }

    std::ostream &operator<<(ostream &os, const Hero &hero) {
        if (hero.name != nullptr) {
            os << hero.name;
        } else {
            os << "No hero";
        }

        return os;

    }
    const Hero & operator*(const Hero & first, const Hero & second)
    {
        int round = 0;
        int flag = 0;
        Hero one = first;
        Hero two = second;


        for (int i = 1; !flag; i++) {
            one -= two.attackStrength();
            two -= one.attackStrength();

            if (!(one.isAlive()) || !(two.isAlive())) {
                round = i;
                flag = 1;
            }
            if (i == max_rounds) {
                flag = 1;
            }

        }
        cout << "Ancient Battle! " << first << " vs " << second<< " : Winner is ";

        if (one.isAlive()) {
            cout << first;
        }
        else {
            cout << second;
        }
        cout << " in " << round << " rounds." << endl;

        return one.isAlive() ? first : second;

    }
}