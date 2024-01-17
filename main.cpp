#include <iostream>
#include <string.h>
#include "Game.h"


int main () {
  Game cFour;

  int coin = 1;

  std::cout << "\033[2J\033[1;1H" << "Welcome to Connect Four!\n\nPlayer 1 = X\nPlayer 2 = +\n\nPlayer 1 starts, Press enter to start - Good luck!\n\n";

  char foo[] = "";
  std::cin.getline(foo, 1);

  while (true) {
    cFour.printBoard();

    if (cFour.checkWin(1)) {
      printf("Game over! Player 1 wins!\n");
      break;
    }

    if (cFour.checkWin(2)) {
      printf("Game over! Player 2 wins!\n");
      break;
    }

    std::cout << "Player " << coin << "'s turn\nInput the column you would like to drop a coin: ";
    char input[] = "";
    std::cin >> input;

    if (strcmp(input, "exit") == 0) {
      printf("exiting...");
      break;
    }

    int col = std::atoi(input);

    cFour.dropCoin(coin, col);

    if (coin == 1) {
      coin = 2;
    } else if (coin == 2) {
      coin = 1;
    }
  }

  return 0;
}
