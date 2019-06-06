#pragma once

class Game {
public:
	Game(const size_t& players = 1, const size_t turn = 1) : numPlayers(players), playerTurn(turn) {}
	virtual void initializeGame() = 0;
	void setNumPlayers(const size_t& players) { numPlayers = players; }
protected:
	size_t playerTurn;
	size_t numPlayers;
};