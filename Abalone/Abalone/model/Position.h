#ifndef POSITION_H
#define POSITION_H

#include "Direction.h"

/*!
 * \brief Position
 * \file
 */
class Position{
    int _x;
    int _y;



public:
    /*!
     * \brief Position Constructor of position
     */
    Position(){};
    Position(int x,int y);
    /*!
     * \brief getX getter of x
     * \return int
     */
    inline int getX(){return _x;}

    inline int getY(){return _y;}
    /*!
     * \brief getNext next position on board
     * \param direction
     * \return the next position in the board
     */
    Position  getNext(Directions direction);
    /*!
     * \brief operator - redefinition of an operator
     * \return  Position
     */

};

/*!
 * \brief operator - redefinition of an operator
 * \return  Position
 */
Position operator- (Position pos,Position pos2);
/*!
 * \brief operator - redefinition of an operator
 * \return  Position
 */
Position operator+(Position pos,Position pos2);
/*!
 * \brief operator - redefinition of an operator
 * \return  Position
 */
bool operator==(Position pos,Position pos2);
/*!
 * \brief operator !- redefinition of an operator
 * \return  Position
 */
bool operator!=(Position pos,Position pos2);





#endif // POSITION_H
