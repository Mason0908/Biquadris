#include "Display.hpp"
#include "Player.hpp"
#include <iostream>
#include <string>

using namespace std;

Displays::Displays(bool graphic): graphic{graphic}{
    if (graphic){
        xw = new Xwindow{520, 600};
        xw->fillRectangle(0, 0, 520, 600,Xwindow::Black);
        xw->drawBigString(180, 40, "Biquadris", Xwindow::White);
        xw->drawString(0, 100, "Level:",Xwindow::White);
        xw->drawString(300, 100, "Level:",Xwindow::White);
        xw->drawString(0, 113, "Score:",Xwindow::White);
	xw->fillRectangle(0,115, 520, 3, Xwindow::White);
	xw->fillRectangle(225,120, 3, 360, Xwindow::White);
        xw->drawString(300, 113, "Score:",Xwindow::White);
        xw->drawString(0, 540, "Next:",Xwindow::White);
        xw->drawString(300, 540, "Next:",Xwindow::White);
	xw->fillRectangle(0,480, 520, 3, Xwindow::White);
	xw->fillRectangle(295,120, 3, 360, Xwindow::White);
    }
};

void Displays::resetLines(){
	if (graphic){
 	    xw->fillRectangle(225,120, 3, 360, Xwindow::White);
	    xw->fillRectangle(295,120, 3, 360, Xwindow::White);

	}
}


int index(int r, int c, vector<Point> pos){
    for (int i = 0; i < 4; i++){
        if ((pos[i].x == c) && (pos[i].y == r)){
            return i;
        }
    }
    return -1;
}

void Displays::fillCell(int x, int y, char type){
    if (graphic){
        if (turn == 1){
            if (type == 'I'){
                xw->fillRectangle(x*20, y*20 + 120, 20, 20, Xwindow::Red);
            }
            if (type == 'J'){
                xw->fillRectangle(x*20, y*20 + 120, 20, 20, Xwindow::Green);
            }
            if (type == 'L'){
                xw->fillRectangle(x*20, y*20 + 120, 20, 20, Xwindow::Blue);
            }
            if (type == 'T'){
                xw->fillRectangle(x*20, y*20 + 120, 20, 20, Xwindow::Cyan);
            }
            if (type == 'S'){
                xw->fillRectangle(x*20, y*20 + 120, 20, 20, Xwindow::Yellow);
            }
            if (type == 'Z'){
                xw->fillRectangle(x*20, y*20 + 120, 20, 20, Xwindow::Magenta);
            }
            if (type == 'O'){
                xw->fillRectangle(x*20, y*20 + 120, 20, 20, Xwindow::Orange);
            }
            if (type == ' '){
                xw->fillRectangle(x*20, y*20 + 120, 20, 20, Xwindow::Black);
            }
            if (type == '*'){
                xw->fillRectangle(x*20, y*20 + 120, 20, 20, Xwindow::Brown);
            }
	    if (type == 'B'){
		    xw->fillRectangle(x*20, y*20 + 120, 20, 20, Xwindow::DarkGreen);
            }
        }
        if (turn == 2){
            if (type == 'I'){
                xw->fillRectangle(300+x*20, y*20 + 120, 20, 20, Xwindow::Red);
            }
            if (type == 'J'){
                xw->fillRectangle(300+x*20, y*20 + 120, 20, 20, Xwindow::Green);
            }
            if (type == 'L'){
                xw->fillRectangle(300+x*20, y*20 + 120, 20, 20, Xwindow::Blue);
            }
            if (type == 'T'){
                xw->fillRectangle(300+x*20, y*20 + 120, 20, 20, Xwindow::Cyan);
            }
            if (type == 'S'){
                xw->fillRectangle(300+x*20, y*20 + 120, 20, 20, Xwindow::Yellow);
            }
            if (type == 'Z'){
                xw->fillRectangle(300+x*20, y*20 + 120, 20, 20, Xwindow::Magenta);
            }
            if (type == 'O'){
                xw->fillRectangle(300+x*20, y*20 + 120, 20, 20, Xwindow::Orange);
            }
            if (type == ' '){
                xw->fillRectangle(300+x*20, y*20 + 120, 20, 20, Xwindow::Black);
            }
            if (type == '*'){
                xw->fillRectangle(300+x*20, y*20 + 120, 20, 20, Xwindow::Brown);
            }
	    if (type == 'B'){
		     xw->fillRectangle(300+x*20, y*20 + 120, 20, 20, Xwindow::DarkGreen);
            }
        }	    
        
    }
}

void Displays::fillBlack(int x, int y, string msg){
    if(graphic){
        xw->drawString(x, y, msg, Xwindow::Black);
    }
}

void Displays::fillString(int x, int y, string msg){
    if(graphic){
        xw->drawString(x, y, msg, Xwindow::White);
    }
}

void Displays::unfill(){
    if (graphic){
        if (turn = 1){
            xw->fillRectangle(0, 160, 220, 40, Xwindow::Black);
        }
        if (turn = 2){
            xw->fillRectangle(300, 160, 220, 40, Xwindow::Black);
        }
    }
    
}

void Displays::restart(){
    if (graphic){
        xw->fillRectangle(0, 120, 520, 360, Xwindow::Black);
    }
    
}
void Displays::textdisplay(Player* player1, Player* player2){
    int lv1 = player1->getLv()->getLv();
    int lv2 = player2->getLv()->getLv();
    int score1 = player1->getScore()->getScore();
    int score2 = player2->getScore()->getScore();
    NextBlock* next1 = player1->getNext();
    NextBlock* next2 = player2->getNext();
    cout << "Level:    " << lv1 << "    " << "Level:    " << lv2 << endl;
    cout << "Score:    " << score1 << "    " << "Score:    " << score2 << endl;
    cout << "-----------    -----------" << endl;
    int width = player1->getBoard()->getWidth();
    int height = player1->getBoard()->getHeight();
    
    Block* curr1 = player1->getBlock();
    Block* curr2 = player2->getBlock();
    for (int r = 0; r < height; r++){
        for (int c = 0; c < width; c++){
            if (player1->getBoard()->getBoard()[r][c].GetBlind()){
                cout << '?';
            }
            else if (index(r, c, curr1->getPos()) >= 0){
                cout << curr1->getType();
            }
            else{
                cout << player1->getBoard()->getBoard()[r][c].GetType();
            }
        }
        cout << "    ";
        for (int c1 = 0; c1 < width; c1++){
            if (player2->getBoard()->getBoard()[r][c1].GetBlind()){
                cout << '?';
            }
            else if (index(r, c1, curr2->getPos()) >= 0){
                cout << curr2->getType();
            }
            else{
                cout << player2->getBoard()->getBoard()[r][c1].GetType();
            }
        }
        cout << endl;
    }
    cout << "-----------    -----------" << endl;
    cout << "Next:          Next:      " << endl;
    for (int r = 0; r < 2; r++){
        for (int c = 0; c < 4; c++){
            cout << next1->getModel()[r][c];
        }
        cout << "           ";
        for (int c1 = 0; c1 < 4; c1++){
            cout << next2->getModel()[r][c1];
        }
        cout << "       " << endl;
    }
}

Displays::~Displays(){
	
	delete xw;
}
