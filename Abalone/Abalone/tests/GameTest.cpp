#include "catch.hpp"
#include "Game.h"

TEST_CASE("Test of game class")
{


    SECTION(" Starting line move A1B1")
    {
        Game game =Game();
        Position position{9,5};
        Position pos2{8,6};
        Position pos3{7,7};
        Position pos4 {6,8};
        auto vector = std::vector<Position>{{9,5},{8,6}};
        game.move(vector,game.getPlayer1());
        REQUIRE(game.getBoard().getCaseAtPosition(position).getColorCase() == Color::EMPTY );
        REQUIRE(game.getBoard().getCaseAtPosition(pos2).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(pos3).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(pos4).getColorCase() == Color::BLACK );
    }


    SECTION(" Starting line move WHITE  ")
    {
        Game game =Game();
        Position position{3,7};
        Position pos2{4,8};
        auto vector =std::vector<Position>{{3,7},{4,8}};
        game.move(vector,game.getPlayer2());
        REQUIRE(game.getBoard().getCaseAtPosition(position).getColorCase() == Color::EMPTY );
        REQUIRE(game.getBoard().getCaseAtPosition(pos2).getColorCase() == Color::WHITE );
    }

    SECTION(" Starting line move  ")
    {
        Game game =Game();
        Position position{2,10};

        Position pos2{3,11};
        Position pos3{4,12};
        Position pos4{5,13};
        auto vector =std::vector<Position>{{2,10},{3,11}};;
        game.move(vector,game.getPlayer2());
        REQUIRE(game.getBoard().getCaseAtPosition(position).getColorCase() == Color::EMPTY );
        REQUIRE(game.getBoard().getCaseAtPosition(pos2).getColorCase() == Color::WHITE );
        REQUIRE(game.getBoard().getCaseAtPosition(pos3).getColorCase() == Color::WHITE );
        REQUIRE(game.getBoard().getCaseAtPosition(pos4).getColorCase() == Color::EMPTY );

    }
    SECTION(" Starting line 2vs1  ")
    {
        Game game =Game();
        Position position{7,7};
        Color color = Color::WHITE;
        game.getBoard().getCaseAtPosition(position).setColorCase(color);
        Position pos2{9,5};
        Position pos3{8,6};
        Position pos {6,8};
        auto vector =std::vector<Position>{{9,5},{8,6}};
        game.move(vector,game.getPlayer1());

        REQUIRE(game.getBoard().getCaseAtPosition(pos2).getColorCase() == Color::EMPTY );
        REQUIRE(game.getBoard().getCaseAtPosition(pos3).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(position).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(pos).getColorCase() == Color::WHITE );

    }


    SECTION(" Starting line move 3vs1  ")
    {
        Game game =Game();
        Position position{6,8};

        Color color = Color::WHITE;
        game.getBoard().getCaseAtPosition(position).setColorCase(color);

        Position pos {9,5};
        Position pos2 {8,6};
        Position pos3 {7,7};
        Position pos4{6,8};
        Position pos5{5,9};

        auto vector =std::vector<Position>{{9,5},{8,6}};//correct
        game.move(vector,game.getPlayer1());

        REQUIRE(game.getBoard().getCaseAtPosition(pos).getColorCase() == Color::EMPTY );
        REQUIRE(game.getBoard().getCaseAtPosition(pos2).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(pos3).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(pos4).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(pos5).getColorCase() == Color::WHITE );

    }
    SECTION(" Starting line move 3vs2  ")
    {
        Game game =Game();
        Position position{6,8};
        Position position2{5,9};

        Color color = Color::WHITE;
        game.getBoard().getCaseAtPosition(position).setColorCase(color);
        game.getBoard().getCaseAtPosition(position2).setColorCase(color);


        Position pos {9,5};
        Position pos2 {8,6};
        Position pos3 {7,7};
        Position pos4{6,8};
        Position pos5{5,9};
        Position pos6{4,10};

        auto vector =std::vector<Position>{{9,5},{8,6}};
        game.move(vector,game.getPlayer1());

        REQUIRE(game.getBoard().getCaseAtPosition(pos).getColorCase() == Color::EMPTY );
        REQUIRE(game.getBoard().getCaseAtPosition(pos2).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(pos3).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(pos4).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(pos5).getColorCase() == Color::WHITE );
        REQUIRE(game.getBoard().getCaseAtPosition(pos6).getColorCase() == Color::WHITE );

    }


    SECTION(" Starting line move 3 vs 3  ")
    {
        Game game =Game();
        Position position{8,10};
        Position position2{8,12};
        Position position3{8,14};


        Color color = Color::WHITE;
        game.getBoard().getCaseAtPosition(position).setColorCase(color);
        game.getBoard().getCaseAtPosition(position2).setColorCase(color);
        game.getBoard().getCaseAtPosition(position3).setColorCase(color);


        Position pos  {8,4};
        Position pos2 {8,6};
        Position pos3 {8,8};


        auto vector =std::vector<Position>{pos,pos2};//correct
        game.move(vector,game.getPlayer1());

        REQUIRE(game.getBoard().getCaseAtPosition(pos).getColorCase() == Color::BLACK ); //à voir
        REQUIRE(game.getBoard().getCaseAtPosition(pos2).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(pos3).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(position).getColorCase() == Color::WHITE );
        REQUIRE(game.getBoard().getCaseAtPosition(position2).getColorCase() == Color::WHITE );
        REQUIRE(game.getBoard().getCaseAtPosition(position3).getColorCase() == Color::WHITE );

    }

    SECTION(" ejected one marble black  ")
    {
        Game game =Game();
        Position position{6,12};
        Position position2{7,13};

        Color color = Color::WHITE;
        game.getBoard().getCaseAtPosition(position).setColorCase(color);
        game.getBoard().getCaseAtPosition(position2).setColorCase(color);


        Position position3{8,14};

        auto vector =std::vector<Position>{{6,12},{7,13}};//correct
        game.move(vector,game.getPlayer2());

        REQUIRE(game.getBoard().getCaseAtPosition(position).getColorCase() == Color::EMPTY );
        REQUIRE(game.getBoard().getCaseAtPosition(position2).getColorCase() == Color::WHITE );
        REQUIRE(game.getBoard().getCaseAtPosition(position3).getColorCase() == Color::WHITE );

    }

    SECTION(" move line horizontal  ")
    {
        Game game =Game();
        Position position{7,7};
        Position position2{7,9};

        Position position3{7,11};
        Position position4{7,13};
        Position position5{7,15};

        Color color = Color::WHITE;
        game.getBoard().getCaseAtPosition(position4).setColorCase(color);

        auto vector =std::vector<Position>{position,{7,9}};//correct
        game.move(vector,game.getPlayer1());

        REQUIRE(game.getBoard().getCaseAtPosition(position).getColorCase() == Color::EMPTY );
        REQUIRE(game.getBoard().getCaseAtPosition(position2).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(position3).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(position4).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(position5).getColorCase() == Color::WHITE );
    }


    SECTION(" move line horizontal 3vs 1  ")
    {
        Game game =Game();
        Position position{7,7};
        Position position2{7,9};

        Position position3{7,11};
        Position position4{7,13};
        Position position5{7,15};

        auto vector =std::vector<Position>{position,{7,9}};//correct
        game.move(vector,game.getPlayer1());

        REQUIRE(game.getBoard().getCaseAtPosition(position).getColorCase() == Color::EMPTY ); //à voir
        REQUIRE(game.getBoard().getCaseAtPosition(position2).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(position3).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(position4).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(position5).getColorCase() == Color::EMPTY ); //à voir
    }
    SECTION(" ejected two marble black  ")
    {
        Game game =Game();
        Position position{7,13};
        Position position2{6,14};
        Position position3 {5,15};
        Color color = Color::WHITE;
        game.getBoard().getCaseAtPosition(position).setColorCase(color);
        game.getBoard().getCaseAtPosition(position2).setColorCase(color);
        game.getBoard().getCaseAtPosition(position3).setColorCase(color);



        Position position4 {8,12};
        Position position5 {9,11};

        auto vector =std::vector<Position>{{5,15},{6,14}};//correct
        game.move(vector,game.getPlayer2());

        REQUIRE(game.getBoard().getCaseAtPosition(position3).getColorCase() == Color::EMPTY ); //à voir
        REQUIRE(game.getBoard().getCaseAtPosition(position2).getColorCase() == Color::WHITE );
        REQUIRE(game.getBoard().getCaseAtPosition(position).getColorCase() == Color::WHITE );
        REQUIRE(game.getBoard().getCaseAtPosition(position4).getColorCase() == Color::WHITE );
        REQUIRE(game.getBoard().getCaseAtPosition(position5).getColorCase() == Color::BLACK );
    }

    SECTION(" eject one marble black  ")
    {
        Game game =Game();
        Position position{6,12};
        Position position2{7,13};

        Color color = Color::WHITE;
        game.getBoard().getCaseAtPosition(position).setColorCase(color);
        game.getBoard().getCaseAtPosition(position2).setColorCase(color);


        Position position3{8,14};

        auto vector =std::vector<Position>{{6,12},{7,13}};//correct
        game.move(vector,game.getPlayer2());

        REQUIRE(game.getBoard().getCaseAtPosition(position).getColorCase() == Color::EMPTY ); //à voir
        REQUIRE(game.getBoard().getCaseAtPosition(position2).getColorCase() == Color::WHITE );
        REQUIRE(game.getBoard().getCaseAtPosition(position3).getColorCase() == Color::WHITE );

    }
    SECTION(" Starting lateral move")
    {
        Game game =Game();
        Position position{7,7};
        Position pos2{7,11};
        Position pos3{6,6};
        Position pos4 {7,9};
        Position pos5{6,8};
        Position pos6{6,10};
        auto vector = std::vector<Position>{position,pos2,pos3};//correct
        game.move(vector,game.getPlayer1());
        REQUIRE(game.getBoard().getCaseAtPosition(position).getColorCase() == Color::EMPTY ); //à voir
        REQUIRE(game.getBoard().getCaseAtPosition(pos2).getColorCase() == Color::EMPTY );
        REQUIRE(game.getBoard().getCaseAtPosition(pos4).getColorCase() == Color::EMPTY );

        REQUIRE(game.getBoard().getCaseAtPosition(pos3).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(pos5).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(pos6).getColorCase() == Color::BLACK );
    }

    SECTION(" Starting lateral move 3vs 2")
    {
        Game game =Game();
        //Move
        Position position{7,7};
        Position pos2{7,11};
        Position pos3{6,6};

        //Marble White

        Position pos6{6,8};

        Color color = Color::WHITE;
        game.getBoard().getCaseAtPosition(pos3).setColorCase(color);
        game.getBoard().getCaseAtPosition(pos6).setColorCase(color);

        auto vector = std::vector<Position>{position,pos2,pos3};//correct
        game.move(vector,game.getPlayer1());


        REQUIRE(game.getBoard().getCaseAtPosition(position).getColorCase() == Color::BLACK ); //à voir
        REQUIRE(game.getBoard().getCaseAtPosition(pos2).getColorCase() == Color::BLACK );
        REQUIRE(game.getBoard().getCaseAtPosition(pos3).getColorCase() == Color::WHITE );
        REQUIRE(game.getBoard().getCaseAtPosition(pos6).getColorCase() == Color::WHITE );

    }

}


