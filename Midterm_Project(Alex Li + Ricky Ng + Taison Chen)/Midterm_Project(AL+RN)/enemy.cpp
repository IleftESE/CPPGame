#include "enemy.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

enemy::enemy()
{
    Name = "Goblin";
    MaxHealth = 40;
    HealthPoints = 40;
    AttackDamage = 10;
    level = 1;
    Gold = 20;
}

enemy::enemy(string name, int max, int hp, int ad, int lvl, int gold)
{
    Name = name;
    MaxHealth = max;
    HealthPoints = hp;
    AttackDamage = ad;
    level = lvl;
    Gold = gold;
}

string enemy::getName()
{
    return Name; // return the variable from private
}

int enemy::getMaxHP()
{
    return MaxHealth;
}

int enemy::getHP()
{
    return HealthPoints;
}

int enemy::getDMG()
{
    return AttackDamage;
}

int enemy::getLVL()
{
    return level;
}

int enemy::getGold()
{
    return Gold;
}

int enemy::rngDMG()             //getter function in which you are displaying a rng value
{
    int randomNumber; // set up the variable

    randomNumber = (rand() % AttackDamage) + 1; // this is the randomization
                                                // with AttackDamage to be the maximum output
                                                // range is from 1 to AttackDamage
    return randomNumber;
}


void enemy::setName(string name)
{
    Name = name;
}

void enemy::setMaxHP(int max)
{
    MaxHealth = max;
}

void enemy::setHP(int hp)
{
    HealthPoints = hp;
}

void enemy::setDMG(int ad)
{
    AttackDamage = ad;
}

void enemy::setLVL(int lvl)
{
    level = lvl;
}

void enemy::setGold(int gold)
{
    Gold = gold;
}

void enemy::status()
{
    cout.setf(ios::fixed);
    cout << "Max Hp: " << getMaxHP() << "\n" << "Current health: " << getHP() << "\n" << "Damage: " << getDMG() << "\n" << "Level: " << getLVL() << "\n" << "Gold drop: " << getGold() << endl;
}

ostream& operator << (ostream& os, const enemy& e)
{
    os << "Max Hp: " << e.MaxHealth << "\n" << "Current health: " << e.HealthPoints << "\n" << "Damage: " << e.AttackDamage << "\n" << "Level: " << e.level << "\n" << "Gold drop: " << e.Gold << endl;
    return os;
}

void enemy::modHealth(int n)
{
    if (HealthPoints == MaxHealth)
    {
        HealthPoints = MaxHealth - n;
    }
    else
    {
        HealthPoints = HealthPoints - n;
    }
}
