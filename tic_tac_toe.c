#include <stdio.h>

int move(int player);

char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
int x_moves[9] = {0,0,0,0,0,0,0,0,0};
int o_moves[9] = {0,0,0,0,0,0,0,0,0};
int player = 0;
int win;

void display() {
    printf("        |       |       \n");
    printf("   %c    |   %c   |   %c   \n",board[0],board[1],board[2]);
    printf("________|_______|_______\n");
    printf("        |       |       \n");
    printf("   %c    |   %c   |   %c   \n",board[3],board[4],board[5]);
    printf("________|_______|_______\n");
    printf("        |       |        \n");
    printf("   %c    |   %c   |   %c   \n",board[6],board[7],board[8]);
    printf("        |       |       \n");
}  


void check_legal(int sq) {
    if (x_moves[sq-1] == 1 || o_moves[sq-1] == 1) {
        printf("Illegal move\nTry again");
        move(player);
    }
}

int move(int player) {
    int place;
    printf("\n\n");
    printf("Choose a square from 1 to 9 : ");
    scanf("%d",&place);
    check_legal(place);
    if (player == 0) {
        o_moves[place-1] = 1;
        board[place-1] = 'o';
    }
    else {
        x_moves[place-1] = 1;
        board[place-1] = 'x';
    }
}


int check_win() {
    if ((board[0] == 'x' && board[1] == 'x' && board[2] == 'x')
    || (board[0] == 'x' && board[3] == 'x' && board[6] == 'x')
    || (board[3] == 'x' && board[4] == 'x' && board[5] == 'x')
    || (board[6] == 'x' && board[7] == 'x' && board[8] == 'x')
    || (board[1] == 'x' && board[4] == 'x' && board[7] == 'x')
    || (board[2] == 'x' && board[5] == 'x' && board[8] == 'x')
    || (board[0] == 'x' && board[4] == 'x' && board[8] == 'x')) {
        return 1;
        win = 0;
    }
    else if ((board[0] == 'o' && board[1] == 'o' && board[2] == 'o')
    || (board[0] == 'o' && board[3] == 'o' && board[6] == 'o')
    || (board[3] == 'o' && board[4] == 'o' && board[5] == 'o')
    || (board[6] == 'o' && board[7] == 'o' && board[8] == 'o')
    || (board[1] == 'o' && board[4] == 'o' && board[7] == 'o')
    || (board[2] == 'o' && board[5] == 'o' && board[8] == 'o')
    || (board[0] == 'o' && board[4] == 'o' && board[8] == 'o')) {
        return 1;
        win = 1;
    }
    else
        return 0;
    
}

int main() {
    int count = 0;

    while(1) {
        count += 1;
        printf("\n\n");
        display();
        player = (player == 1 ? 0 : 1);
        move(player);
        if (check_win() == 1) {
            if (win == 1)
                printf("\n\nO won");
            else printf("\n\nX won");
            break;
        }
        if (check_win() == 0 && count == 9) {
            printf("\n\nDRAW");
            break;
        }
    }
    return 0;
}
