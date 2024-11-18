#include "coverChessboard.hpp"
#include <iostream>
#include <vector>

int main()
{
    int size = 1 << 2;
    vector<vector<int>> board(size, vector<int>(size, -1));

    int missingX = 0, missingY = 1;

    chessBoard(0, 0, missingX, missingY, size, board);

    for (vector<int> row : board) {
        for (int cell : row) {
            cout << cell << "\t";
        }
        cout << endl;
    }

    return 0;
}