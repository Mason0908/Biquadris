

#include "ZBlock.hpp"


using namespace std;

ZBlock::ZBlock(int id, Board* b, int lv, Displays* ob):
Block('Z', id, b, lv, vector<Point>{Point{0,2}, Point{1,2}, Point{1,3}, Point{2,3}}, Point{1,2}, 0, ob) {}

void ZBlock::clockwise()
{
    bool canRotate = true;
    if(getState() == 0)
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
            setState(1);
            checkHeavy();
            draw(getType());
        }
    }
    else
    {
        this->counterClockwise();
    }
}

void ZBlock::counterClockwise()
{
    bool canRotate = true;
    if(getState() == 1)
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
            setState(0);
            checkHeavy();
            draw(getType());
        }
    }
    else
    {
        this->clockwise();
    }
}
