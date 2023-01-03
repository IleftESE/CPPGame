#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class FileOperations
{
private:
	string SB_file_name;
	//holds the name of the scoreboard file (input from user)
	fstream SB_myFile;
	//opens the scoreboard file
	string P_file_name;
	//holds the name of the player file (input from user)
	fstream P_myFile;
	//opens the player file
public:
	void SavePlayer(string player1);
	//Function creates new player file and closes it if no existing file exists
	void SaveScoreboard(string scoreboard1);
	//Function creates new scoreboard file and closes it if no existing file exists
	void ChooseSB(string scoreboard1);
	//Function that asks the user to select the scoreboard file to use and opens it
	void ChooseP(string player1);
	//Function that asks the user to select the player file to use and opens it
	void CloseFile();
	//Function to close the files
	void ScoreRank();
	//Function to output scores from all the scoreboards

};
