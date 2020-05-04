#ifndef TextDisplay_hpp
#define TextDisplay_hpp
#include "window.hpp"
#include <string>
#include <memory>
class Player;


class Displays{
    bool graphic;
    Xwindow* xw = nullptr;
    int turn;
public:
    Displays(bool graphic);
    void textdisplay(Player* player1, Player* player2);
    bool getGraphic(){ return graphic;};
    void unfill();
    void restart();
    void resetLines();
    void fillBlack(int x, int y, std::string msg);
    int getTurn() {return turn;};
    void setTurn(int turn){ this->turn = turn;};
    void fillCell(int x, int y, char type);
    void fillString(int x, int y, std::string msg);
    ~Displays();
};

#endif /* TextDisplay_hpp */
