

#ifndef TBlock_hpp
#define TBlock_hpp

#include "Block.hpp"

class TBlock : public Block{
public:
    TBlock(int id, Board* b, int lv, Displays* ob);
    void clockwise() override;
    void counterClockwise() override;
};

#endif /* TBlock_hpp */
