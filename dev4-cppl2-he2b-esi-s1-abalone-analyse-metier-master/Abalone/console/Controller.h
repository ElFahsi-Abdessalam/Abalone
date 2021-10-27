#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "View.h"
#include "Game.h"

/*!
 * \brief Controller
 * \file
 */

class Controller{

    View _view;
    Game _game;

public:

    /*!
    *Constructor of controller
    */
    Controller()=default;
    Controller(View view,Game game);
    /*!
      * \brief start start the game
      */
    void start();



};


#endif // CONTROLLER_H
