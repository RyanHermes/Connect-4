/* ===========================================================================
COMP-1410 Assignment 2
By: Ryan Hermes
=========================================================================== */

#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// make_move(board, column, player) updates the board following a move
//   by the given player in the given column; returns false if the move
//   was illegal because the column was full
// requires: 0 <= column < 7
//           player is either 'X' or 'O'
bool make_move(char board[6][7], int column, char player){
    
    if(board[0][column-1] != ' '){

        printf("Illegal move, column full!\n");

        return false;
    }

    int n = 0;

    while(board[5-n][column-1]!= ' '){
        n++;
    }

    board[5-n][column-1] = player;
    
    return true;    
}

// check_win(board) returns true if the given player has 4 connected
//   pieces on the board
bool check_win(char board[6][7], char player){

    int count = 0;

// vertical check
 
    for(int col = 0; col < 7; col++){
        count = 0;
        for(int row = 0; row < 6; row++){
            
            if(board[row][col] == player){
                count++;
            }
        
            if(board[row][col] != player){
                count = 0;
            }

            if(count == 4){
                return true;
            }
        }
    }


    // horizontal check

    for(int row = 0; row < 6; row++){
        count = 0;
        for(int col = 0; col < 7; col++){
            
            if(board[row][col] == player){
                count++;
            }
        
            if(board[row][col] != player){
                count = 0;
            }

            if(count == 4){
                return true;
            }

        }
    }

// diagonal / check
    int c = 0;
    // first diagonal 
    while(c != 4){
        if(board[3-c][0+c] == player){
            count++;
        }

        if(board[3-c][0+c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // second diagonal
    c = 0;
    count = 0;
    while(c != 5){
        if(board[4-c][0+c] == player){
            count++;
        }

        if(board[4-c][0+c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // third diagonal
    c = 0;
    count = 0;
    while(c != 6){
        if(board[5-c][0+c] == player){
            count++;
        }

        if(board[5-c][0+c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // fourth diagonal
    c = 0;
    count = 0;
    while(c != 6){
        if(board[5-c][1+c] == player){
            count++;
        }

        if(board[5-c][1+c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // fith diagonal
    c = 0;
    count = 0;
    while(c != 5){
        if(board[5-c][2+c] == player){
            count++;
        }

        if(board[5-c][2+c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // sixth diagonal
    c = 0;
    count = 0;
    while(c != 4){
        if(board[5-c][3+c] == player){
            count++;
        }

        if(board[5-c][3+c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

// diagonal \ check
    // first diagonal
    c = 0;
    count = 0;
    while(c != 4){
        if(board[3-c][6-c] == player){
            count++;
        }

        if(board[3-c][6-c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // second diagonal
    c = 0;
    count = 0;
    while(c != 5){
        if(board[4-c][6-c] == player){
            count++;
        }

        if(board[4-c][6-c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // third diagonal
    c = 0;
    count = 0;
    while(c != 6){
        if(board[5-c][6-c] == player){
            count++;
        }

        if(board[5-c][6-c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // fourth diagonal
    c = 0;
    count = 0;
    while(c != 6){
        if(board[5-c][5-c] == player){
            count++;
        }

        if(board[5-c][5-c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    //fith diagonal
    c = 0;
    count = 0;
    while(c != 5){
        if(board[5-c][4-c] == player){
            count++;
        }

        if(board[5-c][4-c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    //sixth diagonal
    c = 0;
    count = 0;
    while(c != 4){
        if(board[5-c][3-c] == player){
            count++;
        }

        if(board[5-c][3-c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    return false;
}
// function to print board
void printBoard(char board[6][7]){

    int i;
    int j;

    printf("   1     2     3     4     5     6     7  \n");
    printf("|-----|-----|-----|-----|-----|-----|-----|\n");
        for (i = 0; i < 6; ++i) {
            if(i != 0){
                printf("|-----|-----|-----|-----|-----|-----|-----|\n");
            }
            
            for (j = 0; j < 7; ++j) {
                printf("|  %c  ", board[i][j]);
            }
            
            printf("|\n");
        }

    printf("|_____|_____|_____|_____|_____|_____|_____|");
}

int main(){

    char board1[6][7] = 
    
    {' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     'X','X','X','X',' ',' ',' ',};

    char board2[6][7] = 
    
    {' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ','X','X','X','X',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',};

    char board3[6][7] = 
    
    {' ',' ',' ','X','X','X','X',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',};

    char board4[6][7] = 
    
    {'X',' ',' ',' ',' ',' ',' ',
     ' ','X',' ',' ',' ',' ',' ',
     ' ',' ','X',' ',' ',' ',' ',
     ' ',' ',' ','X',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',};

    char board5[6][7] = 
    
    {' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ','X',
     ' ',' ',' ',' ',' ','X',' ',
     ' ',' ',' ',' ','X',' ',' ',
     ' ',' ',' ','X',' ',' ',' ',};

    char board6[6][7] = 
    
    {' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ','X',' ',' ',' ',
     ' ',' ',' ','X',' ',' ',' ',
     ' ',' ',' ','X',' ',' ',' ',
     ' ',' ',' ','X',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',};

     char board7[6][7] = 
    
    {' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ','X',' ',
     ' ',' ',' ',' ',' ','X',' ',
     ' ',' ',' ',' ',' ','X',' ',
     ' ',' ',' ',' ',' ','X',' ',
     ' ',' ',' ',' ',' ',' ',' ',};

     char board8[6][7] = 
    
    {' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ','X',' ',' ',
     ' ',' ',' ','X',' ',' ',' ',
     ' ',' ','X',' ',' ',' ',' ',
     ' ','X',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',};

    char board9[6][7] = 
    
    {' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ','X',' ',' ',' ',
     ' ',' ',' ',' ','X',' ',' ',
     ' ',' ',' ',' ',' ','X',' ',
     ' ',' ',' ',' ',' ',' ','X',};

    char board0[6][7] = 
    
    {' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',
     ' ',' ',' ',' ',' ',' ',' ',};

    char no_win[6][7] = 
    
    {'X','O','O','O','X','O','O',
     'X','O','X','X','O','X','X',
     'O','X','O','X','X','O','O',
     'O','X','X','O','O','X','X',
     'X','O','O','O','X','O','O',
     'X','O','X','X','X','O','X',};

    assert(check_win(board1, 'X') == true);
    assert(check_win(board2, 'X') == true);
    assert(check_win(board3, 'X') == true);
    assert(check_win(board4, 'X') == true);
    assert(check_win(board5, 'X') == true);
    assert(check_win(board6, 'X') == true);
    assert(check_win(board7, 'X') == true);
    assert(check_win(board8, 'X') == true);
    assert(check_win(board9, 'X') == true);
    assert(check_win(board0, 'X') == false);
    assert(check_win(board1, 'O') == false);
    assert(check_win(no_win, 'X') == false);
    assert(check_win(no_win, 'X') == false);

    printf("\nQ1 tests passed!\n\n");

    int end = 0;
    int n = 0;

    char player_1 = 'X';
    char player_2 = 'O';

    char board[6][7] = 
    
    {' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',};

    printf("Welcome to Connect 4!\n");
    printf("Player 1 = X\n");
    printf("Player 2 = O\n");

    
    while(end != 21){

        printBoard(board);
        printf("\nPlayer 1, Your Turn!\nPlease choose a column!(1-7)");
        
        if ((scanf("%d", &n) == 0) || (n < 1 || n > 7)){
            return 0;
        }
    
        while(make_move(board, n, player_1) == false){
            printf("Please choose a column!(1-7)");
            if ((scanf("%d", &n) == 0) || (n < 1 || n > 7)){
            return 0;
        }
        }

        if(check_win(board, player_1) == true){
            printBoard(board);
            printf("\nPLayer 1 is the winner!\n");

            return 0;
        }

        printBoard(board);
        printf("\nPlayer 2, Your Turn!\nPlease choose a column!(1-7)");
        if ((scanf("%d", &n) == 0) || (n < 1 || n > 7)){
            return 0;
        }
    
        while(make_move(board, n, player_2) == false){
            printf("Please choose a column!(1-7)");
            if ((scanf("%d", &n) == 0) || (n < 1 || n > 7)){
                return 0;
            }
        }
        
        if(check_win(board, player_2) == true){
            printBoard(board);
            printf("\nPlayer 2 is the winner!\n");

            return 0;
        }
        end++;
    }

    printBoard(board);
    printf("\nTie game!\n");

    return 0;
}
