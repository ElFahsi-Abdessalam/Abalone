#include "Player.h"


Player::Player(Color playerColor,PlayerStatus status):
    _status{status},_cmptscore{14},_playerColor{playerColor}{}


void Player::setPlayerStatus(PlayerStatus status){
    this->_status=status;
}
