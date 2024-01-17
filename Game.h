class Game { 
  public:
    int board[6][7] = {0};

    void printBoard();
    void dropCoin(int player, int col);
    bool checkVertical(int player);
    bool checkHorizontal(int player);
    bool checkDiagonal(int player);
    int checkWin(int player);
};