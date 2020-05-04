

#ifndef IBlock_hpp
#define IBlock_hpp
#include "Block.hpp"

class IBlock : public Block{
public:
    IBlock(int id, Board* b, int lv, Displays* ob);
    void clockwise() override;
    void counterClockwise() override;
};

#endif /* IBlock_hpp */
