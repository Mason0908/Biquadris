

#ifndef JBlock_hpp
#define JBlock_hpp
#include "Block.hpp"
class JBlock : public Block{
public:
    JBlock(int id, Board* b, int lv, Displays* ob);
    void clockwise() override;
    void counterClockwise() override;
};

#endif /* JBlock_hpp */
