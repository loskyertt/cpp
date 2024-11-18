#include "coverChessboard.hpp"

int tile = 0;

void chessBoard(int top, int left, int missingX, int missingY, int size, vector<vector<int>>& board)
{
    // 当前棋盘只有一个方格
    if (size == 1) {
        return;
    }

    // 增加三格板编号
    int t = tile++;

    // 子棋盘边长
    int subSize = size / 2;

    // 标记四个子棋盘的中心位置
    int centerX = top + subSize;
    int centerY = left + subSize;

    // 当值 L 形三格板
    // 左上子棋盘
    if (missingX < centerX && missingY < centerY) {
        chessBoard(top, left, missingX, missingY, subSize, board);
    } else {
        // 不在左上区域，则在左上区域右下角放置L型骨牌
        board[centerX - 1][centerY - 1] = t;
        chessBoard(top, left, centerX - 1, centerY - 1, subSize, board);
    }
    // 右上角子棋盘
    if (missingX < centerX && missingY >= centerY) {
        chessBoard(top, left + subSize, missingX, missingY, subSize, board);
    } else {
        // 不在右上区域，则在右上区域左下角放置L型骨牌
        board[centerX - 1][centerY] = t;
        chessBoard(top, left + subSize, centerX - 1, centerY, subSize, board);
    }
    // 左下子棋盘
    if (missingX >= centerX && missingY < centerY) {
        chessBoard(top + subSize, left, missingX, missingY, subSize, board);
    } else {
        // 不在左下区域，则在左下区域右上角放置L型骨牌
        board[centerX][centerY - 1] = t;
        chessBoard(top + subSize, left, centerX, centerY - 1, subSize, board);
    }
    // 右下子棋盘
    if (missingX >= centerX && missingY >= centerY) {
        chessBoard(top + subSize, left + subSize, missingX, missingY, subSize, board);
    } else {
        // 不在右下区域，则在右下区域左上角放置L型骨牌
        board[centerX][centerY] = t;
        chessBoard(top + subSize, left + subSize, centerX, centerY, subSize, board);
    }
}