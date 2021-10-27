#ifndef ABAPRO_H
#define ABAPRO_H
#include <string>
#include "Position.h"
#include <vector>
/*!
 * \brief The AbaPro class
 * \file
 */

class AbaPro{



public:


};

/*!
 * \brief findPositionFromAbaPro find a position in the board
 * \param abapro string of abaPro
 * \return vector of position
 */
std::vector<Position> findPositionFromAbaPro(std::string abapro);

/*!
* \brief checkCorrectLetters check if the letter is correct
* \param c char
* \return bool true if the letters is correct
*/
bool checkCorrectLetters(char c);
/*!
* \brief checkCorrectLetters check if the number is correct
* \param c char
* \return bool true if the letters is correct
*/
bool checkCorrectNumbers(char c);

/*!
 * \brief getXFromChar getter of z
 * \param c char
 * \return int
 */
int getXFromChar(char c);
/*!
 * \brief getYFromChar getter of y
 * \param c char
 * \return   int
 */
int getYFromChar(char c,char);

//conversion de laba à la case exacte de mn board
//pair(lettre,chiffre)
//     Y       Z




#endif // ABAPRO_H

