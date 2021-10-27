#include "Controlleur.h"
#include "Direction.h"
#include "mainwindow.h"

Controlleur::Controlleur(MainWindow &mainWindows ,Game &game){
    this->_main=&mainWindows;

    this->_game=game;

}

void findPosition::start(std::string position)
{
std::cout<<position;
//
  //  while(!this->_game.gameIsFinish()){


 //       bool pl1 =false,pl2=false;
/*
        while (!pl1) {
            try {
                // position=  _main.findsPosition();
              //  aba=findPositionFromAbaPro(position);
               //pl1=_game.move(position,_game.getPlayer1());

            }  catch (std::exception &e) {
                std::cout<<e.what()<<std::endl;
                //this->.message("impossible move");
            }

        }
        while(!pl2){
            try {



            } catch (std::exception &e) {
                std::cout<<e.what()<<std::endl;
                //this->.message("impossible move");
            }
            //std::cout<<"Player "<<(this->_game.getPlayer1().getcmpt()==8 ?"O" : "X")<<" HAS WON !!!!!!!!!!"<<std::endl;
        }

    }*/

}

