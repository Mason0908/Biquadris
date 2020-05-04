

#ifndef LevelTwo_hpp
#define LevelTwo_hpp
#include "Level.hpp"

class LevelTwo : public Level{
public:
    LevelTwo(): Level(2){};
    char createBlock() override;
};

#endif /* LevelTwo_hpp */
