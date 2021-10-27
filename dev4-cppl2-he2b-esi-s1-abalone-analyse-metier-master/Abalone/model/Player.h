#ifndef PLAYER_H
#define PLAYER_H

#include "Direction.h"
#include "PlayerStatus.h"
#include "Color.h"

/*!
 * \brief Player
 * \file
 */
class Player{

    PlayerStatus _status;
    int _cmptscore;
    Color _playerColor;


public:
    Player(Color playerColor,PlayerStatus status);
    /*!
      * \brief getcmpt getter of cmpt
      * \return  int
      */

    inline int getcmpt();
    /*!
      * \brief setcmpt setter of cmpt
      * \param cmpt
      */
    inline void setcmpt(int cmpt);
    /*!
      * \brief getPlayerColor getter of the color of player
      * \return color
      */
    inline Color getPlayerColor();
    /*!
      * \brief getPlayerStatus getter of status
      * \return status
      */
    inline PlayerStatus getPlayerStatus();
    /*!
      *
      * \brief setPlayerStatus setter of status
      * \param status
      */
    void setPlayerStatus(PlayerStatus status);
    /*!
      * \brief remove
      */
    inline void remove();
};

inline Color Player::getPlayerColor(){return _playerColor;}

int Player::getcmpt(){return _cmptscore;}

void Player::remove(){_cmptscore--;}

inline PlayerStatus Player::getPlayerStatus(){return _status;}

inline void Player::setcmpt(int cmpt){
    _cmptscore=cmpt;
}





#endif // PLAYER_H
