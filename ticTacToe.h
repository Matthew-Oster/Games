#pragma once

#include "game.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

class TicTacToe : public Game {
public:
	TicTacToe(const size_t& players = 1, const size_t& turn = 1) : Game(players, turn) {
		for (int i = 0; i < 9; i++) {
			board[i] = 0;
		}
		fullBoard = false;
		win = false;
	}

	void initializeGame() override final;
	void vsCPU();
	void vsPlayer();
	int checkWinner();
	void printBoard();
	
private:
	bool blockPlayerRow();
	bool completeCPURow();

	int board[9];
	char player1Char = 'X';
	char player2Char = 'O';
	bool fullBoard;
	int win;
};

void TicTacToe::initializeGame() {
	int playerChoice;
	cout << "Hello, Player " << playerTurn << "! Please choose whether you would like to be X or O."
		<< " Type 0 for X, or 1 for O: ";
	cin >> playerChoice;
	while (playerChoice != 0 && playerChoice != 1) {
		cout << "Invalid choice. Try again: ";
		cin >> playerChoice;
	}

	if (playerChoice == 1) { player1Char = 'O'; player2Char = 'X'; }

	cout << "The numbers on your numpad refer to the following positions on the board:\t\n\n\n";
	cout << "\t \t \t \t   \t | \t   \t | \t   \t \n";
	cout << "\t \t \t \t 1 \t | \t 2 \t | \t 3 \t \n";
	cout << "\t \t \t \t   \t | \t   \t | \t   \t \n";
	cout << "\t \t \t   ---------------------------------------------\n";
	cout << "\t \t \t \t   \t | \t   \t | \t   \t \n";
	cout << "\t \t \t \t 4 \t | \t 5 \t | \t 6 \t \n";
	cout << "\t \t \t \t   \t | \t   \t | \t   \t \n";
	cout << "\t \t \t   ---------------------------------------------\n";
	cout << "\t \t \t \t   \t | \t   \t | \t   \t \n";
	cout << "\t \t \t \t 7 \t | \t 8 \t | \t 9 \t \n";
	cout << "\t \t \t \t   \t | \t   \t | \t   \t \n";

	if (numPlayers == 1) vsCPU();
	else vsPlayer();

	printBoard();
	if (fullBoard == true && win == 0) cout << "Draw! Thanks for playing!";
	else if (win == 1) cout << "Player 1 wins! Thanks for playing!";
	else if (win == 2) cout << "Player 2 wins! Thanks for playing!";

	return;
}

void TicTacToe::printBoard() {
	cout << "\n \n";
	cout << "\t \t \t \t   \t | \t   \t | \t   \t \n";
	cout << "\t \t \t \t ";

	if (board[0] == 1) cout << player1Char;
	else if (board[0] == 2) cout << player2Char;

	cout << "\t | \t ";

	if (board[1] == 1) cout << player1Char;
	else if (board[1] == 2) cout << player2Char;

	cout << "\t | \t ";

	if (board[2] == 1) cout << player1Char;
	else if (board[2] == 2) cout << player2Char;

	cout << " \t \n";
	cout << "\t \t \t \t   \t | \t   \t | \t   \t \n";
	cout << "\t \t \t   ---------------------------------------------\n";
	cout << "\t \t \t \t   \t | \t   \t | \t   \t \n";
	cout << "\t \t \t \t ";

	if (board[3] == 1) cout << player1Char;
	else if (board[3] == 2) cout << player2Char;

	cout << "\t | \t ";

	if (board[4] == 1) cout << player1Char;
	else if (board[4] == 2) cout << player2Char;

	cout << "\t | \t ";

	if (board[5] == 1) cout << player1Char;
	else if (board[5] == 2) cout << player2Char;

	cout << " \t \n";
	cout << "\t \t \t \t   \t | \t   \t | \t   \t \n";
	cout << "\t \t \t   ---------------------------------------------\n";
	cout << "\t \t \t \t   \t | \t   \t | \t   \t \n";
	cout << "\t \t \t \t ";

	if (board[6] == 1) cout << player1Char;
	else if (board[6] == 2) cout << player2Char;

	cout << "\t | \t ";

	if (board[7] == 1) cout << player1Char;
	else if (board[7] == 2) cout << player2Char;

	cout << "\t | \t ";

	if (board[8] == 1) cout << player1Char;
	else if (board[8] == 2) cout << player2Char;

	cout << "\t \n";
	cout << "\t \t \t \t   \t | \t   \t | \t   \t \n";
}

bool TicTacToe::blockPlayerRow() {
	// if-else statements try to block player from getting 3 in a row
	//	Horizontal Rows
	if (board[0] == 1 && board[1] == 1 && board[2] == 0) { board[2] = 2; return true; }		//	XX-
	else if (board[1] == 1 && board[2] == 1 && board[0] == 0) { board[0] = 2; return true; } //	-XX
	else if (board[0] == 1 && board[2] == 1 && board[1] == 0) { board[1] = 2; return true; } //	X-X

	else if (board[3] == 1 && board[4] == 1 && board[5] == 0) { board[5] = 2; return true; } //	XX-
	else if (board[4] == 1 && board[5] == 1 && board[3] == 0) { board[3] = 2; return true; } //	-XX
	else if (board[3] == 1 && board[5] == 1 && board[4] == 0) { board[4] = 2; return true; }	//	X-X

	else if (board[6] == 1 && board[7] == 1 && board[8] == 0) { board[8] = 2; return true; } //	XX-
	else if (board[7] == 1 && board[8] == 1 && board[6] == 0) { board[6] = 2; return true; } //	-XX
	else if (board[6] == 1 && board[8] == 1 && board[7] == 0) { board[7] = 2; return true; } //	X-X

	//	Vertical Rows
	else if (board[0] == 1 && board[3] == 1 && board[6] == 0) { board[6] = 2; return true; }
	else if (board[3] == 1 && board[6] == 1 && board[0] == 0) { board[0] = 2; return true; }
	else if (board[0] == 1 && board[6] == 1 && board[3] == 0) { board[3] = 2; return true; }

	else if (board[1] == 1 && board[4] == 1 && board[7] == 0) { board[7] = 2; return true; }
	else if (board[4] == 1 && board[7] == 1 && board[1] == 0) { board[1] = 2; return true; }
	else if (board[1] == 1 && board[7] == 1 && board[4] == 0) { board[4] = 2; return true; }

	else if (board[2] == 1 && board[5] == 1 && board[8] == 0) { board[8] = 2; return true; }
	else if (board[5] == 1 && board[8] == 1 && board[2] == 0) { board[2] = 2; return true; }
	else if (board[2] == 1 && board[8] == 1 && board[5] == 0) { board[5] = 2; return true; }

	//	Diagonal Rows
	else if (board[0] == 1 && board[4] == 1 && board[8] == 0) { board[8] = 2; return true; }
	else if (board[4] == 1 && board[8] == 1 && board[0] == 0) { board[0] = 2; return true; }
	else if (board[0] == 1 && board[8] == 1 && board[4] == 0) { board[4] = 2; return true; }

	else if (board[2] == 1 && board[4] == 1 && board[6] == 0) { board[6] = 2; return true; }
	else if (board[4] == 1 && board[6] == 1 && board[2] == 0) { board[2] = 2; return true; }
	else if (board[2] == 1 && board[6] == 1 && board[4] == 0) { board[4] = 2; return true; }

	else return false;
}

bool TicTacToe::completeCPURow() {
	if (board[0] == 2 && board[1] == 2 && board[2] == 0) { board[2] = 2; return true; }		//	XX-
	else if (board[1] == 2 && board[2] == 2 && board[0] == 0) { board[0] = 2; return true; } //	-XX
	else if (board[0] == 2 && board[2] == 2 && board[1] == 0) { board[1] = 2; return true; } //	X-X

	else if (board[3] == 2 && board[4] == 2 && board[5] == 0) { board[5] = 2; return true; } //	XX-
	else if (board[4] == 2 && board[5] == 2 && board[3] == 0) { board[3] = 2; return true; } //	-XX
	else if (board[3] == 2 && board[5] == 2 && board[4] == 0) { board[4] = 2; return true; }	//	X-X

	else if (board[6] == 2 && board[7] == 2 && board[8] == 0) { board[8] = 2; return true; } //	XX-
	else if (board[7] == 2 && board[8] == 2 && board[6] == 0) { board[6] = 2; return true; } //	-XX
	else if (board[6] == 2 && board[8] == 2 && board[7] == 0) { board[7] = 2; return true; } //	X-X

	//	Vertical Rows
	else if (board[0] == 2 && board[3] == 2 && board[6] == 0) { board[6] = 2; return true; }
	else if (board[3] == 2 && board[6] == 2 && board[0] == 0) { board[0] = 2; return true; }
	else if (board[0] == 2 && board[6] == 2 && board[3] == 0) { board[3] = 2; return true; }

	else if (board[1] == 2 && board[4] == 2 && board[7] == 0) { board[7] = 2; return true; }
	else if (board[4] == 2 && board[7] == 2 && board[1] == 0) { board[1] = 2; return true; }
	else if (board[1] == 2 && board[7] == 2 && board[4] == 0) { board[4] = 2; return true; }

	else if (board[2] == 2 && board[5] == 2 && board[8] == 0) { board[8] = 2; return true; }
	else if (board[5] == 2 && board[8] == 2 && board[2] == 0) { board[2] = 2; return true; }
	else if (board[2] == 2 && board[8] == 2 && board[5] == 0) { board[5] = 2; return true; }

	//	Diagonal Rows
	else if (board[0] == 2 && board[4] == 2 && board[8] == 0) { board[8] = 2; return true; }
	else if (board[4] == 2 && board[8] == 2 && board[0] == 0) { board[0] = 2; return true; }
	else if (board[0] == 2 && board[8] == 2 && board[4] == 0) { board[4] = 2; return true; }

	else if (board[2] == 2 && board[4] == 2 && board[6] == 0) { board[6] = 2; return true; }
	else if (board[4] == 2 && board[6] == 2 && board[2] == 0) { board[2] = 2; return true; }
	else if (board[2] == 2 && board[6] == 2 && board[4] == 0) { board[4] = 2; return true; }

	else return false;
}

int TicTacToe::checkWinner() {
	if (board[0] == 1 && board[1] == 1 && board[2] == 1) return 1;
	else if (board[0] == 2 && board[1] == 2 && board[2] == 2) return 2;

	else if (board[3] == 1 && board[4] == 1 && board[5] == 1) return 1;
	else if (board[3] == 2 && board[4] == 2 && board[5] == 2) return 2;

	else if (board[6] == 1 && board[7] == 1 && board[8] == 1) return 1;
	else if (board[6] == 2 && board[7] == 2 && board[8] == 2) return 2;

	else if (board[0] == 1 && board[3] == 1 && board[6] == 1) return 1;
	else if (board[0] == 2 && board[3] == 2 && board[6] == 2) return 2;

	else if (board[1] == 1 && board[4] == 1 && board[7] == 1) return 1;
	else if (board[1] == 2 && board[4] == 2 && board[7] == 2) return 2;

	else if (board[2] == 1 && board[5] == 1 && board[8] == 1) return 1;
	else if (board[2] == 2 && board[5] == 2 && board[8] == 2) return 2;

	else if (board[0] == 1 && board[4] == 1 && board[8] == 1) return 1;
	else if (board[0] == 2 && board[4] == 2 && board[8] == 2) return 2;

	else if (board[2] == 1 && board[4] == 1 && board[6] == 1) return 1;
	else if (board[2] == 2 && board[4] == 2 && board[6] == 2) return 2;

	if (find(board, board + 9, 0) == board + 9) fullBoard = true;

	return 0;
}

void TicTacToe::vsPlayer() {
	int position;
	while (fullBoard == false && win == 0) {
		if (playerTurn == 1) {
			printBoard();
			cout << "Player 1's turn.\n";
			cout << "Enter position: ";
			cin >> position;
			while (position < 1 || position > 9 || board[position - 1] != 0) {
				cout << "Invalid position. Try again: ";
				cin >> position;
			}
			board[position - 1] = playerTurn;
			++playerTurn;

			win = checkWinner();
			if (win != 0 || fullBoard == true) return;
		}
		else {
			printBoard();
			cout << "Player 2's turn.\n";
			cout << "Enter position: ";
			cin >> position;
			while (position < 1 || position > 9 || board[position - 1] != 0) {
				cout << "Invalid position. Try again: ";
				cin >> position;
			}
			board[position - 1] = playerTurn;
			--playerTurn;

			win = checkWinner();
			if (win != 0 || fullBoard == true) return;
		}
	}
}

//	Gameplay function for a match against the CPU. The CPU's first priority is completing a row to win the game.
//	If it can't complete a row this turn, it focuses on stopping the player from completing a row.
//	If neither CPU or player is about to complete a row, the CPU chooses a position randomly.
void TicTacToe::vsCPU() {
	int position;
	while (fullBoard == false && win == 0) {
		if (playerTurn == 1) {
			printBoard();
			cout << "Player's turn.\n";
			cout << "Enter position: ";
			cin >> position;
			while (position < 1 || position > 9 || board[position - 1] != 0) {
				cout << "Invalid position. Try again: ";
				cin >> position;
			}
			board[position - 1] = playerTurn;
			++playerTurn;

			win = checkWinner();
			if (win != 0 || fullBoard == true) return;
		}
		else {
			cout << "Computer's turn.\n";
			int chanceFactor;
			if (completeCPURow() == false) {	// try to complete a row
				if (blockPlayerRow() == false) {	// block player from completing a row
					do {
						chanceFactor = rand() % 8;
					} while (board[chanceFactor] != 0);
					board[chanceFactor] = 2;
				}
			}
			--playerTurn;

			win = checkWinner();
			if (win != 0 || fullBoard == true) return;
		}
	}
}