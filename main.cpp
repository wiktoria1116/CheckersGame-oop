#include <iostream>
using namespace std;

const int BLACK_PAWN = 1;
const int WHITE_PAWN = 2;

class Pawn{
    int pawnColor;
public:    
    Pawn(){

    }

    void setPawn(int pawnColor){
        this->pawnColor = pawnColor;
    }

    void paintPawn(){
        if(this->pawnColor == BLACK_PAWN){
            cout << "B";
        }
        else {
            cout << "W";
        }
    }

    void enterCoordinates(){
        cout << "Podaj pionek ";
    }

};

class Field {
    bool black;
    bool isEmpty;
    

public:
    Pawn pawn;
    Field(){   
        this->isEmpty = true;
    }

    void setFieldColor(int i, int j){
        if((i+j)%2 == 0 ){
            black = false;
        }else{
            black = true;
        }
    } 

    bool getColor(){
        return black;
    }


    void paint(){   
        if(this->getIsEmpty()){
            if(black){
               cout << "*";
            }
            else{
                cout << " ";
            }
        } 
        else{ 


            pawn.paintPawn();
        }
    }

    void setOccupied(int pawnColor){
        this->isEmpty = false;
        
    }


    void setEmpty(){
        this->isEmpty = true;
    }

    bool getIsEmpty(){
        return this->isEmpty;
    }
};


class Board {

    Field fields[8][8];
   
public:

    Board(){      
        createBoard();
        setPawns();
        paintBoard();
    }
    void setPawns(){
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){   
                if(i<3 && (i+j)%2==0){
                    fields[i][j].setOccupied(BLACK_PAWN);  
                    fields[i][j].pawn.setPawn(BLACK_PAWN);
                }
                else if(i>4 && (i+j)%2==0){
                    fields[i][j].setOccupied(WHITE_PAWN);
                    fields[i][j].pawn.setPawn(WHITE_PAWN);
                }
            }
        }
    }
    void createBoard(){
        for( int i=0; i<8; i++){

            for(int j=0; j<8; j++){
            fields[i][j].setFieldColor(i,j);
            }
        }
    }

    void paintBoard(){
        cout << " 01234567 " << endl;
        for(int i=0; i<8; i++){
            cout << i;
                for( int j=0; j<8; j++){
                    fields[i][j].paint(); 
                }
                cout << endl;
        }        
    }
};

int main() {
    
    Board place;

  return 0;
} 