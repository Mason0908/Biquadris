

#include "LevelOne.hpp"
#include <cstdlib>
#include <iostream>

char LevelOne::createBlock(){
    
    int a = rand() % 11;
    if (a == 0){
        return 'S';
    }
    if (a == 1){
        return 'Z';
    }
    if ((a == 2) || (a == 3)){
        return 'T';
    }
    if ((a == 4) || (a == 5)){
        return 'I';
    }
    if ((a == 6) || (a == 7)){
        return 'J';
    }
    if ((a == 8) || (a == 9)){
        return 'L';
    }
    else {
        return 'O';
    }
}
