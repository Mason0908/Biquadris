#include "Board.hpp"
#include "Point.hpp"
#include <iostream>
using namespace std;

Board::Board(int lv){
    this->lv = lv;
}


void Board::init(){
    if (theBoard.size() != 0){
        for (int x = 0; x < theBoard.size(); x++){
            theBoard[x].clear();
        }
        theBoard.clear();
    }
    for (int r = 0; r < height; r++){
        vector<Cell> temp;
        for (int c = 0; c < width; c++){
            Point curr{c,r};
            temp.emplace_back(Cell{curr});
        }
        theBoard.emplace_back(temp);
    }
}

bool is_in(vector<int> l, int i){
    for (auto &n : l){
        if (n == i){
            return true;
        }
    }
    return false;
}

int get_pos(vector<int> l, int i){
    for (int a = 0; a < l.size(); a++){
        if (l[a] == i){
            return a;
        }
    }
    return -1;
}

int Board::clearLines(){
    vector<int> lines;
    //check if any lines will be clear
    for (int r = 0; r < height; r++){
        int count = 0;
        for (int c = 0; c < width; c++){
            if (theBoard[r][c].GetType() != ' '){
                count++;
            }
        }
        if (count == 11) {
            lines.emplace_back(r);
        };
        count = 0;
    }
    return lines.size();
}

int Board::clear(){
    vector<int> lines;
    //check if any lines will be clear
    for (int r = 0; r < height; r++){
        int count = 0;
        for (int c = 0; c < width; c++){
            if (theBoard[r][c].GetType() != ' '){
                count++;
            }
        }
        if (count == 11) {
            lines.emplace_back(r);
        };
        count = 0;
    }
    //return 0 if no line will be clear
    if (lines.size() == 0) return 0;
    //store levels of the blocks when generated, which will be completely clear
    vector<int> levels;
    //store ids of blocks that will be completely clear
    vector<int> ids;
    //add all block id of the lines that will be clear to "ids" vector
    for (int line = 0; line < lines.size(); line++){
        for (int c = 0; c < width; c++){
            int currID = theBoard[lines[line]][c].GetId();
            if (!is_in(ids, currID)){
                ids.emplace_back(currID);
            }
        }
    }
    // remove block id that appear in lines other than the cleared lines
    for (int r = 0; r < height; r++){
        for (int c = 0; c < width; c++){
            if (!is_in(lines, r)){
                if (is_in(ids, theBoard[r][c].GetId())){
                    int pos = get_pos(ids, theBoard[r][c].GetId());
                    ids.erase(ids.begin() + pos);
                }
            }
        }
    }
    //add levels of completely cleared blocks to "level" vector
    for (int line = 0; line < lines.size(); line++){
        for (int c = 0; c < width; c++){
            int id = theBoard[lines[line]][c].GetId();
            if (is_in(ids, id)){
                levels.emplace_back(theBoard[lines[line]][c].GetLv());
                int pos = get_pos(ids, id);
                ids.erase(ids.begin() + pos);
            }
        }
    }
    //calculate score from line clear
    int lineScore = (lv + lines.size()) * (lv + lines.size());
    int blockScore = 0;
    //calculate score from block clear
    for (auto &n : levels){
        blockScore += (n + 1) * (n + 1);
    }
    int total = lineScore + blockScore;
    //reset all cleared cells
    for (int line = 0; line < lines.size(); line++){
        for (int c = 0; c < width; c++){
            theBoard[lines[line]][c].reset();
	        ob->fillCell(c, lines[line], ' ');
        }
    }
    int l = lines.size();
    for (int r = (height - l - 1); r >= 3; r--){
	int a = 0;
        for (int c = 0; c < width; c++){
	    if ((theBoard[r+l][c].GetType() == ' ') && (theBoard[r][c].GetType() == ' ')){
		a++;
	    }
            theBoard[r+l][c].setLv(theBoard[r][c].GetLv());
            theBoard[r+l][c].setType(theBoard[r][c].GetType());
            theBoard[r+l][c].setId(theBoard[r][c].GetId());
            ob->fillCell(c, r+l, theBoard[r+l][c].GetType());
            theBoard[r][c].reset();
            ob->fillCell(c, r, ' ');
        }
	if (a == 11){
            break;
	}
	a = 0;
        
    }
    return total;
}

vector<vector<Cell>>& Board::getBoard(){
    return theBoard;
}

void Board::setLv(int l){
    lv = l;
}

void Board::dropStar(){
    for (int i = height - 1; i >= 0; i--){
        if (theBoard[i][5].GetType() == ' '){
            theBoard[i][5].setType('*');
            ob->fillCell(5,i,'*'); 
            break;
        }
    }
}

void Board::blindAction(){
    for (int r = 2; r < 12; r++){
        for (int c = 2; c < 9; c++){
	    if (ob->getTurn() == 1){
                ob->setTurn(2);
                ob->fillCell(c, r, 'B');	
                theBoard[r][c].setBlind(true);
	        ob->setTurn(1);
	    }
	    else {
		ob->setTurn(1);
                ob->fillCell(c, r, 'B');
                theBoard[r][c].setBlind(true);
                ob->setTurn(2);
	    }
        }
    }
}

void Board::unBlind(){
    for (int r = 2; r < 12; r++){
        for (int c = 2; c < 9; c++){
	    if (theBoard[r][c].GetBlind() == true){
	         theBoard[r][c].setBlind(false);
		 ob->fillCell(c,r,theBoard[r][c].GetType());
            }
	    
        }
    }
}
Board::~Board(){
    for (int i = 0; i < theBoard.size(); i++){
        theBoard[i].clear();
    }
    theBoard.clear();
}
