#include "catch.hpp"
#include "Position.h"


TEST_CASE("Test of the position class")
{


    SECTION("Test of getNext UPRIGHT")
       {
           Position pos=Position(0,0);
           Position posNext=pos.getNext(Direction::UP_RIGHT);
           REQUIRE(posNext==Position(-1,1));


       }

    SECTION("Test of getNext UPLEFT")
       {
           Position pos=Position(0,0);
           Position posNext=pos.getNext(Direction::UP_LEFT);
           REQUIRE(posNext==Position(-1,-1));


       }


    SECTION("Test of getNext LEFT")
       {
           Position pos=Position(0,0);
           Position posNext=pos.getNext(Direction::LEFT);
           REQUIRE(posNext==Position(0,-1));


       }


    SECTION("Test of getNext RIGHT")
       {
           Position pos=Position(0,0);
           Position posNext=pos.getNext(Direction::RIGHT);
           REQUIRE(posNext==Position(0,1));


       }


    SECTION("Test of getNext downLeft")
       {
           Position pos=Position(0,0);
           Position posNext=pos.getNext(Direction::DOWN_LEFT);
           REQUIRE(posNext==Position(1,-1));


       }
    SECTION("Test of getNext dowlright")
       {
           Position pos=Position(0,0);
           Position posNext=pos.getNext(Direction::DOWN_RIGHT);
           REQUIRE(posNext==Position(1,1));


       }

}
