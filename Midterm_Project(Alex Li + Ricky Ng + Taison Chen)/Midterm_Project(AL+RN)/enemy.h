#pragma once
#include <string>
using namespace std;

class enemy
{
private:
    string Name;        //This should hold the player’s name

    int MaxHealth;      //This should hold the maximum health of the player

    int HealthPoints;   //This should hold the current health of the player

    int AttackDamage;   //This should hold the attack damage of the player

    int level = 0;

    int Gold; // currency drop

public:
    enemy();
    enemy(string, int, int, int, int, int);
    string getName();
    int getMaxHP();     //returns the maximum health
    int getHP();
    int getDMG();       //returns the current damage
    int getLVL();       //returns the level
    int getGold();      //returns the gold
    int rngDMG();      //return the rng attack range


    void setName(string);
    void setMaxHP(int);
    void setHP(int);    //sets the current health
    void setDMG(int);   //sets the current damage
    void setLVL(int);   //sets the level
    void setGold(int);  //set the gold
    void status();      //see the status of the enemy. print all
    void operator << (int n);


    void modHealth(int); //decrease the player's health by rng damage
    void modDamage(int); //Increments or decrements the player’s attack damage by the input value
    friend ostream& operator <<(ostream& os, const enemy& e);
};
