

#ifndef LevelZero_hpp
#define LevelZero_hpp
#include "Level.hpp"
#include <vector>
#include <fstream>


class LevelZero : public Level{
    std::string filename;
    std::vector<char> blocks;
public:
    LevelZero(std::string filename);
    char createBlock() override;
};

#endif /* LevelZero_hpp */
