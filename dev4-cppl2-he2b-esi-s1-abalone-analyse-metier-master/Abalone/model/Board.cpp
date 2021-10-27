#include "Board.h"
#include "Direction.h"


bool Board::isInside(Position position){
    return !(Board::getCaseAtPosition(position).getColorCase()==OUTOFBOARD);
}

Case& Board::getCaseAtPosition(Position position){
    return this->board.at(position.getX()).at(position.getY());
}

bool  Board::checkMove(Position &oldPosition,Player player){
    return board[oldPosition.getX()][oldPosition.getY()].getColorCase()==Color::EMPTY ||board[oldPosition.getX()][oldPosition.getY()].getColorCase()==player.getPlayerColor();
}

void Board::marbleWhite (Position &position , int &i,int &j){
    if((i==1 &&(j>3 && j%2!=0 && j<15)) ||(i==2 &&( j>3 &&j%2==0 && j<15))|| (i==3 && (j>5 && j%2!=0 && j<13))){
        this->board[i][j] = Case(Color::WHITE,position);
    }
}
void Board::marbleBlack (Position &position , int &i,int &j){
    if((i==9 &&(j>3 && j%2!=0 && j<15)) ||(i==8 &&( j>3 &&j%2==0 && j<15))|| (i==7 && (j>5 && j%2!=0 && j<13))){
        this->board[i][j] = Case(Color::BLACK,position);
    }
}

Board::Board(){
    this->board = std::vector<std::vector<Case>>(12,std::vector<Case>(19));
    int depart =5;
    int arrive=13;
    for(int i =0;i<=11;i++){
        for(int j =0;j<=18;j++){
            Position position(i,j);
            this->board[i][j] = Case(Color::OUTOFBOARD,position);
            if(i!=0 &&i<=5){
                if(j<depart || j>arrive){
                    this->board[i][j] = Case(Color::OUTOFBOARD,position);
                }
                if(j>=depart && j<=arrive){

                    if(i%2!=0 && j%2!=0){
                        this->board[i][j] = Case(Color::EMPTY,position);
                    }
                    if(i%2==0 &&j%2!=0){
                        this->board[i][j] = Case(Color::OUTOFBOARD,position);
                    }
                    if(i%2==0 &&j%2 ==0){
                        this->board[i][j] = Case(Color::EMPTY,position);
                    }
                }
            }
            if(i>5 && i<10){
                if(j<depart || j<arrive){
                    this->board[i][j] = Case(Color::OUTOFBOARD,position);
                }
                if(j>depart && j<arrive){

                    if(i%2!=0 && j%2!=0){
                        this->board[i][j] = Case(Color::EMPTY,position);
                    }
                    if(i%2==0 &&j%2!=0){
                        this->board[i][j] = Case(Color::OUTOFBOARD,position);
                    }

                    if(i%2==0 &&j%2 ==0){
                        this->board[i][j] = Case(Color::EMPTY,position);
                    }
                }
            }
            marbleBlack(position,i,j);
            marbleWhite(position,i,j);
        }
        if(i<5){
            depart--;
            arrive++;}
        if(i>5){
            depart++;
            arrive--;
        }
    }
}

