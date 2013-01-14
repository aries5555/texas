#ifndef HOLDEM_H
#define HOLDEM_H

#include <vector>
#include <deque>
#include <cassert>

#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "ComPlayer.h"
#include "HumanPlayer.h"
#include "Stage.h"

typedef unsigned money;
typedef unsigned player_num;

class Holdem {
public:
	const static player_num MIN_PLAYER = 2;
	const static player_num MAX_PLAYER = 9;
	Holdem();
	void run();
private:
	Deck deck;
	std::vector<Player*> playerList;
	std::vector<Player*> players;
	std::vector<Player*> brokePlayers;
	std::vector<Card> community;
	money pot;
	money sBlind;
	money bBlind;
	player_num numOfPlayers;
	player_num dealer;
	player_num humanPos;
	bool allowAllIn;
	unsigned roundNum;
	bool gotoShowDown; //when all but one players are all-in, skip betting

	void constructPlayers(const money budget);
	void startGame();
	std::vector<Player*> highestHands(std::vector<Player*> &competitors);
	void cleanUp();
	//functions below are console-only
	bool setParams(money &budget);
	bool preFlop();
	bool flop();
	bool turn();
	bool river();
	void showDown();
	bool betting(const Stage stage);
	void stageResult();
	void distributePot(std::deque< std::vector<Player*> > &ranks);
	void checkBroke();
	bool checkEarlyEnd();
	bool askContinue();
	void gameOver();
};

#endif