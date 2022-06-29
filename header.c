//
// Created by Eli on 29/06/2022.
//

#include "header.h"


void printTicTacToeBoard(char board[3][3]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%c  ",board[i][j]);
        }
        printf("\n=======\n");
    }
}

void playTicTacToe(){
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int turn = 0;
    char player1 = 'X';
    char player2 = 'O';
    bool gameIsOn = true;
    while(gameIsOn && turn < 9) {
        printTicTacToeBoard(board);
        makeMove(board, player1, player2, turn);
        checkWin(board, turn, &gameIsOn);
        if(!gameIsOn)
            printWinner(turn);
        turn++;
    }
    printTicTacToeBoard(board);
    if(turn == 9){
        printf("Draw!\n");
    }
}

void makeMove(char board[][3], char p1, char p2, int turn){
    char playersInput;
    char currentPlayerChar;
    if(turn % 2 == 0){
        currentPlayerChar = 'X';
        printf("Player's 1 turn: ");
    }
    else{
        currentPlayerChar = 'O';
        printf("Player's 2 turn: ");
    }
    scanf("%c", &playersInput);
    getchar(); // flushes the \n
    while(isNotValid(board, playersInput)){
        printf("Invalid Input, try again: ");
        scanf("%c", &playersInput);
        getchar(); // flushes the \n
    }
    updateBoardWithChar(board, playersInput, currentPlayerChar);
}

bool isNotValid(char board[][3], char input){
    int row,col;
    if(input > '9' || input < '1')
        return true;
    else{
        row = (input - '1') / 3;
        col = (input - '1') % 3;
        if(board[row][col] == 'X' || board[row][col] == 'O')
            return true;
    }
    return false;
}

void updateBoardWithChar(char board[][3], char input, char sign){
    int row,col;
    row = (input - '1') / 3;
    col = (input - '1') % 3;
    board[row][col] = sign;
}

void checkWin(char board[][3], int turn, bool* gameIsOn){
    char signToCheck;
    if(turn%2==0)
        signToCheck = 'X';
    else
        signToCheck = 'O';

    checkRowsAndCols(board, signToCheck, gameIsOn);
    checkDiagonals(board, signToCheck, gameIsOn);
}

void checkRowsAndCols(char board[][3], char sign, bool* gameisOn){
    int i;
    for(i=0;i<3;i++){
        if(board[i][0] == sign && board[i][1] == sign && board[i][2] == sign){  // this checks the i-th row
            *gameisOn = false;
            break;
        }
        else if(board[0][i] == sign && board[1][i] == sign && board[2][i] == sign){ // this checks the i-th col
            *gameisOn = false;
            break;
        }
    }
}

void checkDiagonals(char board[][3], char sign, bool* gameIsOn){
    if(board[0][0] == sign && board[1][1] == sign && board[2][2] == sign)      // main diagonal
        *gameIsOn = false;

    if(board[0][2] == sign && board[1][1] == sign && board[2][0] == sign)     // secondary diagonal
        *gameIsOn - false;
}

void printWinner(int turn){
    if(turn%2==0)
        printf("Player 1 won!\n");
    else
        printf("Player 2 won!\n");
}