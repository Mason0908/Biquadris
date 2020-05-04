

#ifndef LevelThree_hpp
#define LevelThree_hpp
#include "Level.hpp"

class LevelThree : public Level{
public:
    LevelThree(): Level(3){};
    char createBlock() override;
};

#endif /* LevelThree_hpp */
