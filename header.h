//
// Created by Eli on 29/06/2022.
//

#ifndef TICTACTOE_HEADER_H
#define TICTACTOE_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void playTicTacToe();
void printTicTacToeBoard(char board[3][3]);
void makeMove(char board[][3], char p1, char p2, int turn);
bool isNotValid(char board[][3], char input);
void updateBoardWithChar(char board[][3], char input, char sign);
void checkWin(char board[][3], int turn, bool* gameIsOn);
void checkRowsAndCols(char board[][3], char sign, bool* gameIsOn);
void checkDiagonals(char board[][3], char sign, bool* gameIsOn);
void printWinner(int turn);

#endif //TICTACTOE_HEADER_H
