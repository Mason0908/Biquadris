
#include "LevelFour.hpp"
#include <cstdlib>

char LevelFour::createBlock(){
    
    int a = rand() % 8;
    if ((a == 0) || (a == 1)){
        return 'S';
    }
    if ((a == 2) || (a == 3)){
        return 'Z';
    }
    if (a == 4){
        return 'T';
    }
    if (a == 5){
        return 'J';
    }
    if (a == 6){
        return 'L';
    }
    if (a == 7){
        return 'I';
    }
    else{
        return 'O';
    }
}
