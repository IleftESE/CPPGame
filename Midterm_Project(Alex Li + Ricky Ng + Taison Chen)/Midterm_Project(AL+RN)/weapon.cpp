#include "weapon.h"

weapon::weapon()
{
	W_item = "Blank";
	W_damage = 0;
	W_uses = 99999;
	W_cost = 0;
}

weapon::weapon(string i, int d, int u, int c)
{
	W_item = i;
	W_damage = d;
	W_uses = u;
	W_cost = c;
}

void weapon::setItem(string W_item)
{
	this->W_item = W_item;
}

void weapon::setDMG(int W_damage)
{
	this->W_damage = W_damage;
}

void weapon::setUses(int W_uses)
{
	this->W_uses = W_uses;
}

void weapon::setCost(int W_cost)
{
	this->W_cost = W_cost;
}

string weapon::getItem()
{
	return W_item;
}

int weapon::getDMG()
{
	return W_damage;
}

int weapon::getUses()
{
	return W_uses;
}

int weapon::getCost()
{
	return W_cost;
}


