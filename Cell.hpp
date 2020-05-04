

#ifndef Cell_hpp
#define Cell_hpp
#include "Point.hpp"

class Cell{
    char BlockType = ' ';
    Point pos;
    bool isBlind = false;
    int lv;
    int BlockId;
    
public:
    Cell(char type, Point pos, bool isblind, int lv, int id): BlockType{type}, pos{pos}, isBlind{isblind}, lv{lv}, BlockId{id}{}
    Cell(Point pos);
    
    char GetType();
    Point GetPos();
    int GetId();
    int GetLv();
    bool GetBlind();
    
    void setType(char type);
    void setPos(Point pos);
    void setBlind(bool isBlind);
    void setLv(int lv);
    void setId(int id);
    
    void reset();
};

#endif /* Cell_hpp */
