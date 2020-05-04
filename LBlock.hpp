

#ifndef LBlock_hpp
#define LBlock_hpp
#include "Block.hpp"

class LBlock : public Block{
public:
    LBlock(int id, Board* b, int lv, Displays* ob);
    void clockwise() override;
    void counterClockwise() override;
};

#endif /* LBlock_hpp */
