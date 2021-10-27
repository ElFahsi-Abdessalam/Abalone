#include "catch.hpp"
#include "Board.h"
TEST_CASE("Test of board class")
{

    SECTION(" Is not inside test ")
    {
        Board board=Board();
        Position pos=Position(0,0);
        REQUIRE(board.isInside(pos) ==false);
    }


    SECTION(" Is not inside test ")
    {
        Board board=Board();
        Position pos=Position(0,18);
        REQUIRE(board.isInside(pos) ==false);
    }

    SECTION(" Is not inside test ")
    {
        Board board=Board();
        Position pos=Position(11,0);
        REQUIRE(board.isInside(pos) ==false);
    }

    SECTION(" Is  not inside test ")
    {
        Board board=Board();
        Position pos=Position(11,18);
        REQUIRE(board.isInside(pos) ==false);
    }

    SECTION(" Is inside test ")
    {
        Board board=Board();
        Position pos=Position(1,5);
        REQUIRE(board.isInside(pos) ==true);
    }

    SECTION(" Is inside test ")
    {
        Board board=Board();
        Position pos=Position(7,9);
        REQUIRE(board.isInside(pos) ==true);
    }
    SECTION(" Is inside test ")
    {
        Board board=Board();
        Position pos=Position(5,17);
        REQUIRE(board.isInside(pos) ==true);
    }

    SECTION(" Is inside test ")
    {
        Board board=Board();
        Position pos=Position(3,7);
        REQUIRE(board.isInside(pos) ==true);
    }

    SECTION(" Is inside test ")
    {
        Board board=Board();
        Position pos=Position(4,8);
        REQUIRE(board.isInside(pos) ==true);
    }
}
