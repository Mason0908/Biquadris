

#include "IBlock.hpp"
using namespace std;

IBlock::IBlock(int id, Board* b, int lv, Displays* ob):
Block('I', id, b, lv, vector<Point>{Point{0,3}, Point{1,3}, Point{2,3}, Point{3,3}}, Point{0,3}, 0, ob) {}

void IBlock::clockwise()
{
    bool canRotate = true;
    if(getState() == 1)
    {
        for(int i = 0; i < getPos().size(); i++)
        {
            int new_x = getRotatePoint().x - getPos()[i].y + getRotatePoint().y;
            int new_y = getRotatePoint().y + getPos()[i].x - getRotatePoint().x;
            if(!check(new_x, new_y, getBoard()))
            {
                canRotate = false;
                break;
            }
        }
        
        if(canRotate)
        {
            draw(' ');
            for(int i = 0; i < getPos().size(); i++)
            {
                int new_x = getRotatePoint().x - getPos()[i].y + getRotatePoint().y;
                int new_y = getRotatePoint().y + getPos()[i].x - getRotatePoint().x;
                getPos()[i] = Point{new_x, new_y};
            }
            setState(0);
            checkHeavy();
            draw(getType());
        }
    }
    else
    {
        this->counterClockwise();
    }
}


void IBlock::counterClockwise()
{
    bool canRotate = true;
    if(getState() == 0)
    {
        for(int i = 0; i < getPos().size(); i++)
        {
            int new_x = getRotatePoint().x + getPos()[i].y - getRotatePoint().y;
            int new_y = getRotatePoint().y - getPos()[i].x + getRotatePoint().x;
            if(!check(new_x, new_y, getBoard()))
            {
                canRotate = false;
                break;
            }
            
        }
        if(canRotate)
        {
            draw(' ');
            for(int i = 0; i < getPos().size(); i++)
            {
                int new_x = getRotatePoint().x + getPos()[i].y - getRotatePoint().y;
                int new_y = getRotatePoint().y - getPos()[i].x + getRotatePoint().x;
                getPos()[i] = Point{new_x, new_y};
            }
            setState(1);
            checkHeavy();
            draw(getType());
        }
    }
    else
    {
        this->clockwise();
    }
}
