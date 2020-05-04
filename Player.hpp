

#ifndef Player_hpp
#define Player_hpp
#include "Board.hpp"
#include "Score.hpp"
#include "Block.hpp"
#include "Level.hpp"
#include "NextBlock.hpp"


class Player{
    Level* lv;
    Score* scr;
    Block* currBlock;
    NextBlock* nextBlock;
    Board* board;
    bool isEnd;
    bool isHeavy = false;
    
public:
    Player(Level* lv, Score* scr, Block* currBlock, NextBlock* nextBlock, Board* board):
    lv{lv}, scr{scr}, currBlock{currBlock}, nextBlock{nextBlock}, board{board}, isEnd{false}{}
    Level* getLv(){return lv;};
    Score* getScore(){return scr;};
    Block* getBlock(){return currBlock;};
    class NextBlock* getNext(){return nextBlock;};
    Board* getBoard(){return board;};
    bool getEnd(){return isEnd;};
    bool getHeavy(){ return isHeavy;};
    
    void setLv(Level* level){ lv = level; };
    void setScr(Score* score){ scr = score;};
    void setcurr(Block* block){ currBlock = block;};
    void setnext(NextBlock* next){ nextBlock = next;};
    void setBoard(Board* b){ board = b;};
    void setEnd(bool end){ isEnd = end;};
    void checkEnd();
    void setHeavy(bool heavy){ isHeavy = heavy;};
};

#endif /* Player_hpp */
