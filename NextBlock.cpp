
#include <iostream>
#include "NextBlock.hpp"
#include "SBlock.hpp"
#include "ZBlock.hpp"
#include "OBlock.hpp"
#include "IBlock.hpp"
#include "LBlock.hpp"
#include "JBlock.hpp"
#include "TBlock.hpp"
using namespace std;

NextBlock::NextBlock(Level* lv, int id, Board* b, Displays* ob){
    char c = lv->createBlock();
    if (c == 'S'){
        block = new SBlock{id, b, lv->getLv(), ob};
        vector<char> p1;
        vector<char> p2;
        p1.emplace_back(' ');
        p1.emplace_back('S');
        p1.emplace_back('S');
        p1.emplace_back(' ');
        p2.emplace_back('S');
        p2.emplace_back('S');
        p2.emplace_back(' ');
        p2.emplace_back(' ');
        model.emplace_back(p1);
        model.emplace_back(p2);
    }
    if (c == 'Z'){
        block = new ZBlock{id, b, lv->getLv(), ob};
        vector<char> p1;
        vector<char> p2;
        p1.emplace_back('Z');
        p1.emplace_back('Z');
        p1.emplace_back(' ');
        p1.emplace_back(' ');
        p2.emplace_back(' ');
        p2.emplace_back('Z');
        p2.emplace_back('Z');
        p2.emplace_back(' ');
        model.emplace_back(p1);
        model.emplace_back(p2);
    }
    if (c == 'O'){
        block = new OBlock{id, b, lv->getLv(), ob};
        vector<char> p1;
        vector<char> p2;
        p1.emplace_back('O');
        p1.emplace_back('O');
        p1.emplace_back(' ');
        p1.emplace_back(' ');
        p2.emplace_back('O');
        p2.emplace_back('O');
        p2.emplace_back(' ');
        p2.emplace_back(' ');
        model.emplace_back(p1);
        model.emplace_back(p2);
    }
    if (c == 'I'){
        block = new IBlock{id, b, lv->getLv(), ob};
        vector<char> p1;
        vector<char> p2;
        p1.emplace_back(' ');
        p1.emplace_back(' ');
        p1.emplace_back(' ');
        p1.emplace_back(' ');
        p2.emplace_back('I');
        p2.emplace_back('I');
        p2.emplace_back('I');
        p2.emplace_back('I');
        model.emplace_back(p1);
        model.emplace_back(p2);
    }
    if (c == 'J'){
        block = new JBlock{id, b, lv->getLv(), ob};
        vector<char> p1;
        vector<char> p2;
        p1.emplace_back('J');
        p1.emplace_back(' ');
        p1.emplace_back(' ');
        p1.emplace_back(' ');
        p2.emplace_back('J');
        p2.emplace_back('J');
        p2.emplace_back('J');
        p2.emplace_back(' ');
        model.emplace_back(p1);
        model.emplace_back(p2);
    }
    if (c == 'T'){
        block = new TBlock{id, b, lv->getLv(), ob};
        vector<char> p1;
        vector<char> p2;
        p1.emplace_back('T');
        p1.emplace_back('T');
        p1.emplace_back('T');
        p1.emplace_back(' ');
        p2.emplace_back(' ');
        p2.emplace_back('T');
        p2.emplace_back(' ');
        p2.emplace_back(' ');
        model.emplace_back(p1);
        model.emplace_back(p2);
    }
    if (c == 'L'){
        block = new LBlock{id, b, lv->getLv(), ob};
        vector<char> p1;
        vector<char> p2;
        p1.emplace_back(' ');
        p1.emplace_back(' ');
        p1.emplace_back('L');
        p1.emplace_back(' ');
        p2.emplace_back('L');
        p2.emplace_back('L');
        p2.emplace_back('L');
        p2.emplace_back(' ');
        model.emplace_back(p1);
        model.emplace_back(p2);
    }
    ob->fillCell(2, 21, ' ');
    ob->fillCell(3, 21, ' ');
    ob->fillCell(4, 21, ' ');
    ob->fillCell(5, 21, ' ');
    ob->fillCell(2, 22, ' ');
    ob->fillCell(3, 22, ' ');
    ob->fillCell(4, 22, ' ');
    ob->fillCell(5, 22, ' ');

    
    if (ob->getTurn() == 1){
	  
	    for (int i = 0; i < block->getPos().size(); i++){
                ob->fillCell(block->getPos()[i].x+2, block->getPos()[i].y+19, block->getType());
            }

    }
    if (ob->getTurn() == 2){
	    
	    for (int i = 0; i < block->getPos().size(); i++){
                ob->fillCell(block->getPos()[i].x+2, block->getPos()[i].y+19, block->getType());
            }
    }

}
