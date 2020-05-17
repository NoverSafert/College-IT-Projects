#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
#include "dice.h"
using namespace std;

class MyGame{
    public:
        void start();
        int turn(Player, Board);
        char checkContPlaying(char);
};

void MyGame::start(){

    Board board;
    Player player1(1);
    Player player2(2);
    char contPlaying;
    int box;
    cout << "Press \"C\" to continue next turn or \"E\" to end the game\n";
    cin >> contPlaying;
    contPlaying = toupper(contPlaying);
    contPlaying = checkContPlaying(contPlaying);
        while (contPlaying != 'E' && player1.getPosition() < 29 && player2.getPosition() < 29){
            box = turn(player1, board);
            player1.setFinalPos(box);
            //cout << "Position:" <<player1.getPosition()<< "\n"; //Debugging
            player1.setTurn();
            if (player1.getPosition() >= 29){
                break;
            }
            else {
                cin >> contPlaying;
                contPlaying = toupper(contPlaying);
                contPlaying = checkContPlaying(contPlaying);
                if(contPlaying == 'C' && player1.getPosition() < 29){
                    box = turn(player2, board);
                    player2.setFinalPos(box);
                    //cout << "Position:" <<player2.getPosition()<< "\n"; //debugging
                    player2.setTurn();
                    if (player2.getPosition() >= 29){
                        break;
                    }
                    else {
                    cin >> contPlaying;
                    contPlaying = toupper(contPlaying);
                    contPlaying = checkContPlaying(contPlaying);
                    }
                }
            }
        }
    cout << "--Game Over--\n";
    if (player1.getPosition() >= 29){
        cout << "Player 1 is the winner!!!\n";
    }
    else{
        cout << "Player 2 is the winner!!!\n";
    }
    cout << "Thanks for playing!!!";
}

char MyGame::checkContPlaying(char cont){
    while (cont != 'C' && cont != 'E'){
        cout << "Invalid option, please press \"C\" to continue next turn or \"E\" to end the game\n";
        cin >> cont;
        cont = toupper(cont);
    }
    return cont;
}

int MyGame::turn(Player p, Board b){
    dice Dice;
    int roll;
    int nbox;
    char box;
    int newBox;
    roll = Dice.roll();
    cout << "Player " << p.getName() << "\nTurn: " <<p.getTurn() << "\n";
    cout << "Position:" <<p.getPosition() + 1;
    cout << " Roll: " << roll <<"\n";
    p.setRoll(roll);
    nbox = roll + p.getPosition();
    box = b.getBox(nbox);
    p.setBoxValue(box);
    //cout << nbox << box; // debugging
    p.setMove();
    p.setPosition();
    cout << "Final position:" <<p.getPosition() + 1<< "\n"; 
    return p.getPosition();
}

int main(){
    MyGame g;
    g.start();
    return 0;
}