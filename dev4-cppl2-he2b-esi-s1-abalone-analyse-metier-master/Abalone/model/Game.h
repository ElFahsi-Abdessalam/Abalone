#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

/*!
 * \brief Game
 * \file
 */


class Game{

    Board _board;
    Player _player1;
    Player _player2;



public:
    /*!
     * \brief Game Constructor of game
     */
    Game();
    /*!
     * \brief getBoard getter of board
     * \return board
     */
    inline Board& getBoard();
    /*!
     * \brief getPlayer1 getter of first player
     * \returnplayer
     */
    inline Player getPlayer1();
    /*!
     * \brief getPlayer2 getteter of the second player
     * \return player
     */
    inline Player getPlayer2();
    /*!
     * \brief restartGame restart the game
     */
    void restartGame();//fait
    bool gameIsFinish();//fait
    /*!
     * \brief setWinner setter of the winner
     */
    void setWinner();//fait
    /*!
     *
     * \brief askPositionUser Ask positon on user
     * \param player player of the game
     * \return  string
     */
    std::string askPositionUser(Color player);//fait
    void playMove(std::vector<Position>);//a faire
    /*!
    * \brief move move a marble
    * \param position positon on boar
    */
    bool move(std::vector<Position> position,Player);//fait
    /*!
    * \brief moveLine move marble inline
    * \param pos1 position 1
    * \param pos2 pos2
    */
    bool moveLine(Position pos1,Position pos2,Player);
    /*!
    * \brief deductDirection gives a direction with  a position
    * \return direction
    */
    Directions deductDirection(Position &);//fait
    /*!
    * \brief moveLateral move lateral in board
    * \param pos1 position in board
    * \param pos2 position in board
    * \param pos3 position in board
    */
    bool moveLateral(Position pos1,Position,Position pos3,Color);
    /*!
    * \brief applyMove
    * \param group
    * \param direction
    */
    void applyMove(std::vector<Position>group,Directions direction,Player);
    /*!
    * \brief checkMove check i can move
    * \param oldPosition position on boarf
    * \return bool
    */
    bool checkMove(Position &oldPosition,Directions ); //mouv ligne
    /*!
    * \brief group
    * \param pos
    * \param player
    * \param direction
    * \return
    */
    std::vector<Position>group (Position pos,Directions direction,Color player);
    /*!
    * \brief otherGroup
    * \return a vector of position
    */
    std::vector<Position> otherGroup(Position ,Directions,Color);
    /*!
    * \brief setMove
    * \param group a vector of positions
    * \param otherGroup a vector of positions
    */
    bool setMove(std::vector<Position> group , std::vector<Position> otherGroup,Directions,Player);
    /*!
     * \brief marble
     * \param group a vector of position
     * \return a boolean
     */
    bool marble (std::vector<Position> &group,Player);

    /*!
     * \brief applyMoveOtherGroup
     * \param group a vector of positions
     * \param direction a direction
     * \param player a color of player
     */
    void applyMoveOtherGroup(std::vector<Position>group,Directions direction,Color player);
    /*!
     * \brief otherGroupLateral
     * \param pos a position
     * \param direction a direction
     * \return a vector of positions
     */
    std::vector<Position> otherGroupLateral(Position pos ,Position,Directions direction,Color);
    /*!
     * \brief setLateral
     * \param group1 a vector of positions
     * \param direction a direction
     * \param player the color of player
     * \return a boolean
     */
    bool setLateral (std::vector<Position> group1 ,Directions direction,Color player);


};

inline Board & Game::getBoard(){return _board;}
inline Player Game::getPlayer1(){return _player1;}
inline Player Game::getPlayer2(){return _player2;}


#endif // GAME_H
