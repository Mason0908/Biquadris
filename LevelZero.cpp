

#include "LevelZero.hpp"
using namespace std;

LevelZero::LevelZero(string filename): Level(0), filename{filename}{
}

char LevelZero::createBlock(){
    if (blocks.size() == 0){
        ifstream f{filename};
        char c;
        while (f >> c){
            blocks.emplace_back(c);
        }
    }
    char d = blocks[0];
    blocks.erase(blocks.begin());
    return d;
    
}
