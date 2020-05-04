

#ifndef ZBlock_hpp
#define ZBlock_hpp
#include "Block.hpp"

class ZBlock : public Block{
public:
    ZBlock(int id, Board* b, int lv, Displays* ob);
    void clockwise() override;
    void counterClockwise() override;
};

#endif /* ZBlock_hpp */
