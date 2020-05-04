

#ifndef Block_hpp
#define Block_hpp
#include "Point.hpp"
#include <vector>
#include "Display.hpp"
class Board;

class Block{
    char type;
    int BlockId;
    Board* board;
    int rotate_state;
    Point rotate_point;
    std::vector<Point> pos;
    Displays* ob;
public:
    Block(char type, int id, Board* board, int lv, std::vector<Point> pos, Point rotate_point, int state, Displays* ob):
    type{type}, BlockId{id}, board{board}, pos{pos}, rotate_point{rotate_point}, rotate_state{state}, ob{ob}{};
    
    virtual ~Block() = default;
    
    virtual char getType() {return type;};
    virtual int getId() {return BlockId;};
    virtual Board* getBoard() {return board;};
    virtual std::vector<Point>& getPos() {return pos;};
    virtual int getState() {return rotate_state;};
    virtual Point getRotatePoint() {return rotate_point;};
    virtual void draw(char type);
    virtual void undraw();
    
    virtual void setState(int state) {rotate_state = state;};
    virtual void setRotatePoint(Point p) {rotate_point = p;};
    virtual bool check(int x, int y, Board* b);
    virtual void clockwise() = 0;
    virtual void counterClockwise() = 0;
    virtual void move(char c);
    virtual void drop();
    virtual void checkHeavy();
};
#endif /* Block_hpp */
