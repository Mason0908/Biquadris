

#ifndef Core_hpp
#define Core_hpp



#include <string>
class Displays;
class Player;
class Block;
class Core{
    Displays* display;
    Player* player1;
    Player* player2;
    std::string file1;
    std::string file2;
    int id1;
    int id2;
    int seed;
    bool isBonus;
public:
    Core(int startlevel, std::string filename1, std::string filename2, bool graphic, bool isBonus, int seed = 0);
    void Run();
    void RestartGame();
    void whoWin();
    Block* generateBlock(Player* player, std::string type);
    void SpecialAction(Player* player);
    ~Core();
};
#endif /* Core_hpp */
