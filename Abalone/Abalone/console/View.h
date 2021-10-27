#ifndef VIEW_H
#define VIEW_H
#include <string>
#include "Board.h"
/*!
 * \brief View
 * \file
 */

class View{
public:

    /*!
    * Constructor of viex
    */
    View()=default;

    /*!
     * \brief displayBoard display the board
     * \param board board of the game
     */
    void displayBoard(Board &board);

    /*!
     * \brief displayLimiteAndLetter display limite of the game
     */
    void displayLimiteAndLetter(int &,int &);
    /*!
     * \brief message print message
     */
    void message(std::string mess);
    /*!
     * \brief displayNbMarbles display the number of marbles that have the player
     * \param player the player
     */
    void displayNbMarbles(Player player);

};

#endif // VIEW_H
