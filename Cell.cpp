#include "Cell.hpp"

Cell::Cell(Point pos){
    BlockType = ' ';
    this->pos = pos;
    isBlind = false;
    lv = -1;
    BlockId = -1;
}

char Cell::GetType(){
    return BlockType;
}

Point Cell::GetPos(){
    return pos;
}

int Cell::GetId(){
    return BlockId;
}

int Cell::GetLv(){
    return lv;
}

bool Cell::GetBlind(){
    return isBlind;
}

void Cell::setId(int id){
    BlockId = id;
}

void Cell::setLv(int lv){
    this->lv = lv;
}

void Cell::setPos(Point pos){
    this->pos = pos;
}

void Cell::setType(char type){
    BlockType = type;
}

void Cell::setBlind(bool isBlind){
    this->isBlind = isBlind;
}

void Cell::reset(){
    BlockType = ' ';
    isBlind = false;
    lv = -1;
    BlockId = -1;
}
