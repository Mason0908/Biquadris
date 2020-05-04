

#ifndef SBlock_hpp
#define SBlock_hpp

#include "Block.hpp"
#include "Point.hpp"
#include <vector>

class SBlock : public Block{
    
public:
    SBlock(int id, Board* b, int lv, Displays* ob);
    void clockwise() override;
    void counterClockwise() override;
};

#endif /* SBlock_hpp */
