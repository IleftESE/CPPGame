#pragma once
#include <string>
#include <iostream>
using namespace std;

class weapon
{
private:
	string W_item;
	//Name of the weapon item
	int W_damage;
	//Attack damage to the item. This can be added or removed by the player
	int W_uses;
	//Number of uses for the weapon
	int W_cost;
	//Cost of the weapon
public:
	weapon();
	weapon(string i, int d, int u, int c);
	void setItem(string W_item);
	void setDMG(int W_damage);
	void setUses(int W_uses);
	void setCost(int W_cost);
	string getItem();
	int getDMG();
	int getUses();
	int getCost();
};
