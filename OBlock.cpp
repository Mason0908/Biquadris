

#include "OBlock.hpp"

using namespace std;

OBlock::OBlock(int id, Board* b, int lv, Displays* ob):
Block('O', id, b, lv, vector<Point>{Point{0,2}, Point{1,2}, Point{0,3}, Point{1,3}}, Point{0,0}, 0,ob){}

void OBlock::clockwise() {
    draw(' ');
    checkHeavy();
    draw(getType());
}

void OBlock::counterClockwise() {
    draw(' ');
    checkHeavy();
    draw(getType());
}
