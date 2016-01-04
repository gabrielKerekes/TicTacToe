#pragma once
#include "GameField.h"
#include "Player.h"
#include "Point.h"
#include "MinMax.h"

class Game
{
public:
	Game();
	Game(GameField gameField, Player *player1, Player *player2);
	~Game();
	
	Player getPlayerWithId(int id) const;

	GameField getGameField() const;
	void setGameField(GameField gameField);

	int getWinnerId() const;
	void setWinnerId(int winnerId);

	void play();
	void handleFinish();

	int checkGameOver(Player player, Point lastMove) const;
	int checkWin(Player player, Point lastMove) const;

	static int CheckGameOver(const GameField &gameField, const Player &player, const Player &opponent);
	static bool CheckWin(const GameField &gameField, const Player &player);
private:
	GameField mGameField;
	Player *mPlayer1;
	Player *mPlayer2;
	int mNumOfRounds;
	int mWinnerId;
};

