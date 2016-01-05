#include <time.h>
#include <string>
#include <iostream>
#include <algorithm>

#include "Game.h"
#include "GameField.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

using namespace std;

typedef struct Settings
{
	int firstPlayer;
	int fieldSize;
	int neededToWin;
}Settings;

void printSeparator()
{
	cout << "----------------------------" << endl;
}

int safeIntCin(int from, int to)
{
	int number;

	while (!(cin >> number) || number < from || number > to) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "Invalid input. Please type a number between " << from << " and " << to << ": ";
	}

	return number;
}

int menu(Settings* settings)
{
	int choice = 0;
	do
	{
		choice = 0;
		cout << endl;
		cout << "Choose an item: " << endl;
		printSeparator();
		cout << "1. Set starting player" << endl;
		cout << "2. Set field size" << endl;
		cout << "3. Set needed to win" << endl;
		printSeparator();
		if (settings->firstPlayer == 1)
		{
			cout << "4. Start game (you start, field size = " << settings->fieldSize;
			cout << ", needed to win = " << settings->neededToWin << ")" << endl;
		}
		else
		{
			cout << "4. Start game (AI starts, field size = " << settings->fieldSize;
			cout << ", needed to win = " << settings->neededToWin << ")" << endl;
		}
		printSeparator();
		cout << "0. Quit" << endl;
		printSeparator();
		cout << "Your choice: ";
		choice = safeIntCin(0, 4);

		switch (choice)
		{
		case 1:
			cout << "Who will start? (1 - You, 2 - CPU):";
			settings->firstPlayer = safeIntCin(1, 2);
			break;
		case 2:
			cout << "Choose a field size (2 - 100): ";			
			settings->fieldSize = safeIntCin(2, 100);
			break;
		case 3:
			cout << "Choose how many to win (2 - field size): ";
			settings->neededToWin = safeIntCin(2, settings->fieldSize);
			break;
		}

	} while (choice != 0 && choice != 4);

	cout << endl;

	return choice;
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	//get human player name
	Settings settings = { 1, 3, 3 };

	string humanPlayerName("");
	cout << "Please enter your name: ";
	cin >> humanPlayerName;
	cout << "Hello " << humanPlayerName << "!!!" << endl;

	HumanPlayer player1(humanPlayerName, GameField::M_CROSS_CHAR);
	AIPlayer player2("AI", GameField::M_CIRCLE_CHAR);

	char c = 'm';
	while (c != 'q' && c != 'Q')
	{
		if (c == 'm' && menu(&settings) == 0)
		{
			c = 'q';
			continue;
		}

		GameField gameField(settings.fieldSize, settings.neededToWin);

		if (settings.firstPlayer == 1)
		{
			Game game(gameField, &player1, &player2);
			game.play();
		}
		else
		{
			Game game(gameField, &player2, &player1);
			game.play();
		}

		cout << endl;
		cout << "Press q/Q to quit." << endl;
		cout << "Press m/M to go to the menu." << endl;
		cout << "Any other key to play a new game. (Confirm with enter) ";
		cin >> c;
		cin.clear();
	}

	return 0;
}