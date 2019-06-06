#include "ticTacToe.h"
#include <string>
using namespace std;

int main() {
	int numPlayers = 0;
	cout << "Would you like a 1 or 2 player game? Please enter 1 or 2: ";
	cin >> numPlayers;
	while (numPlayers != 1 && numPlayers != 2) {
		cout << "Invalid number. Please try again: ";
		cin >> numPlayers;
	}

	Game* ttt = new TicTacToe(numPlayers);
	ttt->initializeGame();
}