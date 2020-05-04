

#ifndef LevelOne_hpp
#define LevelOne_hpp
#include "Level.hpp"

class LevelOne : public Level{
public:
    LevelOne(): Level(1){};
    char createBlock() override;
};

#endif /* LevelOne_hpp */
