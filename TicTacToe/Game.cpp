#include "Game.h"

Game::Game()
{
}

Game::Game(GameField gameField, Player *player1, Player *player2)
{
	mGameField = gameField;
	mPlayer1 = player1;
	mPlayer2 = player2;

	mNumOfRounds = 0;
}

Game::~Game()
{
}

Player Game::getPlayerWithId(int id) const
{
	if (mPlayer1->getId() == id)
	{
		return *mPlayer1;
	}

	return *mPlayer2;
}

GameField Game::getGameField() const
{
	return mGameField;
}

void Game::setGameField(GameField gameField)
{
	mGameField = gameField;
}

int Game::getWinnerId() const
{
	return mWinnerId;
}

void Game::setWinnerId(int winnerId)
{
	mWinnerId = winnerId;
}

void Game::play()
{
	mWinnerId = -1;
	Point lastMove(-1, -1);

	while (mWinnerId == -1)
	{
		mGameField.print();

		lastMove = mPlayer1->move(mGameField, *mPlayer2);
		mGameField.setField(lastMove, mPlayer1->getSign());
		mWinnerId = checkGameOver(*mPlayer1, lastMove);

		if (mWinnerId > -1)
		{
			continue;
		}

		mGameField.print();

		lastMove = mPlayer2->move(mGameField, *mPlayer1);
		mGameField.setField(lastMove, mPlayer2->getSign());
		mWinnerId = checkGameOver(*mPlayer2, lastMove);
	}

	handleFinish();
}

void Game::handleFinish()
{
	//if tie
	if (mWinnerId == 0)
	{
		std::cout << std::endl << "*********************************" << std::endl;
		std::cout << "The game ended with a tie";
		std::cout << std::endl << "*********************************" << std::endl;
	}
	//if a winner exists
	else
	{
		Player winner = getPlayerWithId(mWinnerId);

		mGameField.print();

		std::cout << std::endl << "*********************************" << std::endl;
		std::cout << winner.getName() << " won !!";
		std::cout << std::endl << "*********************************" << std::endl;
	}
}

int Game::checkGameOver(Player player, Point lastMove) const
{
	int winnerId = -1;
	
	//only if more than 2*neededToWin-1 moves have been player, otherwise noone
	//could've won
	if (mGameField.getNumOfFilled() >= 2 * mGameField.getNeededToWin() - 1)
	{
		winnerId = checkWin(player, lastMove);
	}
	else
	{
		return winnerId;
	}

	//if is tie
	if (winnerId == -1 && mGameField.isFull())
	{
		winnerId = 0;
	}

	return winnerId;
}

int Game::checkWin(Player player, Point lastMove) const
{
	int fieldSize = mGameField.getSize();
	int neededToWin = mGameField.getNeededToWin();

	int consecutiveRow = 0;
	int consecutiveColumn = 0;
	int consecutiveDiagonal1 = 0;
	int consecutiveDiagonal2 = 0;

	for (int i = 0 - neededToWin + 1; i < neededToWin; i++)
	{
		//check row
		mGameField.getField(lastMove.getY() + i, lastMove.getX()) == player.getSign() ?
			consecutiveRow++ : consecutiveRow = 0;
		//check column
		mGameField.getField(lastMove.getY(), lastMove.getX() + i) == player.getSign() ?
			consecutiveColumn++ : consecutiveColumn = 0;
		//check diagonal 1
		mGameField.getField(lastMove.getY() + i, lastMove.getX() + i) == player.getSign() ?
			consecutiveDiagonal1++ : consecutiveDiagonal1 = 0;
		//check diagonal 2
		mGameField.getField(lastMove.getY() - i, lastMove.getX() + i) == player.getSign() ?
			consecutiveDiagonal2++ : consecutiveDiagonal2 = 0;

		if (consecutiveRow == neededToWin || consecutiveColumn == neededToWin
			|| consecutiveDiagonal1 == neededToWin || consecutiveDiagonal2 == neededToWin)
		{
			return player.getId();
		}
	}

	return -1;
}

int Game::CheckGameOver(const GameField &gameField, const Player &player, const Player &opponent)
{
	bool playerWin = false;
	bool opponentWin = false;
	
	//only if more than 2*neededToWin-1 moves have been player, otherwise noone
	//could've won
	if (gameField.getNumOfFilled() >= 2 * gameField.getNeededToWin() - 1)
	{
		playerWin = CheckWin(gameField, player);
		opponentWin = CheckWin(gameField, opponent);
	}
	else
	{
		return -1;
	}
	
	if (playerWin)
	{
		return player.getId();
	}
	else if (opponentWin)
	{
		return opponent.getId();
	}
	//if is tie
	else if (gameField.isFull())
	{
		return 0;
	}

	return -1;
}

bool Game::CheckWin(const GameField &gameField, const Player &player)
{
	int fieldSize = gameField.getSize();
	int neededToWin = gameField.getNeededToWin();
	
	Point lastMove = player.getLastMove();
	
	if (lastMove.getX() == -1 && lastMove.getY() == -1)
	{
		return false;
	}

	int consecutiveRow = 0;
	int consecutiveColumn = 0;
	int consecutiveDiagonal1 = 0;
	int consecutiveDiagonal2 = 0;

	for (int i = 0 - neededToWin + 1; i < neededToWin; i++)
	{
		//check row
		gameField.getField(lastMove.getY() + i, lastMove.getX()) == player.getSign() ?
			consecutiveRow++ : consecutiveRow = 0;
		//check column
		gameField.getField(lastMove.getY(), lastMove.getX() + i) == player.getSign() ?
			consecutiveColumn++ : consecutiveColumn = 0;
		//check diagonal 1
		gameField.getField(lastMove.getY() + i, lastMove.getX() + i) == player.getSign() ?
			consecutiveDiagonal1++ : consecutiveDiagonal1 = 0;
		//check diagonal 2
		gameField.getField(lastMove.getY() - i, lastMove.getX() + i) == player.getSign() ?
			consecutiveDiagonal2++ : consecutiveDiagonal2 = 0;


		if (consecutiveRow == neededToWin || consecutiveColumn == neededToWin
			|| consecutiveDiagonal1 == neededToWin || consecutiveDiagonal2 == neededToWin)
		{
			return true;
		}
	}

	return false;
}