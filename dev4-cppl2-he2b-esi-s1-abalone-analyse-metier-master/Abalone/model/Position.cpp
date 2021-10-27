#include "Position.h"

Position::Position(int x,int y):
    _x{x},_y{y}{
    if(x+y+(-x-y)!= 0){

        //throw std::invalid_argument("The position doesn't exist");
    }
}
Position Position::getNext(Directions direction){
    return Position (this->_x+direction.first ,this->_y+ direction.second);
}

Position operator-(Position pos,Position pos2){
    return Position(pos.getX()-pos2.getX(),pos.getY()-pos2.getY());
}

Position operator+(Position pos,Position pos2){
    return Position(pos.getX()+ pos2.getX(),pos.getY()+pos2.getY());
}


bool operator==(Position pos,Position pos2){
    return ((pos.getX() == pos2.getX())&&(pos.getY() == pos2.getY()));
}


bool operator!=(Position pos,Position pos2){
    return ! (pos==pos2);
}
