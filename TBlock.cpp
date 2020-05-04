

#include "TBlock.hpp"
using namespace std;

TBlock::TBlock(int id, Board* b, int lv, Displays* ob):
Block('T', id, b, lv, vector<Point>{Point{0,2}, Point{1,2}, Point{2,2}, Point{1,3}}, Point{1,2}, 0, ob) {}


void TBlock::clockwise()
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
    
    else if(getState() == 1)
    {
        for(int i = 0; i < getPos().size(); i++)
        {
            int new_x = getRotatePoint().x - getPos()[i].y + getRotatePoint().y;
            int new_y = getRotatePoint().y + getPos()[i].x - getRotatePoint().x;
            if(!check(new_x, new_y + 1, getBoard()))
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
                getPos()[i] = Point{new_x, new_y + 1};
            }
            setState(2);
            Point new_rotate = Point{getRotatePoint().x, getRotatePoint().y + 1};
            setRotatePoint(new_rotate);
            checkHeavy();
            draw(getType());
        }
    }
    
    else if(getState() == 2)
    {
        for(int i = 0; i < getPos().size(); i++)
        {
            int new_x = getRotatePoint().x - getPos()[i].y + getRotatePoint().y;
            int new_y = getRotatePoint().y + getPos()[i].x - getRotatePoint().x;
            if(!check(new_x - 1, new_y - 1, getBoard()))
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
                getPos()[i] = Point{new_x - 1, new_y - 1};
            }
            setState(3);
            Point new_rotate = Point{getRotatePoint().x - 1, getRotatePoint().y - 1};
            setRotatePoint(new_rotate);
            checkHeavy();
            draw(getType());
        }
    }
    
    else if(getState() == 3)
    {
        for(int i = 0; i < getPos().size(); i++)
        {
            int new_x = getRotatePoint().x - getPos()[i].y + getRotatePoint().y;
            int new_y = getRotatePoint().y + getPos()[i].x - getRotatePoint().x;
            if(!check(new_x + 1, new_y, getBoard()))
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
                getPos()[i] = Point{new_x + 1, new_y};
            }
            setState(0);
            Point new_rotate = Point{getRotatePoint().x + 1, getRotatePoint().y};
            setRotatePoint(new_rotate);
            checkHeavy();
            draw(getType());
        }
    }
}

void TBlock::counterClockwise()
{
    bool canRotate = true;
    if(getState() == 0)
    {
        for(int i = 0; i < getPos().size(); i++)
        {
            int new_x = getRotatePoint().x + getPos()[i].y - getRotatePoint().y;
            int new_y = getRotatePoint().y - getPos()[i].x + getRotatePoint().x;
            if(!check(new_x - 1, new_y, getBoard()))
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
                getPos()[i] = Point{new_x - 1, new_y};
            }
            setState(3);
            Point new_rotate = Point{getRotatePoint().x - 1, getRotatePoint().y};
            setRotatePoint(new_rotate);
            checkHeavy();
            draw(getType());
        }
    }
    else if(getState() == 3)
    {
        for(int i = 0; i < getPos().size(); i++)
        {
            int new_x = getRotatePoint().x + getPos()[i].y - getRotatePoint().y;
            int new_y = getRotatePoint().y - getPos()[i].x + getRotatePoint().x;
            if(!check(new_x + 1, new_y + 1, getBoard()))
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
                getPos()[i] = Point{new_x + 1, new_y + 1};
            }
            setState(2);
            Point new_rotate = Point{getRotatePoint().x + 1, getRotatePoint().y + 1};
            setRotatePoint(new_rotate);
            checkHeavy();
            draw(getType());
        }
    }
    
    else if(getState() == 2)
    {
        for(int i = 0; i < getPos().size(); i++)
        {
            int new_x = getRotatePoint().x + getPos()[i].y - getRotatePoint().y;
            int new_y = getRotatePoint().y - getPos()[i].x + getRotatePoint().x;
            if(!check(new_x, new_y - 1, getBoard()))
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
                getPos()[i] = Point{new_x, new_y - 1};
            }
            setState(1);
            Point new_rotate = Point{getRotatePoint().x, getRotatePoint().y - 1};
            setRotatePoint(new_rotate);
            checkHeavy();
            draw(getType());
        }
    }
    
    else if(getState() == 1)
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
}
