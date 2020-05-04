

#ifndef OBlock_hpp
#define OBlock_hpp
#include "Block.hpp"
class OBlock : public Block{
public:
    OBlock(int id, Board* b, int lv, Displays* ob);
    void clockwise() override;
    void counterClockwise() override;
};
#endif /* OBlock_hpp */
