#include <iostream>
using namespace std;

class Player{
    public:
        Player();
        Player(int);
        void setName(int);
        int getName();
        void setPosition();
        int getPosition();
        void setBoxValue(char);
        void setTurn();
        int getTurn();
        void setRoll(int);
        int getRoll();
        void setMove();
        void setFinalPos(int);


    private:
        int infoPlayer[6];
};

Player::Player(){
    infoPlayer[0] = 0; // player name 
    infoPlayer[1] = 0; // player position
    infoPlayer[2] = 1; // player turn 
    infoPlayer[3] = 0; // dice roll
    infoPlayer[4] = 0; // box value N = 0; L = 3; s = -3;
    infoPlayer[5] = 0; //final movement value
}

Player::Player(int n){
    infoPlayer[0] = n; // player name 
    infoPlayer[1] = 0; // player position
    infoPlayer[2] = 1; // player turn 
    infoPlayer[3] = 0; // dice roll
    infoPlayer[4] = 0; // box value N = 0; L = 3; s = -3;
    infoPlayer[5] = 0; //final movement value
}

void Player::setName(int n){
    infoPlayer[0] = n;
}

int Player::getName(){
    return infoPlayer[0];
}

void Player::setPosition(){
    infoPlayer[1] = infoPlayer[1]+infoPlayer[5];
}

int Player::getPosition(){
    return infoPlayer[1];
}

void Player::setTurn(){
    infoPlayer[2] = infoPlayer[2] + 1;
}

int Player::getTurn(){
    return infoPlayer[2];
}

void Player::setRoll(int r){
    infoPlayer[3] = r;
}

int Player::getRoll(){
    return infoPlayer[3];
}

void Player::setBoxValue(char box){
    if (box == 'N'){
        infoPlayer[4] = 0;
    }
    else if (box == 'L'){
        infoPlayer[4] = 3;
    }
    else{
        infoPlayer[4] = -3;
    }
}

void Player::setMove(){
    infoPlayer[5] = infoPlayer[3] + infoPlayer[4];
}

void Player::setFinalPos(int b){
    infoPlayer[1] = b;
}
