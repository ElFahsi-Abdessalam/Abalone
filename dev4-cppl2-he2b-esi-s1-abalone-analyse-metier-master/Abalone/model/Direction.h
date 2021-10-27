#ifndef DIRECTION_H
#define DIRECTION_H
#include <tuple>
/*!
 * \brief Direction
 * \file
 */

using Directions = std::pair<int, int>;

struct Direction
{
public:


    constexpr static const Directions UP_RIGHT{-1, 1};

    constexpr static const Directions UP_LEFT{-1, -1};

    constexpr static const Directions LEFT{0, -1};

    constexpr static const Directions RIGHT{0, 1};

    constexpr static const Directions DOWN_LEFT{1, -1};

    constexpr static const Directions DOWN_RIGHT{1, 1};

};



#endif // DIRECTION_H
