#include <iostream>
#include "Game.h"

void Game::printBoard() {
  /*
  Takes 2D array of integers and displays the board
  with some extra formatting for cosmetic purposes.
  */

  std::cout << "\033[2J\033[1;1H" << "\n\n";

  for (int i=0; i<6; i++) {
    for (int j=0; j<7; j++) {
      switch (board[i][j]) {
        case 0:
          std::cout << "[ ]";
          break;

        case 1:
          std::cout << "[x]";
          break;

        case 2:
          std::cout << "[+]";
          break;
      }
    }
    std::cout << std::endl;
  }
  std::cout << "=====================\n 1  2  3  4  5  6  7 \n=====================\n";
};

void Game::dropCoin(int player, int col) {
  /*
  Takes column number and 'drops' a coin down
  that column, where depending on the player will
  leave a 1 or 2.
  */

  int row = 0;
  while (row < 6) {
    if (board[row][col - 1] == 1 || board[row][col - 1] == 2) {
      board[row - 1][col - 1] = player;
      break;
    } else if (row==5 && board[row][col - 1] == 0) {
      board[row][col - 1] = player;
      break;
    } else {
      row ++;
    }
  }
};

/*
Next four methods are to check if there are any win conditions.
First check horizontal wins if any
Then Vertical
Then Diagonal (both ways)
Last method combines previous three to check entire board.
*/

bool Game::checkVertical(int player) {
  for (int col = 0; col < 7; ++col) {
        for (int row = 0; row < 3; ++row) {
            if (board[row][col] == player &&
                board[row + 1][col] == player &&
                board[row + 2][col] == player &&
                board[row + 3][col] == player) {
                return true;
            }
        }
    }
    return false;
};

bool Game::checkHorizontal(int player) {
  for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (board[row][col] == player &&
                board[row][col + 1] == player &&
                board[row][col + 2] == player &&
                board[row][col + 3] == player) {
                return true;
            }
        }
    }
    return false;
};

bool Game::checkDiagonal(int player) {
  for (int row = 3; row < 6; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (board[row][col] == player &&
                board[row - 1][col + 1] == player &&
                board[row - 2][col + 2] == player &&
                board[row - 3][col + 3] == player) {
                return true;
            }
        }
    }

  
  for (int row = 0; row < 3; ++row) {
      for (int col = 0; col < 4; ++col) {
          if (board[row][col] == player &&
              board[row + 1][col + 1] == player &&
              board[row + 2][col + 2] == player &&
              board[row + 3][col + 3] == player) {
              return true;
          }
      }
  }

  return false;
};

int Game::checkWin(int player) {
  return Game::checkVertical(player) || Game::checkHorizontal(player) || Game::checkDiagonal(player);
};