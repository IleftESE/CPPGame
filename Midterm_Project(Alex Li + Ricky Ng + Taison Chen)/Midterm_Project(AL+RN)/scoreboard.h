#pragma once
#include <string>
using namespace std;

class scoreboard
{
private:
    string SB_Name;         //Name of the player
    int SB_Score;           //score of the player. Score should increase after the player defeats an enemy or through some custom method designed by you.
        //(*Note: Higher level enemies should give more points.)
    string SB_Difficulty;
    int SB_DifficultyMod;   //Difficulty of the game.
    int SB_Floor;           //keeps track of the area in the game the player is currently at
public:
    scoreboard();   //default constructor

    string getName(); //get the player name
    int getScore(); //get the score
    string getDiff();   //the name of difficulity
    int getDiffMod();   //should depend on the floor
    int getFloor();     // fl level

    void setName(string);
    void setScore(int);
    void setDiff(string d);
    void setDiffMod(int);
    void setFloor(int);
    void AddScore(int); //increase the getscore whenever an enemy is defeated
    void SB_out(); //outputs scoreboard to the player
    friend ostream& operator <<(ostream& os, const scoreboard& p);
};
