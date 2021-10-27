#include "View.h"


void View ::displayBoard(Board& board){
    int a =0;
    for(int i =0;i<=11;i++){
        for(int j =0;j<=18;j++){
            Position position(i,j);
            displayLimiteAndLetter(i,j);
            if(board.getCaseAtPosition(position).getColorCase()==WHITE){
                std::cout<<"O";
            }else if(board.getCaseAtPosition(position).getColorCase()==BLACK)
            {
                std::cout<<"X";
            }else if(board.getCaseAtPosition(position).getColorCase()==EMPTY){
                std::cout<<".";
            }else if(i==11 &&(j>=9 && j<=13 )){
                a++;
                std::cout<<a<<" ";
            }
            else{
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }
}

void View::displayLimiteAndLetter(int & i ,int &j){

    if(i==0 && (j>=9 && j<=13)){
        std::cout<<"_";
    }

    if((i ==1 &&j==14)||(i==2 && j==15) || (i==3 && j==16) || (i==4 &&j==17)){
        std::cout<<"\\";
    }

    if(i==1){
        if(j==5){
            std::cout<<"I--/";
        }
    }
    if(i==2){
        if(j==4){
            std::cout<<"H--/";
        }
    }
    if(i==3){
        if(j==3){
            std::cout<<"G--/";
        }
    }
    if(i==4){
        if(j==2){
            std::cout<<"F--/";
        }
    }
    if(i==5){
        if( j==1){
            std::cout<<"E--(";
        }
        if(j==18){
            std::cout<<")";
        }


    }

    if((i==6 && j==17) || (i==7 &&j==16) || (i==8 && j==15) ||(i==9 && j==14)){
        std::cout<<"/";
    }
    if(i==10){
        if(j>=9 && j<=13){
            std::cout<<"-";
        }
    }

    if(i==6){
        if( j==2){
            std::cout<<"D--\\";
        }
        if(j==17){
            std::cout<<"9";
        }

    }
    if(i==7){
        if( j==3){
            std::cout<<"C--\\";
        }
        if(j==16){
            std::cout<<"8";
        }

    }
    if(i==8){
        if( j==4){
            std::cout<<"B--\\";
        }
        if(j==15){
            std::cout<<"7";
        }

    }
    if(i==9){
        if( j==5){
            std::cout<<"A--\\";
        }
        if(j==14){
            std::cout<<"6";
        }

    }

}
void View::message(std::string mess)
{
    std::cout<<mess<<std::endl;

}

void View::displayNbMarbles(Player player){
    std::cout<<"Player "<<(player.getPlayerColor()==BLACK?"X":"O")<<" "<<player.getcmpt()<<" marbles"<<std::endl;
}



