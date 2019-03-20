/*
 * Mehedi Haque
 * 154908172
 * Workshop 6 in-lab
 * March 14 2019
 * */

#ifndef IN_LAB_HERO_H
#define IN_LAB_HERO_H

namespace sict{
const int max_rounds = 100;
class Hero{

    char name[41];
    int health;
    int strength;


public:
    Hero();
    void operator-=(int attack);
    bool isAlive() const;
    int attackStrength()const;
    Hero(const char *p_name, int p_health, int p_strength);

    friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
};

    const Hero& operator* (const Hero& first, const Hero& second);

}



#endif //IN_LAB_HERO_H
