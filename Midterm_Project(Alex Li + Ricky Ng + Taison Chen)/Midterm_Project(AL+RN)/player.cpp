#include "player.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

player::player()
{
	Name = "MissingNo.";
	MaxHealth = 100;
	HealthPoints = 100;
	AttackDamage = 0;
	Currency = 20;
 }
string player::getName()
{
	return Name;
}
int player::getHP()
{
	return HealthPoints;
}
int player::getMaxHP()
{
	return MaxHealth;
}
int player::getDMG()
{
	return AttackDamage;
}
int player::getC()
{
	return Currency;
}
void player::setName(string N1)
{
	cout << "What is thy name? ";
	cin >> N1;
	Name = N1;
}
void player::setC(int Currency)
{
	this->Currency = Currency;
}
void player::setDMG(int weapon1) //weapon is the damage that a weapon can deal
{
	AttackDamage = weapon1;
}
void player::setMaxHP(int health)
{
	MaxHealth = health;
}
void player::setHP(int health)
{
	HealthPoints = health;
}
void player::ModifyHealth(int HP)
{
	HealthPoints = getHP() + HP; //If HP is loss, use a negative number
	setHP(HealthPoints);
}
void player::ModifyCurrency(int gold)
{
	Currency = getC() + gold; //If gold is loss, use a negative number
	setC(Currency);
}
void player::ModifyDamage(int dmg)
{
	AttackDamage = getDMG() + dmg; //if attack damage is decreased, use a negative number
	setDMG(AttackDamage);
}
ostream& operator << (ostream& os, const player& p)
{
	os << "Max HP: " << p.MaxHealth << "\n" << "Current health: " << p.HealthPoints << "\n" << "Damage: " << p.AttackDamage << "\n" << "Gold: " << p.Currency << endl;
	return os;
}