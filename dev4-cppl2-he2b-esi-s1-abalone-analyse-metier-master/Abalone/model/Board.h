#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "AbaPro.h"
#include "vector"
#include "Case.h"
#include "Position.h"
#include "Player.h"

/*!
 * \brief Board
 * \file
 */

class Board{

    std::vector<std::vector<Case>>board;

public:


public:


    /*!
     * Create the board of the game
     * \brief Board::Board
     */
    Board();
    /*!
      *
     * \brief Board::getCaseAtPosition
     * \param position on board
     * \return case
     */

    Case& getCaseAtPosition(Position position);

    /*!
     * check the position is inside in the board
     * \brief Board::isInside
     * \param position position in board
     * \return true is the value isinside
     */

    bool isInside(Position position);

    /*!
     * \brief Board::marbleWhite create 14 marble black in the board
     * \param position position in the board
     * \param i row  of board
     * \param j column of board
     */
    void marbleBlack (Position &position , int &i,int &j);
    /*!
     * \brief Board::marbleBlack create 14 marble black in the board
     * \param position position in the board
     * \param i row  of board
     * \param j column of board
     */
    void marbleWhite (Position &position , int &i,int &j);

    /*!
     * move line in board
     * \brief Game::moveLine
     * \param pos1 old pos in the board
     * \param pos2 new position in the board
     * \param player player of the game
     */
    void moveLine(Position pos1,Position pos2, Player player);

    /*!
     * \brief Game::deductDirection
     * \param pos position on board
     * \return direction
     */
    Directions deductDirection(Position &);

    /*!
     * \brief Board::checkMove check if i can move in the board
     * \param oldPosition position of marble
     * \param player player of the game
     * \return boolean if i can move on the board
     */
    bool checkMove(Position &oldPosition,Player player);

};

#endif // BOARD_H


