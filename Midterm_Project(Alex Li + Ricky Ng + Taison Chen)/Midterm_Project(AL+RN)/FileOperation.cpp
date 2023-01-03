#include "FileOperation.h"

void FileOperations::SavePlayer(string player1)
{
	ofstream dataout;
	dataout.open(player1);
	if (dataout.fail()) {
		cerr << "Player file can not be opened." << endl;
	}
	dataout.close();
}

void FileOperations::SaveScoreboard(string scoreboard1)
{
	ofstream dataout;
	dataout.open(scoreboard1);
	if (dataout.fail()) {
		cerr << "Scoreboard file can not be opened." << endl;
	}
	dataout.close();
}

void FileOperations::ChooseSB(string scoreboard1)
{
	SB_myFile.open(scoreboard1);

	if (SB_myFile.fail() || P_myFile.fail()) {
		cerr << "Unable to find the file." << endl;
	}
	else {
		cout << "Opened files." << endl;
	}
}

void FileOperations::ChooseP(string player1)
{
	P_myFile.open(player1);

	if (P_myFile.fail()) {
		cerr << "Unable to find the file." << endl;
	}
	else {
		cout << "Opened player file" << endl;
	}
}


void FileOperations::CloseFile()
{
	SB_myFile.close();
	P_myFile.close();

}