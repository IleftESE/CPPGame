#pragma once
#include <string>
using namespace std;

class player
{
private:
	string Name;
	//This should hold the player’s name
	int MaxHealth;
	//This should hold the maximum health of the player
	int HealthPoints;
	//This should hold the current health of the player
	int AttackDamage;
	//This should hold the attack damage of the player
	int Currency;
	//Holds the amount of gold the player has
public:
	player();
	//default constructor
	string getName();
	int getMaxHP();
	//returns the maximum health
	int getHP();
	//returns the current health
	int getDMG();
		//returns the current damage
	int getC();
	//returns the amount of gold the player has
	void setName(string);
	void setMaxHP(int);
	void setHP(int);
	//sets the current health
	void setDMG(int);
	//sets the current damage
	void setC(int);
	//sets the amount of gold the player has
	void ModifyHealth(int);
	//Increments or decrements the player’s health by the input value
	void ModifyDamage(int);
	//Increments or decrements the player’s attack damage by the input value
	void ModifyCurrency(int);
	//Increments of decrements the player's currency
	friend ostream& operator <<(ostream& os, const player& p);
};