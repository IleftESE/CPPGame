#include "scoreboard.h"
#include <string>
#include <iostream>

scoreboard::scoreboard()
{
    SB_Name = ' ';
    SB_Score = 0;
    SB_Difficulty = ' ';
    SB_Floor = 1;
}

string scoreboard::getName()
{
    return SB_Name;
}

int scoreboard::getScore()
{
    return SB_Score;
}

string scoreboard::getDiff()
{
    return SB_Difficulty;
}

int scoreboard::getDiffMod()
{
    return SB_DifficultyMod;
}

int scoreboard::getFloor()
{
    return SB_Floor; //floor
}

void scoreboard::setName(string name)
{
    SB_Name = name;
}

void scoreboard::setScore(int s)
{
    SB_Score = s; //the score
}

void scoreboard::setDiff(string d)
{
    SB_Difficulty = d;
}

void scoreboard::setDiffMod(int m)
{
    SB_DifficultyMod = m;
}

void scoreboard::setFloor(int f)
{
    SB_Floor = f;
}

void scoreboard::AddScore(int a) //how many points the player earn which will then be added back
{
    SB_Score = a + SB_Score; //the score plus the current score
}

void scoreboard::SB_out()
{
    cout << "Name: " << getName() << "\n" << "Difficulty: " << getDiff() << "\n" << "Score: " << getScore() << "\n" << "Floor: " << getFloor() << endl;
}


ostream& operator << (ostream& os, const scoreboard& s)
{
    os << "Player Name: " << s.SB_Name << "\n" << "Current Score: " << s.SB_Score << "\n" << "Difficulty: " << s.SB_Difficulty << "\n" << "Floor: " <<s.SB_Floor << endl;
    return os;
}