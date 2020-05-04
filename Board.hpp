#ifndef Board_hpp
#define Board_hpp
#include "Cell.hpp"
#include <vector>
#include "Display.hpp"


class Board{
    std::vector<std::vector<Cell>> theBoard;
    int lv;
    int height = 18;
    int width = 11;
    Displays* ob;
public:
    Board(int lv);
    ~Board();
    void setOb(Displays* ob){ this->ob = ob;};
    void init();
    int clear();
    int clearLines();
    void setLv(int l);
    int getLv() {return lv;};
    std::vector<std::vector<Cell>>& getBoard();
    int getHeight(){ return height;};
    int getWidth(){ return width;};
    void dropStar();
    void blindAction();
    void unBlind();
};


#endif
