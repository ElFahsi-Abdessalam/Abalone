#include <iostream>
#include "Game.h"
#include <string>



Game::Game():
    _board{Board()},_player1{Player(Color::BLACK,NEUTRAL)},_player2{Color::WHITE,NEUTRAL}{}

void Game::restartGame()
{
    _player1.setcmpt(14);
    _player2.setcmpt(14);

    _player1.setPlayerStatus(NEUTRAL);
    _player2.setPlayerStatus(NEUTRAL);

    _board=Board();
}


bool Game::move(std::vector<Position> position,Player player){
    if(_board.getCaseAtPosition(position.front()).getColorCase()!=player.getPlayerColor())
        throw std::invalid_argument("A wrong marble has been selected");

    if(position.size()==3){
        return moveLateral(position.at(0),position.at(1),position.at(2),player.getPlayerColor());
    }else{
        return moveLine(position.at(0),position.at(1),player);
    }
}
std::string Game::askPositionUser(Color player){

    std::string str;
    std::cout <<"Player "<<(player==WHITE?"O":"X")<< " enter the move"<<std::endl;
    std::cin>>str;

    return str;
}

bool Game::gameIsFinish()
{
    return _player1.getcmpt()<=8 || _player2.getcmpt()<=8;
}

void Game::setWinner()
{
    if(_player1.getcmpt()<=8){
        _player1.setPlayerStatus(LOOSER);
        _player2.setPlayerStatus(WINNER);
    } else {
        _player1.setPlayerStatus(WINNER);
        _player2.setPlayerStatus(LOOSER);
    }
}

Directions Game::deductDirection(Position &pos){

    Directions direction;

    if(pos.getX()<0&&pos.getY()>0){
        direction = Direction::UP_RIGHT;
    }else if (pos.getX()<0 && pos.getY()<0){
        direction = Direction::UP_LEFT;
    }else if(pos.getX()==0 && pos.getY()<0){
        direction = Direction::LEFT;
    }else if(pos.getX()==0 &&pos.getY()>0){
        direction = Direction::RIGHT;
    } else if(pos.getX()>0 &&pos.getY()<0){
        direction = Direction::DOWN_LEFT;
    }
    else if(pos.getX()>0&& pos.getY()>0){
        direction = Direction::DOWN_RIGHT;
    }
    return direction;

}


bool Game::moveLateral(Position pos1,Position pos2,Position pos3,Color player){

    auto pos = pos2 - pos1;

    auto direction = deductDirection(pos);
    auto position = pos3 - pos1;

    auto directions = deductDirection(position);
    if(pos1.getNext(directions)==pos3){

        auto group1=otherGroupLateral(pos1,pos2,direction,player);
        if(group1.size()>3)
            return false;


        auto otherGroup1 =otherGroup(pos1,direction,player);
        return setLateral(group1,directions,player);
    }else{
        std::cout<<("Position are not adjacent")<<std::endl;
        return false;

    }
}

bool Game::setLateral (std::vector<Position> group1 ,Directions direction,Color player){

    for (auto cases : group1) {
        Position position =cases.getNext(direction);
        if(_board.getCaseAtPosition(position).getColorCase()!=EMPTY){
            return false;
        }
    }

    for (auto caseSet : group1) {
        Position position =caseSet.getNext(direction);
        _board.getCaseAtPosition(caseSet).setColorCase(EMPTY);
        _board.getCaseAtPosition(position).setColorCase(player);
    }
    return true;
}



bool Game::moveLine(Position pos1,Position pos2,Player player){
    auto pos = pos2-pos1;
    auto direction = deductDirection(pos);
    if(pos1.getNext(direction) == pos2 || ((pos1.getX() == pos2.getX()) && (pos1.getNext(direction).getNext(direction) == pos2 )) ){

        auto group1= group(pos1,direction,player.getPlayerColor());

        Position  next ;
        if(direction.first ==0){
            next =group1.at(group1.size()-1).getNext(direction).getNext(direction);
        }else{
            next =group1.at(group1.size()-1).getNext(direction);
        }
        auto otherGroup1 = otherGroup(next,direction,player.getPlayerColor());

        if(direction.first!=0){
            if( group1.size()>3 ||(!_board.isInside(group1.back().getNext(direction)))){
                return false;
            }

        }else{
            if( group1.size()>3 ||(!_board.isInside(group1.back().getNext(direction).getNext(direction)))){
                return false;
            }

        }

        return setMove(group1,otherGroup1,direction,player);


    }else{
        std::cout<<"position are not adjacent"<<std::endl;
        return false;
    }
}


bool Game::setMove(std::vector<Position> group , std::vector<Position> otherGroup ,Directions direction,Player player){
    if(otherGroup.size()==0||group.size()>otherGroup.size()){
        applyMove(group,direction,player);
    }else{
        return false;
    }
    if((group.size()>otherGroup.size()) && otherGroup.size()!=0){
        applyMoveOtherGroup(otherGroup,direction,colorOpposite(player.getPlayerColor()));
    }
    return true;
}

bool Game::marble (std::vector<Position> &group,Player player){
    int verif=0;
    for(auto it =group.begin();it!=group.end();it++){

        if(_board.getCaseAtPosition(*it).getColorCase()==player.getPlayerColor()){

            verif++;
        }
    }
    return verif == static_cast<int>(group.size());

}


void Game::applyMoveOtherGroup(std::vector<Position>group,Directions direction,Color player){

    Position pos;
    if(direction.first==0){
        pos =group.at(group.size()-1).getNext(direction).getNext(direction);
    }else{
        pos =group.at(group.size()-1).getNext(direction);
    }

    if(group.size() == 2){
        if(_board.isInside(pos)){
            _board.getCaseAtPosition(group.front()).setColorCase(colorOpposite(player));
            _board.getCaseAtPosition(pos).setColorCase(player);
        }else{
            _board.getCaseAtPosition(pos).setColorCase(OUTOFBOARD);
            this->_player1.getPlayerColor()==player?_player1.remove():_player2.remove();

        }
    }else{
        if(_board.isInside(pos)){
            _board.getCaseAtPosition(group.front()).setColorCase(colorOpposite(player));
            _board.getCaseAtPosition(pos).setColorCase(player);
        }else{
            _board.getCaseAtPosition(pos).setColorCase(OUTOFBOARD);
            this->_player1.getPlayerColor()==player?_player1.remove():_player2.remove();
        }
    }
}


void Game::applyMove(std::vector<Position>group,Directions direction,Player players){

    for(auto it =group.rbegin();it !=group.rend();it++){
        auto position =*it;

        _board.getCaseAtPosition(position).setColorCase(EMPTY);
        Position pos2;
        if(direction.first == 0){
            pos2=position.getNext(direction).getNext(direction);
        }else{
            pos2 =position.getNext(direction);
        }
        if(_board.isInside(pos2)){
            _board.getCaseAtPosition(pos2).setColorCase(players.getPlayerColor());
        }else{
            players.remove();
        }
    }
}


std::vector<Position> Game::otherGroupLateral(Position pos ,Position pos2,Directions direction,Color player){
    auto position =pos;
    std::vector<Position> group;

    int i =0;
    if(pos.getX() ==pos2.getX()){
        while(_board.getCaseAtPosition(position).getColorCase()==player && position !=pos2.getNext(direction).getNext(direction)){
            group.push_back(position);
            position = position.getNext(direction).getNext(direction);

            i++;
        }
    }else{
        while(_board.getCaseAtPosition(position).getColorCase()==player && position !=pos2.getNext(direction)){
            group.push_back(position);
            position = position.getNext(direction);
            i++;
        }
    }
    return group;
}


std::vector<Position> Game::otherGroup(Position pos ,Directions direction,Color player){
    Position position= pos;
    std::vector<Position> group ;

    if(direction.first==0){
        while(_board.getCaseAtPosition(position).getColorCase()==colorOpposite(player)){
            group.push_back(position);
            position = position.getNext(direction).getNext(direction);
        }
    }else{
        while(_board.getCaseAtPosition(position).getColorCase()==colorOpposite(player)){
            group.push_back(position);
            position = position.getNext(direction);

        }
    }
    return group;
}

std::vector<Position> Game::group (Position pos,Directions direction,Color player){

    std::vector<Position> group ;
    Position p = pos;

    int i =0;

    if(direction.first==0){
        while (_board.getCaseAtPosition(p).getColorCase() == player){
            group.push_back(p);
            p = p.getNext(direction).getNext(direction);
            i++;
        }
    }else{
        while (_board.getCaseAtPosition(p).getColorCase() == player){
            group.push_back(p);
            p = p.getNext(direction);
            i++;
        }
    }
    return  group;
}

