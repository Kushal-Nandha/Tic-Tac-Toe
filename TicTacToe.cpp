#include <iostream>

using namespace std;

char board[3][3] = {{'1', '1', '3'}, { '4', '5', '6' }, {'7','8','9'}};

char current_marker;
int current_player;

void drawBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot)
{
    int row = slot/3;
    int col;
    if(slot %3==0){
        row = slot/3-1;
        col=2;
    }
    else col = slot%3-1;

    if(board[row][col]!= 'X' && board[row][col]!= 'O'){
            board[row][col]=current_marker;
            return true;
    }
    else
    return false;
}

int winner()
{
    for(int i=0;i<3;i++){
        //rows
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])return current_player;

        //column
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])return current_player;
    }
    if(board[0][0]==board[1][1] && board[1][1]== board[2][2])return current_player;
    if(board[0][2]==board[1][1] && board[1][1] == board[2][0])return current_player;

    return 0;
}

void swap_player_ans_marker()
{
    if(current_marker=='X')current_marker='O';
    else current_marker='X';

    if(current_player==1)current_player=2;
    else current_player=1;

}

void game()
{
    cout << "Player one, Choose your marker : ";
    char marker_p1;
    cin >> marker_p1;
    cout << endl;
    if(marker_p1=='X'){
        cout << "Player two, Your Marker is : O"<< endl;
    }else
    {
        cout << "Player two, Your Marker is : X"<< endl;
    }

    current_player=1;
    current_marker = marker_p1;

    cout << endl;
    drawBoard();
    cout << endl;

    int player_won;

    for(int i=0;i<9;i++){
        cout << "It's Player " << current_player << "'s turn. Enter your slot : ";
        int slot;
        cin >> slot;

        if(slot <1 || slot>9){
            cout << "That is ans invalid slot!";
            i--;
            continue;
        }

        if(!placeMarker(slot)){
                cout << "That slot is occupied! Try another slot!";
                i--;
                continue;
        }
        cout << endl;
        drawBoard();
        cout << endl;

        player_won = winner();
        if(player_won==1){cout << "Player one won! Congratulations!";break;}
        if(player_won==2){cout << "Player two won! Congratulations!";break;}

        swap_player_ans_marker();


    }

    if(player_won==0){"That is a tie game!";}

}



int main()
{
    game();


    return 0;
}
