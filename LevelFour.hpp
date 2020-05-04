

#ifndef LevelFour_hpp
#define LevelFour_hpp
#include "Level.hpp"

class LevelFour : public Level{
public:
    LevelFour(): Level(4){};
    char createBlock() override;
};

#endif /* LevelFour_hpp */
