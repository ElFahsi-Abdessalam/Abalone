#include "Controller.h"
#include "Direction.h"

Controller::Controller(View view,Game game){this->_view=view;this->_game=game;}
void Controller::start()
{

    while(!_game.gameIsFinish()){
        std::string position;
        std::vector<Position>aba;
        bool pl1 =false,pl2=false;

        while (!pl1) {
            try {
                _view.displayNbMarbles((_game.getPlayer1()));
                _view.displayNbMarbles(_game.getPlayer2());
                this->_view.displayBoard(_game.getBoard());
                position=_game.askPositionUser(_game.getPlayer1().getPlayerColor());
                aba=findPositionFromAbaPro(position);

                while(aba.empty()){
                    position=_game.askPositionUser(_game.getPlayer1().getPlayerColor());
                    aba=findPositionFromAbaPro(position);

                }
                pl1=_game.move(aba,_game.getPlayer1());
                while(!pl1){
                    position=_game.askPositionUser(_game.getPlayer1().getPlayerColor());
                    aba=findPositionFromAbaPro(position);
                    pl1=_game.move(aba,_game.getPlayer1());
                }
            }  catch (std::exception &e) {
                std::cout<<e.what()<<std::endl;
                this->_view.message("impossible move");
            }

        }
        while(!pl2){
            try {
                _view.displayNbMarbles((_game.getPlayer1()));
                _view.displayNbMarbles(_game.getPlayer2());
                this->_view.displayBoard(_game.getBoard());
                position=_game.askPositionUser(_game.getPlayer2().getPlayerColor());
                aba=findPositionFromAbaPro(position);

                while( aba.empty()){
                    position=_game.askPositionUser(_game.getPlayer2().getPlayerColor());
                    aba=findPositionFromAbaPro(position);

                }
                pl2=_game.move(aba,_game.getPlayer2());
                while(!pl2){
                    position=_game.askPositionUser(_game.getPlayer2().getPlayerColor());
                    aba=findPositionFromAbaPro(position);
                    pl2=_game.move(aba,_game.getPlayer2());
                }
            }  catch (std::exception &e) {
                std::cout<<e.what()<<std::endl;
                this->_view.message("impossible move");
            }
        }
    }
      std::cout<<"Player "<<(this->_game.getPlayer1().getcmpt()==8 ?"O" : "X")<<" HAS WON !!!!!!!!!!"<<std::endl;
}






