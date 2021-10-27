#include <iostream>
#include <AbaPro.h>
#include "string"


int getYFromChar(char lettre,char  nombre){

    auto getX = getXFromChar(lettre);

    switch (nombre) {
    case '1':
        return getX-4;
    case '2':
        return getX-2;
    case '3':
        return getX;
    case '4':
        return getX+2;
    case '5':
        return getX+4;
    case '6':
        return getX+6;
    case '7':
        return getX+8;
    case '8':
        return getX+10;
    case '9':
        return getX+12;
    default:throw std::invalid_argument("Invalid input numbers");
    }
}
int getXFromChar(char c){
    char b =std::toupper(c);
    switch (b) {
    case 'A':
        return 9;
    case 'B':
        return 8;
    case 'C':
        return 7;
    case 'D':
        return 6;
    case 'E':
        return 5;
    case 'F':
        return 4;
    case 'G':
        return 3;
    case 'H':
        return 2;
    case 'I':
        return 1;
    default:throw std::invalid_argument("Invalid input letters");

    }
}

bool checkCorrectLetters(char c){
    std::string authorized="ABCDEFGHIabcdefghi";

    for(size_t j=0;j<authorized.length();j++){
        if(c==authorized.at(j)){
            return true;
        }
    }
    return false;
}

bool checkCorrectNumbers(char c){
    std::string authorized="123456789";

    for(size_t j=0;j<authorized.length();j++){
        if(c==authorized.at(j)){
            return true;
        }
    }
    return false;
}


std::vector<Position> findPositionFromAbaPro(std::string abapro){

    std::vector<Position> positions{};
    if(abapro.length()!=4 && abapro.length()!=6){
        std::cout<<"Invalid abapro"<<std::endl;
        return positions;
    }
    for(size_t i=0;i<abapro.length();i++){

        if(i%2==0) {
            if (!isalpha(abapro.at(i))||!checkCorrectLetters(abapro.at(i))){
                std::cout<<"Not alpha";
                return positions;
            }

        }else if(!checkCorrectNumbers(abapro.at(i))){
            std::cout<<"Not digit"<<std::endl;
            return positions;
        }
    }


    int x,y,x2,y2;

    x=getXFromChar(abapro.at(0));

    y = (getYFromChar(abapro.at(0),abapro.at(1)));
    positions.push_back(Position(x,y));
    y2=getYFromChar(abapro.at(2),abapro.at(3));
    x2 = (getXFromChar(abapro.at(2)));

    positions.push_back(Position(x2,y2));

    if(abapro.length()==6){
        int x3,y3;
        y3=getYFromChar(abapro.at(4),abapro.at(5));
        x3=(getXFromChar(abapro.at(4)));
        positions.push_back(Position(x3,y3));
    }
    return positions;
}
