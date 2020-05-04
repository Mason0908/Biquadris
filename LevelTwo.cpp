

#include "LevelTwo.hpp"
#include <cstdlib>

char LevelTwo::createBlock(){
    
    int a = rand() % 6;
    if (a == 0){
        return 'S';
    }
    if (a == 1){
        return 'Z';
    }
    if (a == 2){
        return 'L';
    }
    if (a == 3){
        return 'T';
    }
    if (a == 4){
        return 'O';
    }
    if (a == 5){
        return 'J';
    }
    else {
        return 'I';
    }
}
