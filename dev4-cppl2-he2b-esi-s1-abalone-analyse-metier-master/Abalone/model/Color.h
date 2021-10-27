#ifndef COLOR_H
#define COLOR_H
/*!
 *\file
 * \brief The Color enum
 */
enum Color{WHITE=0,BLACK=1,EMPTY=2,OUTOFBOARD=3};
inline Color colorOpposite(Color color);
inline Color colorOpposite(Color color){
    return color ==BLACK ? WHITE :BLACK;
}

#endif // COLOR_H
