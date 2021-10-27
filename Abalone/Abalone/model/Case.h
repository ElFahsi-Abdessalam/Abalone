#ifndef CASE_H
#define CASE_H

#include "AbaPro.h"
#include "Position.h"
#include "AbaPro.h"
#include "Color.h"
#include "string.h"
/*!
 * \brief Case
 * \file
 */

class Case{


    Color _colorCase;
    Position _position;
    inline Position getPosition();


public:
    /*!
     * \brief Case default constructor
     */
    Case(){};
    Case(Color const colorcase,Position position):_colorCase(colorcase),_position(position){
    }
    /*!
     * \brief getColorCase getter of case
     * \return Color
     */
    inline Color getColorCase();
    /*!
     * \brief setColorCase setter of color
     * \param color c
     */
    inline void setColorCase(Color color);


};

inline void Case::setColorCase(Color color){this->_colorCase = color;}
inline Color Case::getColorCase(){return _colorCase;}


inline Position Case::getPosition(){return _position;}



#endif // CASE_H
