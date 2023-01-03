#include "player.h"
#include "enemy.h"
#include "scoreboard.h"
#include "weapon.h"
#include "FileOperation.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include "weapon.h"
#include <vector>
using namespace std;

//Hello! This is the main code for running the game! Made in collaboration with Taison Chen, Alex Li and Ricky Ng!

int counter(int j)
{
	return j;
}

int main()
{
	//	int money = 0;
	string N1; //Player name
	player p1; //Initializes default player's profile
	enemy p2; //Initializes default enemy values
	scoreboard p3;
	weapon p4;
	string filename;
	char scoreboardfile;
	string SBfilename; //name of the saved scoreboard file
	string Pfilename; //name of the saved player file
	char difficulty; //difficulty of game
	string difficulty1; //full string statement of the difficulty
	char savegame; //options are y or n for seeing if there is a saved file
	char options; //Used for menu "What would you like to do?"
	char battleoptions; //used for battle
	ifstream datain; //input file
	ifstream datain2; //for weapon list
	string weaponline; //string from weaponlist.txt
	ofstream dataout; //output file
	vector <string> weaponsowned;
	int weaponnumber = 0; //keeps track of the number of weapons the user owns
	int weapondmg[5] = {}; //storing weapon damage
	int punchdamage = 0; //sets the punchdamage

	FileOperations f1;

	cout << "Do you have an existing player file?" << endl;
	cout << "[Y]es or [N]o" << endl;
	cout << "> ";
	cin >> savegame;
	switch (savegame) //switch for seeing if there is a save file
	{
	case 'Y':
	case 'y':
		/*
				cout << "What is the name of the scoreboard file and player file?" << endl;
				cin >> SBfilename >> Pfilename;
				f1.ChooseSB(SBfilename);
				f1.ChooseP(Pfilename);
				break;
				*/
		cout << "What is the name of this file?" << endl;
		cin >> filename;
		datain.open(filename);
		if (datain.fail())
		{
			cerr << "File cannot be opened or was not found." << endl;
			//system("pause");
			exit(1);
		}
		else
		{
			cout << "File successfully found!" << endl;
		}
		cout << "Do you have an existing scoreboard file?" << endl;
		cout << "[Y]es or [N]o" << endl;
		cout << "> ";
		cin >> scoreboardfile;
		switch (scoreboardfile)
		{
		case'y':
		case'Y':
			f1.ChooseSB("scoreboard1.txt");
			break;
		case 'n':
		case'N':
			cout << "Scoreboard createed!" << endl;
			f1.SaveScoreboard("scoreboard1.txt");
			break;
		default:
			cout << "Invalid option." << endl;
			exit(1);
		}


		while (!datain.eof())
		{
			datain >> N1;
			p3.setName(N1);
			//cout << N1 << endl;
			datain >> difficulty1;
			p3.setDiff(difficulty1);
			//cout << difficulty1 << endl;
			//money++;
			//cout << money << endl;
		}
		if (difficulty1 == "Easy")
		{
			punchdamage = 15;
		}
		else if (difficulty1 == "Medium")
		{
			punchdamage = 10;
		}
		else if (difficulty1 == "Hard")
		{
			punchdamage = 5;
		}
		break;
	case 'N':
	case 'n':
		cout << "What would you like to call this file?" << endl;
		cin >> filename;
		dataout.open(filename);
		if (dataout.fail())
		{
			cerr << "File cannot be opened." << endl;
			//system("pause");
			exit(1);
		}
		else
		{
			cout << "Success in creating new file!\nScoreboard created!" << endl;
			f1.SaveScoreboard("scoreboard1.txt");
		}

		p1.setName(N1);
		p3.setName(N1);
		dataout << p1.getName() << endl;
		cout << "What difficulty level do you want to play on?" << "\n" << "Pick from: [E]asy, [M]edium, or [H]ard" << "\n> ";
		cin >> difficulty;
		switch (difficulty)
		{
		case'e':
		case'E':
			difficulty1 = "Easy";
			p3.setDiff(difficulty1);
			break;
		case 'M':
		case'm':
			difficulty1 = "Medium";
			p3.setDiff(difficulty1);
			break;
		case 'H':
		case 'h':
			difficulty1 = "Hard";
			p3.setDiff(difficulty1);
			break;
		}
		cout << "You chose " << difficulty1 << "!" << endl;
		if (difficulty1 == "Easy")
		{
			punchdamage = 15;
		}
		else if (difficulty1 == "Medium")
		{
			punchdamage = 10;
		}
		else if (difficulty1 == "Hard")
		{
			punchdamage = 5;
		}

		dataout << difficulty1 << endl; //don't forget to not put an "endl" at the end of the dataout!
		break;
	default: //if options y or n are not chosen
		cout << "That is not a valid option." << endl;
		//system("pause");
		exit(1);
	}
	options = 'z';
	int level = 1; //acts a counter for knowing the floor level
LOOP: while (options != 'Q' && p1.getHP() != 0 && level < 5) {
	cout << "What would you like to do?" << endl;
	cout << "[E]xamine self, [C]ontinue, [B]uy from shop, [S]coreboard, [Q]uit\n> ";
	cin >> options;
	switch (options)
	{
	case'q': //quit the program
	case'Q':
		options = 'Q';
		break;
	case'E': //examine self
	case'e':
		cout << p1;
		break;
	case'S':
	case's':
		cout << p3;
		break;
	case'c':
	case'C':
		counter(level);
		break;
	case'b':
	case'B':
		cout << "Your current amount of gold is: " << p1.getC() << endl;
		cout << "Type the name of the weapon you would like to buy" << endl;
		datain2.open("weaponlist.txt");
		if (datain2.fail())
		{
			cerr << "Weaponlist.txt cannot be opened." << endl;
			//system("pause");
			exit(1);
		}
		int pop = 0; //to give each subheadings for each value
		string storeweaponname[5]; //store weapon names
		//string weaponowned[5]; //array to hold the weapons a player has bought
		int weaponcost[5] = {}; //storing weapon cost
		int countforweapon = 0; //using to count the array for weaponcost (above)
		string weaponop; //used for player selecting which weapon to buy
		char weaponoption; //to take the first character of the user input (otherwise many characters will be entered into the player options menu)
		while (datain2 >> weaponline)
		{
			if (pop == 0)
			{
				cout << weaponline << endl;
				storeweaponname[countforweapon] = weaponline;
				pop++;
			}
			else if (pop == 1)
			{
				cout << "Cost: " << weaponline << " gold" << endl;
				weaponcost[countforweapon] = stoi(weaponline);
				pop++;
			}
			else if (pop == 2)
			{
				cout << "Durability: " << weaponline << endl;  //not necessary (ricky)
				pop++;
			}
			else if (pop == 3)
			{
				cout << "Attack Damage: " << weaponline << endl;
				weapondmg[countforweapon] = stoi(weaponline);
				countforweapon++;
				pop = 0;
			}
		}

		datain2.close();
		cin >> weaponop;
		weaponoption = weaponop[0];
		switch (weaponoption)
		{
		case'd':
		case'D':
			if (p1.getC() >= weaponcost[0])
			{
				cout << "You bought a dagger!\n" << endl;
				p1.setC(p1.getC() - weaponcost[0]);
				weaponsowned.insert(weaponsowned.begin() + weaponnumber, storeweaponname[0]);
				weaponnumber++;
			}
			else
			{
				cout << "Funds not enough.\n" << endl;
			}
			break;
		case'S':
		case's':
			if (p1.getC() >= weaponcost[1])
			{
				cout << "You bought a sword!\n" << endl;
				p1.setC(p1.getC() - weaponcost[1]);
				weaponsowned.insert(weaponsowned.begin() + weaponnumber, storeweaponname[1]);
				weaponnumber++;
				//p1.setDMG(weapondmg[1]);
			}
			else
			{
				cout << "Funds not enough.\n" << endl;
			}
			break;
		case'b':
		case'B':
			if (p1.getC() >= weaponcost[2])
			{
				cout << "You bought a bow!\n" << endl;
				p1.setC(p1.getC() - weaponcost[2]);
				weaponsowned.insert(weaponsowned.begin() + weaponnumber, storeweaponname[2]);
				weaponnumber++;
				//p1.setDMG(weapondmg[2]);
			}
			else
			{
				cout << "Funds not enough.\n" << endl;
			}
			break;
		case'p':
		case'P':
			if (p1.getC() >= weaponcost[3])
			{
				cout << "You bought a pistol!\n" << endl;
				p1.setC(p1.getC() - weaponcost[3]);
				weaponsowned.insert(weaponsowned.begin() + weaponnumber, storeweaponname[3]);
				weaponnumber++;
				//p1.setDMG(weapondmg[3]);
			}
			else
			{
				cout << "Funds not enough.\n" << endl;
			}
			break;
		case'R':
		case'r':
			if (p1.getC() >= weaponcost[4])
			{
				cout << "You bought a rifle!\n" << endl;
				p1.setC(p1.getC() - weaponcost[4]);
				weaponsowned.insert(weaponsowned.begin() + weaponnumber, storeweaponname[4]);
				weaponnumber++;
				//p1.setDMG(weapondmg[4]);
			}
			else
			{
				cout << "Funds not enough.\n" << endl;
			}
			break;
		}
		break; //first switch
	}
	bool k = false;
	int sayonce = 0;
	while (options == 'C' || options == 'c')
	{
		if (level < 5 && sayonce == 0)
		{
			cout << "You enter Floor " << level << endl;
			cout << "A " << p2.getName() << " blocks your path.\n" << endl;
			sayonce++;
		}
		if (level < 5)
		{
			cout << "What would you like to do?\n" <<
				"[A]ttack\n" << "Examine [S]elf\n" << "Examine [E]nemy" << endl;
			cin >> battleoptions;
		}
		int cc = 0; //counts for while loop to print out available weapon options
		int pp = 0; //Option number user will select
		switch (counter(level))
		{
		case 1:
		case 2:
		case 3:
		case 4:
			switch (battleoptions)
			{
			case'a':
			case'A':
				cout << "What weapon would you like to use? (Type the option number)" << endl;
				cout << "Option 1: Fist (" << punchdamage << " damage)" << endl;
				cc = 0;
				while (cc != weaponnumber)
				{
					cout << "Option " << cc + 2 << ": " << weaponsowned[cc] << endl;
					cc++;
				}
				cin >> pp;
				k = false;
				while (k == false)
				{

					if (pp > cc + 2 || pp < 0)
					{
						cout << "That option is unavailable." << endl;
						break;
					}
					else if (pp == 1)
					{
						cout << "Punches were thrown with the fist!" << endl;
						p1.setDMG(punchdamage); //set damage for player
						p2.setHP(p2.getHP() - p1.getDMG());//deal damage towards enemy
						if (p2.getHP() <= 0) //check if enemy dead
						{
							cout << "Enemy perished!\n" << endl;
							p1.setC(p1.getC() + p2.getGold());
							p3.AddScore(p3.getScore() + (100 * level));
							level++;//if enemy dead, get gold and increase score
							p2.setDMG(p2.getDMG() + 6);
							p2.setMaxHP(p2.getMaxHP() + 10);
							p2.setHP(p2.getMaxHP());
							p2.setGold(p2.getGold() + (10 * level));
							p2.setLVL(p2.getLVL() + 1);
							p3.setFloor(p3.getFloor() + 1);
							sayonce = 0;
							goto LOOP;
							break;
						}
						else {
							cout << "The enemy attacks!" << endl;
							//p2.setDMG(p2.rngDMG());
							int p = p2.rngDMG();
							cout << "You take " << p << "!" << endl;
							p1.setHP(p1.getHP() - p);
						}
						if (p1.getHP() <= 0)
						{
							cout << "You died!\n" << "Game over" << endl;
							exit(0);
						}//if you dead, game over,
						//level up if alive
						// option after level ends to be able to go shop and stuff
						k = true;
					}
					else
					{
						cout << "You attacked with the " << weaponsowned[pp - 2] << "!" << endl;
						if (weaponsowned[pp - 2] == "Sword")
						{
							p1.setDMG(weapondmg[1]); //set damage for player
							weaponsowned[pp - 2].erase(); // weapon gets used up
							if (weaponnumber != pp - 2)
							{
								for (int orb = pp - 2; orb < weaponnumber - 1; orb++)
								{
									//string temp = weaponsowned[pp - 1];
									weaponsowned[orb] = weaponsowned[orb + 1];
								}
							}
							if (weaponnumber != 0)
							{
								weaponnumber--;
							}
						}
						else if (weaponsowned[pp - 2] == "Dagger")
						{
							p1.setDMG(weapondmg[0]); //set damage for player
							weaponsowned[pp - 2].erase(); // weapon gets used up
							if (weaponnumber != pp - 2)
							{
								for (int orb = pp - 2; orb < weaponnumber - 1; orb++)
								{
									//string temp = weaponsowned[pp - 1];
									weaponsowned[orb] = weaponsowned[orb + 1];
								}
							}
							if (weaponnumber != 0)
							{
								weaponnumber--;
							}
						}
						else if (weaponsowned[pp - 2] == "Bow")
						{
							p1.setDMG(weapondmg[2]); //set damage for player
							weaponsowned[pp - 2].erase(); // weapon gets used up
							if (weaponnumber != pp - 2)
							{
								for (int orb = pp - 2; orb < weaponnumber - 1; orb++)
								{
									//string temp = weaponsowned[pp - 1];
									weaponsowned[orb] = weaponsowned[orb + 1];
								}
							}
							if (weaponnumber != 0)
							{
								weaponnumber--;
							}
						}
						else if (weaponsowned[pp - 2] == "Pistol")
						{
							p1.setDMG(weapondmg[3]); //set damage for player
							weaponsowned[pp - 2].erase(); // weapon gets used up
							if (weaponnumber != pp - 2)
							{
								for (int orb = pp - 2; orb < weaponnumber - 1; orb++)
								{
									//string temp = weaponsowned[pp - 1];
									weaponsowned[orb] = weaponsowned[orb + 1];
								}
							}
							if (weaponnumber != 0)
							{
								weaponnumber--;
							}
						}
						else if (weaponsowned[pp - 2] == "Rifle")
						{
							p1.setDMG(weapondmg[4]); //set damage for player
							weaponsowned[pp - 2].erase(); // weapon gets used up
							if (weaponnumber != pp - 2)
							{
								for (int orb = pp - 2; orb < weaponnumber - 1; orb++)
								{
									//string temp = weaponsowned[pp - 1];
									weaponsowned[orb] = weaponsowned[orb + 1];
								}
							}
							if (weaponnumber != 0)
							{
								weaponnumber--;
							}
						}
						p2.setHP(p2.getHP() - p1.getDMG());//deal damage towards enemy
						if (p2.getHP() <= 0) //check if enemy dead
						{
							cout << "Enemy perished!\n" << endl;
							p1.setC(p1.getC() + p2.getGold());
							p3.AddScore(p3.getScore() + (100 * level));
							level++;//if enemy dead, get gold and increase score
							p2.setDMG(p2.getDMG() + 10);
							p2.setMaxHP(p2.getMaxHP() + 10);
							p2.setHP(p2.getMaxHP());
							p2.setGold(p2.getGold() + (10 * level));
							p2.setLVL(p2.getLVL() + 1);
							p3.setFloor(p3.getFloor() + 1);
							goto LOOP;
							break;
						}
						else {
							cout << "The enemy attacks!" << endl;
							//p2.setDMG(p2.rngDMG());
							int p = p2.rngDMG();
							cout << "You take " << p << "!" << endl;
							p1.setHP(p1.getHP() - p);
						}
						if (p1.getHP() <= 0)
						{
							cout << "You died!\n" << "Game over" << endl;
							exit(0);
						}//if you dead, game over,
						//level up if alive
						// option after level ends to be able to go shop and stuff
						k = true;
					}
				}

				break;
			case's':
			case'S':
				cout << p1;
				break;
			case 'e':
			case'E':
				cout << p2;
				break;
			default:
				cout << "Invalid option" << endl;
				break;
			}
			//level++;
			//system("pause");
			break;
		case 5:
			cout << "You win!" << endl;
			options = 'Q';
			//system("pause");
			break;
		}
	}
}
cout << "You win!" << endl;

datain.close();
dataout.close();
//system("pause");
return 0;
}



