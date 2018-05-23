#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


using namespace std;

void printDefault(void);
int printActiveGrid(char grid[3][3],int coords,int player);
void checkStatus(char grid[3][3]);
int neuralMachine(char grid[3][3]);

int status = 1;
int game = 0;
char winner;
int main()
{
    srand(time(NULL));
    system("cls");
    char grid[3][3]={{'-','.','-'},{'.','-','.'},{'.','-','.'}};
    int number;
    cout<<"___________________________\n";
    cout<<"                           \n";
    cout<<"  Tick Tac Terminal (TTT)  \n";
    cout<<"___________________________\n";
    cout<<endl;
    cout<<"Can you win?\n\n\n";
    system("pause");
    system("cls");
    while(game == 0){

        printDefault();

            cout<<"Player(1): ";
            cin>>number;
            printActiveGrid(grid,number,1);
            while(status != 1){
                printDefault();
                cout<<"Try Again Player(1): ";
                cin>>number;
                printActiveGrid(grid,number,1);
            }

        if(game != 0){
            break;
        }
         printDefault();
         Sleep(1000);
         printActiveGrid(grid,neuralMachine(grid),2);
         while(status != 1){
                printDefault();
                cout<<"Try Again Player(2): ";
                Sleep(1000);
                printActiveGrid(grid,neuralMachine(grid),2);
            }
    }
    if(winner){
        cout<<"("<<winner<<") Wins!!"<<endl;
    }else{
        cout<<"\nGame over"<<endl;
    }
    system("pause");
}

void printDefault(){
    cout<<endl<<endl;
    cout<<"----- GRID GUIDE -----\n\n";
    int grid[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            cout<<"  "<<grid[row][col]<<"\t";
        }
        cout<<endl<<endl;
    }
    cout<<"----------------------\n";
}

int printActiveGrid(char grid[3][3],int coords,int player){
    system("cls");
    char choice;

    if(player == 1){
        choice = 'X';
        }else{
            choice = 'O';
        }

    if(coords == 1){
            if(grid[0][0]=='-'|| grid[0][0]=='.'){
                grid[0][0] = choice;
                status = 1;
            }else{
                cout<<"\ninvalid move!\n";
                status = 0;
            }
        }else if(coords == 2){
            if(grid[0][1]=='-'|| grid[0][1]=='.'){
                grid[0][1] = choice;
                status = 1;
            }else{
                cout<<"\ninvalid move!\n";
                status = 0;
            }
        }else if(coords == 3){
            if(grid[0][2]=='-'|| grid[0][2]=='.'){
                grid[0][2] = choice;
                status = 1;
            }else{
                cout<<"\ninvalid move!\n";
                status = 0;
            }
        }else if(coords == 4){
            if(grid[1][0]=='-'|| grid[1][0]=='.'){
                grid[1][0] = choice;
                status = 1;
            }else{
                cout<<"\ninvalid move!\n";
                status = 0;
            }
        }else if(coords == 5){
            if(grid[1][1]=='-'|| grid[1][1]=='.'){
                grid[1][1] = choice;
                status = 1;
            }else{
                cout<<"\ninvalid move!\n";
                status = 0;
            }
        }else if(coords == 6){
            if(grid[1][2]=='-'|| grid[1][2]=='.'){
                grid[1][2] = choice;
                status = 1;
            }else{
                cout<<"\ninvalid move!\n";
                status = 0;
            }
        }else if(coords == 7){
            if(grid[2][0]=='-'|| grid[2][0]=='.'){
                grid[2][0] = choice;
                status = 1;
            }else{
                cout<<"\ninvalid move!\n";
                status = 0;
            }
        }else if(coords == 8){
            if(grid[2][1]=='-'|| grid[2][1]=='.'){
                grid[2][1] = choice;
                status = 1;
            }else{
                cout<<"\ninvalid move!\n";
                status = 0;
            }
        }else{
        if(grid[2][2]=='-'|| grid[2][2]=='.'){
                grid[2][2] = choice;
                status = 1;
            }else{
                cout<<"\ninvalid move!\n";
                status = 0;
            };
    }
    checkStatus(grid);
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            cout<<""<<grid[row][col]<<"\t";
        }
        cout<<endl<<endl;
    }
}

int neuralMachine(char grid[3][3]){
    int choice;
    if(grid[0][0] == 'X' && grid[0][2] == 'X' && !(grid[0][1] == 'O') && !(grid[0][1] == 'X')){
        choice = 2;
    }else if(grid[0][1] == 'X' && grid[0][2] == 'X' && !(grid[0][0] == 'O') && !(grid[0][0] == 'X')){
        choice = 1;
    }else if(grid[0][0] == 'X' && grid[0][1] == 'X' && !(grid[0][2] == 'O') && !(grid[0][2] == 'X')){
        choice = 3;
    }else if(grid[0][0] == 'X' && grid[2][0] == 'X' && !(grid[1][0] == 'O') && !(grid[0][1] == 'X')){
        choice = 4;
    }else if(grid[1][1] == 'X' && grid[1][2] == 'X' && !(grid[1][0] == 'O') && !(grid[0][1] == 'X')){
        choice = 4;
    }else if(grid[2][2] == 'X' && grid[2][0] == 'X' && !(grid[2][1] == 'O') && !(grid[2][1] == 'X')){
        choice = 8;
    }else if(grid[0][1] == 'X' && grid[2][1] == 'X' && !(grid[1][1] == 'O') && !(grid[1][1] == 'X')){
        choice = 5;
    }else if(grid[0][0] == 'X' && grid[2][2] == 'X' && !(grid[1][1] == 'O') && !(grid[1][1] == 'X')){
        choice = 5;
    }else if(grid[2][2] == 'X' && grid[0][2] == 'X' && !(grid[1][2] == 'O') && !(grid[1][2] == 'X')){
        choice = 6;
    }else if(grid[0][2] == 'X' && grid[2][2] == 'X' && !(grid[1][2] == 'O') && !(grid[1][2] == 'X')){
        choice = 6;
    }else if(grid[0][0] == 'X' && grid[1][0] == 'X' && !(grid[2][0] == 'O') && !(grid[2][0] == 'X')){
        choice = 7;
    }else if(grid[0][2] == 'X' && grid[1][1] == 'X' && !(grid[2][0] == 'O') && !(grid[2][0] == 'X')){
        choice = 7;
    }else if(grid[2][1] == 'X' && grid[2][2] == 'X' && !(grid[2][0] == 'O') && !(grid[2][0] == 'X')){
        choice = 7;
    }else if(grid[2][0] == 'X' && grid[0][2] == 'X' && !(grid[1][1] == 'O') && !(grid[2][1] == 'X')){
        choice = 5;
    }else if(grid[0][0] == 'X' && grid[1][1] == 'X' && !(grid[2][2] == 'O') && !(grid[2][2] == 'X')){
        choice = 9;
    }else if(grid[0][2] == 'X' && grid[1][2] == 'X' && !(grid[2][2] == 'O') && !(grid[2][2] == 'X')){
        choice = 9;
    }else{
        choice = 1 + rand() % 9;
    }
    return choice;
}

void checkStatus(char grid[3][3]){
    
    if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
        game = 1;
        winner = grid[0][0];
    }else if(grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]){
        game = 1;
        winner = grid[0][0];
    }else if(grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]){
        game = 1;
        winner = grid[0][0];
    }else if(grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]){
        game = 1;
        winner = grid[0][1];
    }else if(grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]){
        game = 1;
        winner = grid[0][2];
    }else if(grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]){
        game = 1;
        winner = grid[1][0];
    }else if(grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]){
        game = 1;
        winner = grid[2][0];
    }else if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){
        game = 1;
        winner = grid[0][2];
    }else if((grid[0][0] == 'X' || grid[0][0] == 'O' )){
        if((grid[0][1] == 'X' || grid[0][1] == 'O' )){
           if((grid[0][2] == 'X' || grid[0][2] == 'O' )){
               if((grid[1][0] == 'X' || grid[1][0] == 'O' )){
                   if((grid[1][1] == 'X' || grid[1][1] == 'O' )){
                    if((grid[1][2] == 'X' || grid[1][2] == 'O' )){
                        if((grid[2][0] == 'X' || grid[2][0] == 'O' )){
                                if((grid[2][1] == 'X' || grid[2][1] == 'O' )){
                                    if((grid[2][2] == 'X' || grid[2][2] == 'O' )){
                                        game = 1;
                                    }
                                 }
                            }
                        }
                     }
                }
            } 
        }
    }
}

