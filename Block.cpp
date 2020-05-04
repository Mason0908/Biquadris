

#include "Block.hpp"
#include "Board.hpp"
#include <iostream>
bool Block::check(int x, int y, Board *b){
    if ((x > 10) || (x < 0) || (y > 17) || (y < 0)){
        return false;
    }
    if (b->getBoard()[y][x].GetType() != ' '){
        return false;
    }
    return true;
}

void Block::checkHeavy(){
    if (board->getLv() >= 3){
        for (int a = 0; a < pos.size(); a++){
            if(!check(pos[a].x, pos[a].y + 1, board)){
                return;
            }
        }
        for (int p = 0; p < pos.size(); p++){
            pos[p].y += 1;
        }
        rotate_point.y += 1;
    }
}

void Block::draw(char type){
    for (int i = 0; i < 4; i++){
	if (!board->getBoard()[pos[i].y][pos[i].x].GetBlind()){
            ob->fillCell(pos[i].x, pos[i].y, type);
	}
    }
}

void Block::undraw(){
    for (int i = 0; i < 4; i++){
        ob->fillCell(pos[i].x, pos[i].y, ' ');
    }
}

void Block::move(char c){
    if (c == 'l'){
        for (int a = 0; a < pos.size(); a++){
            if(!check(pos[a].x - 1, pos[a].y, board)){
                return;
            }
        }
        draw(' ');
        for (int p = 0; p < pos.size(); p++){
            pos[p].x -= 1;
        }
        rotate_point.x -= 1;
        checkHeavy();
	draw(type);
        return;
    }
    if (c == 'r'){
        for (int a = 0; a < pos.size(); a++){
            if(!check(pos[a].x + 1, pos[a].y, board)){
                return;
            }
        }
        draw(' ');
        for (int p = 0; p < pos.size(); p++){
            pos[p].x += 1;
        }
       
        rotate_point.x += 1;
        checkHeavy();
	draw(type);
        return;
    }
    if (c == 'd'){
        for (int a = 0; a < pos.size(); a++){
            if(!check(pos[a].x, pos[a].y + 1, board)){
                return;
            }
        }
        draw(' ');
        for (int p = 0; p < pos.size(); p++){
            pos[p].y += 1;
        }
        
        rotate_point.y += 1;
        checkHeavy();
	draw(type);
        return;
    }
}

void Block::drop(){
    int lowest = 18;
    for (int p = 0; p < pos.size(); p++){
        int currRow = pos[p].y;
        int currCol = pos[p].x;
        int count = 0;
        for (int r = currRow + 1; r < board->getHeight(); r++){
            if (board->getBoard()[r][currCol].GetType() == ' '){
                count++;
            }
            else{
                break;
            }
        }
        if (count < lowest){
            lowest = count;
        }
    }
    draw(' ');
    for (int p = 0; p < pos.size(); p++){
        int row = pos[p].y + lowest;
        int col = pos[p].x;
        board->getBoard()[row][col].setType(type);
        board->getBoard()[row][col].setLv(board->getLv());
        board->getBoard()[row][col].setId(BlockId);
        ob->fillCell(col, row, type);
    }
}
