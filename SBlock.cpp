

#include "SBlock.hpp"
using namespace std;

SBlock::SBlock(int id, Board* b, int lv, Displays* ob):
Block('S', id, b, lv, vector<Point>{Point{1,2}, Point{2,2}, Point{0,3}, Point{1,3}}, Point{1,2}, 0, ob){}

void SBlock::clockwise(){
    bool canRotate = true;
    if(getState() == 0){
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
    else{
        this->counterClockwise();
    }
}

void SBlock::counterClockwise(){
    bool canRotate = true;
    if(getState() == 1){
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
    else{
        this->clockwise();
    }
}


