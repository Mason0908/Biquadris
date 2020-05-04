

#ifndef NextBlock_hpp
#define NextBlock_hpp
#include "Block.hpp"
#include "Level.hpp"
#include <vector>
#include "Display.hpp"

class NextBlock{
    Block* block;
    Displays* ob;
    std::vector<std::vector<char>> model;
public:
    NextBlock(Level* lv, int id, Board* b, Displays* ob);
    Block* getBlock(){return block;};
    std::vector<std::vector<char>> getModel(){ return model;};
};

#endif /* NextBlock_hpp */
