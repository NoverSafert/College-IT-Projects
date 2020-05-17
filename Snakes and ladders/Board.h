#include <iostream> 
#include <string>
using namespace std;

class Board{
    public:
        Board();
        void printboard();
        char getBox(int);
    private:
        char board[30];

};

Board::Board(){
    for(int box = 0; box < 30; box++)
        board[box] = 'N';
        board[28] ='S';
        board[26] = 'L';
        board[22] = 'L';
        board[8] = 'L';
        board[7] = 'S';
        board[3] = 'S';

    /*board = "|30N  |","29S  |","28N  |","27L  |","26N  |","25N  |",
    "|24N  |","23N  |","22N  |","21N  |","20N  |","19N  |",
    "|18N  |","17N  |","16N  |","15N  |","14N  |","13N  |",
    "|12N  |","11N  |","10N  |","09L  |","08S  |","07N  |",
    "|06N  |","05N  |","04S  |","03N  |","02N  |","01N  |";*/
}


void Board::printboard(){
    int box = 0;
    for (int c = 0; c<5;c++){
        for (int r = 0; r<6; r++){
        cout <<  board[box];
        box++;
        }
    cout << "\n";
    }
}

char Board::getBox(int b){
    return board[b];
}