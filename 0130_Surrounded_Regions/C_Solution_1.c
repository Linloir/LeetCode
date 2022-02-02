//C Solution (1) to Leetcode.130
#include <stdio.h>
#include <stdlib.h>

void paint(char** board, int r, int rSize, int c, int* cSize){
    if(r < 0 || c < 0 || r >= rSize || c >= cSize[r]){
        return;
    }
    if(board[r][c] == 'X' || board[r][c] == 'M'){
        return;
    }
    board[r][c] = 'M';  //Marked true
    //Paint upper
    paint(board, r - 1, rSize, c, cSize);
    //Paint righter
    paint(board, r, rSize, c + 1, cSize);
    //Paint lower
    paint(board, r + 1, rSize, c, cSize);
    //Paint left
    paint(board, r, rSize, c - 1, cSize);
}

void solve(char** board, int boardSize, int* boardColSize){
    for(int i = 0; i < boardSize; i++){
        paint(board, i, boardSize, 0, boardColSize);
        paint(board, i, boardSize, boardColSize[i] - 1, boardColSize);
    }
    for(int i = 1; i < boardColSize[0] - 1; i++){
        paint(board, 0, boardSize, i, boardColSize);
    }
    for(int i = 1; i < boardColSize[boardSize - 1] - 1; i++){
        paint(board, boardSize - 1, boardSize, i, boardColSize);
    }
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardColSize[i]; j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
            else if(board[i][j] == 'M'){
                board[i][j] = 'O';
            }
        }
    }
}