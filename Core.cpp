#include "Core.hpp"
#include "LevelZero.hpp"
#include "LevelOne.hpp"
#include "LevelTwo.hpp"
#include "LevelThree.hpp"
#include "LevelFour.hpp"
#include "SBlock.hpp"
#include "ZBlock.hpp"
#include "OBlock.hpp"
#include "IBlock.hpp"
#include "LBlock.hpp"
#include "JBlock.hpp"
#include "TBlock.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include "Player.hpp"
#include "Display.hpp"

using namespace std;



Core::Core(int startlevel, std::string filename1, std::string filename2, bool graphic, bool isBonus, int seed){
    srand(seed);
    this->isBonus = isBonus;
    display = new Displays{graphic};
    display->setTurn(1);
    Board* b1 = new Board{startlevel};
    Board* b2 = new Board{startlevel};
    b1->setOb(display);
    b2->setOb(display);
    b1->init();
    b2->init();
    id1 = 0;
    id2 = 0;
    int l1 = startlevel;
    int l2 = startlevel;
    Level* lv1;
    Level* lv2;
    file1 = filename1;
    file2 = filename2;
    if (l1 == 0){
        lv1 = new LevelZero{filename1};
        lv2 = new LevelZero{filename2};
    }
    if (l1 == 1){
        lv1 = new LevelOne{};
        lv2 = new LevelOne{};
    }
    if (l1 == 2){
        lv1 = new LevelTwo{};
        lv2 = new LevelTwo{};
    }
    if (l1 == 3){
        lv1 = new LevelThree{};
        lv2 = new LevelThree{};
    }
    if (l1 == 4){
        lv1 = new LevelFour{};
        lv2 = new LevelFour{};
    }
    display->fillString(40, 100, to_string(l1));
    display->fillString(340, 100, to_string(l1));
    Score* score1 = new Score{};
    Score* score2 = new Score{};
    score1->setScore(0);
    score2->setScore(0);
    display->fillString(40, 113, "0");
    display->fillString(340, 113, "0");
    NextBlock *next1 = new NextBlock{lv1, id1, b1, display};
    display->setTurn(2);
    NextBlock *next2 = new NextBlock{lv2, id2, b2, display};
    display->setTurn(1);
    Block *curr1 = next1->getBlock();
    Block *curr2 = next2->getBlock();
    curr1->draw(curr1->getType());
    display->setTurn(2);
    curr2->draw(curr2->getType());
    display->setTurn(1);
    delete next1;
    delete next2;
    id1++;
    id2++;
    next1 = new NextBlock{lv1, id1, b1, display};
    display->setTurn(2);
    next2 = new NextBlock{lv2, id2, b2, display};
    display->setTurn(1);
    player1 = new Player{lv1, score1, curr1, next1, b1};
    player2 = new Player{lv2, score2, curr2, next2, b2};
    id1++;
    id2++;
}

Block* Core::generateBlock(Player* player, string type){
    
    if (type == "Z"){
        Block* b = new ZBlock{player->getBlock()->getId(), player->getBoard(), player->getLv()->getLv(), display};
        return b;
    }
    if (type == "S"){
        Block* b = new SBlock{player->getBlock()->getId(), player->getBoard(), player->getLv()->getLv(), display};
        return b;
    }
    if (type == "T"){
        Block* b = new TBlock{player->getBlock()->getId(), player->getBoard(), player->getLv()->getLv(), display};
        return b;
    }
    if (type == "J"){
        Block* b = new JBlock{player->getBlock()->getId(), player->getBoard(), player->getLv()->getLv(), display};
        return b;
    }
    if (type == "L"){
        Block* b = new LBlock{player->getBlock()->getId(), player->getBoard(), player->getLv()->getLv(), display};
        return b;
    }
    if (type == "I"){
        Block* b = new IBlock{player->getBlock()->getId(), player->getBoard(), player->getLv()->getLv(), display};
        return b;
    }
    else {
        Block* b = new OBlock{player->getBlock()->getId(), player->getBoard(), player->getLv()->getLv(), display};
        return b;
    }
}


void Core::SpecialAction(Player* player){
    string selection;
    while(cin >> selection){
        if ((selection != "b") && (selection != "h") && (selection != "f")){
            display->fillString(150, 90, "Invalid input! Please type one of b, h and f");
            cout << "Invalid input! Please type one of b, h and f" << endl;
            
        }
        else{
            break;
        }
    }
    display->fillBlack(150, 90, "Invalid input! Please type one of b, h and f");

    if (selection == "b"){
        player->getBoard()->blindAction();
    }
    if (selection == "h"){
        player->setHeavy(true);
    }
    if (selection == "f"){
        display->fillString(150, 90, "What block do you want to replace?");
        cout << "What block do you want to replace?" << endl;

        string type;
        while (cin>>type){
            if ((type != "Z") && (type != "S") && (type != "O") && (type != "T") &&
                (type != "I") && (type != "J") && (type != "L")){
		display->fillBlack(150, 90, "What block do you want to replace?");
                display->fillString(150,90, "Invalid block type! Please input a valid block type.");
                cout << "Invalid block type! Please input a valid block type." << endl;
                
            }
            else{
                break;
            }
        }
        display->fillBlack(150,90, "Invalid block type! Please input a valid block type.");
        display->fillBlack(150, 90, "What block do you want to replace?");
        Block* temp = player->getBlock();
        player->setcurr(generateBlock(player, type));
	if (display->getTurn() == 1){
		display->setTurn(2);
		temp->draw(' ');
		player->getBlock()->draw(player->getBlock()->getType());
		display->setTurn(1);
	}
	if (display->getTurn() == 2){
                display->setTurn(1);
                temp->draw(' ');
                player->getBlock()->draw(player->getBlock()->getType());
                display->setTurn(2);
        }
	delete temp;
    }
}


void Core::RestartGame(){
    display->restart();
    display->setTurn(1);
    player1->getBoard()->init();
    display->fillBlack(40, 113, to_string(player1->getScore()->getScore()));
    player1->getScore()->setHiScore();
    player1->getScore()->setScore(0);
    display->fillString(40, 113, "0");
    player1->getScore()->resetCount();
    player1->setHeavy(false);
    delete player1->getBlock();
    player1->setcurr(player1->getNext()->getBlock());
    delete player1->getNext();
    player1->setnext(new NextBlock{player1->getLv(), id1, player1->getBoard(), display});
    id1++;
    delete player1->getBlock();
    player1->setcurr(player1->getNext()->getBlock());
    delete player1->getNext();
    player1->setnext(new NextBlock{player1->getLv(), id1, player1->getBoard(), display});
    player1->getBlock()->draw(player1->getBlock()->getType());
    display->setTurn(2);
    id1++;
    player2->getBoard()->init();
    display->fillBlack(340, 113, to_string(player2->getScore()->getScore()));
    player2->getScore()->setHiScore();
    player2->getScore()->setScore(0);
    display->fillString(340, 113, "0");
    player2->getScore()->resetCount();
    player2->setHeavy(false);
    delete player2->getBlock();
    player2->setcurr(player2->getNext()->getBlock());
    delete player2->getNext();
    player2->setnext(new NextBlock{player2->getLv(), id2, player2->getBoard(), display});
    id2++;
    delete player2->getBlock();
    player2->setcurr(player2->getNext()->getBlock());
    delete player2->getNext();
    player2->setnext(new NextBlock{player2->getLv(), id2, player2->getBoard(), display});
    player2->getBlock()->draw(player2->getBlock()->getType());
    display->setTurn(1);
    id2++;
    display->resetLines(); 
}

void Core::whoWin(){
    if (player1->getScore()->getScore() > player2->getScore()->getScore()){
        display->fillString(180, 80, "Player 1 wins this time!");
        cout << "Player 1 wins this time!" << endl;
    }
    if (player1->getScore()->getScore() == player2->getScore()->getScore()){
        display->fillString(180, 80, "It's tie this time!");
        cout << "It's tie this time!" << endl;
    }
    if (player1->getScore()->getScore() < player2->getScore()->getScore()){
        display->fillString(180, 80, "Player 2 wins this time!");
        cout << "Player 2 wins this time!" << endl;
    }
}

void Core::Run(){
    string Command;
    int turn = 1;
    bool nrd1 = false;
    bool nrd2 = false;
    vector<string> f1;
    vector<string> f2;
    string file1;
    string file2;
    string sequenceFile;
    bool sq = false;
    vector<string> sequence;
    while ((!player1->getEnd()) && (!player2->getEnd())){
        display->textdisplay(player1, player2);
        if (!sq){
            cin >> Command;
        }
	string m2 = "Player 1 has " + to_string(5 - player1->getScore()->getCount()) + " more blocks before a star block will drop";
        display->fillBlack(120, 70, m2);

        string m1 = "Player 2 has " + to_string(5 - player2->getScore()->getCount()) + " more blocks before a star block will drop";
        display->fillBlack(120, 70, m1);
        if (cin.eof()){
            break;
        }
        if (Command.substr(0,2) == "se"){
            cin >> sequenceFile;
            ifstream ff{sequenceFile};
            string cmd;
            while (ff >> cmd){
                sequence.emplace_back(cmd);
            }
            sq = true;
        }
        if (sq){
            if (sequence.size() == 0){
                break;
            }
            Command = sequence[0];
	    sequence.erase(sequence.begin());
        }
        int pre = 1;
        if ('0' <= Command[0] && Command[0] <= '9'){
            pre = Command[0] - '0';
            Command = Command.substr(1);
        }
        if (turn == 1){
            if (Command.substr(0,3) == "lef"){
                for (int i = 0; i < pre; i++){
                    player1->getBlock()->move('l');
                    if (player1->getHeavy()){
                        player1->getBlock()->move('d');
                        player1->getBlock()->move('d');
                    }
                }
                pre = 1;
                
            }
            if (Command.substr(0,2) == "ri"){
                for (int i = 0; i < pre; i++){
                    player1->getBlock()->move('r');
                    if (player1->getHeavy()){
                        player1->getBlock()->move('d');
                        player1->getBlock()->move('d');
                    }
                }
                pre = 1;
            }
            if (Command.substr(0,2) == "do"){
                for (int i = 0; i < pre; i++){
                    player1->getBlock()->move('d');
                }
                pre = 1;
            }
            if (Command.substr(0,2) == "cl"){
                for (int i = 0; i < pre; i++){
                    player1->getBlock()->clockwise();
                }
                pre = 1;
            }
            if (Command.substr(0,2) == "co"){
                for (int i = 0; i < pre; i++){
                    player1->getBlock()->counterClockwise();
                }
                pre = 1;
            }
            if (Command.substr(0,2) == "dr"){
                for (int i = 0; i < pre; i++){
                    player1->getBlock()->drop();
                    delete player1->getBlock();
                    player1->setcurr(player1->getNext()->getBlock());
                    
                    if ((nrd1) && (player1->getLv()->getLv() >= 3)){
                        if (f1.size() == 0){
                            ifstream ff{file1};
                            string tp;
                            while(ff>>tp){
                                f1.emplace_back(tp);
                            }
                        }
                        Block* temp = player1->getBlock();
                        player1->setcurr(generateBlock(player1, f1[0]));
                        temp->draw(' ');
                        player1->getBlock()->draw(player1->getBlock()->getType());
                        delete temp;
                        f1.erase(f1.begin());
                    }
                    
                    delete player1->getNext();
                    player1->setnext(new NextBlock{player1->getLv(), id1, player1->getBoard(), display});
                    
                    id1++;
                    int lines = player1->getBoard()->clearLines();
                    if (lines >= 2){
                        string msg = "Wow! You clear " + to_string(lines) + " rows! You can select one of the following action on your opponent:";
                        display->fillString(20, 70, msg);
                        cout << "Wow! You clear " << lines << " rows! You can select one of the following action on your opponent:" << endl;
                        display->fillString(150, 80, "Blind(b) Heavy(h) Force(f)");
                        cout << "Blind(b)\nHeavy(h)\nForce(f)" << endl;
                        SpecialAction(player2);
                        display->fillBlack(20, 70, msg);
                        display->fillBlack(150, 80, "Blind(b) Heavy(h) Force(f)");
                    }
                    player1->getBoard()->unBlind();
                    player1->getBlock()->draw(player1->getBlock()->getType());
                    int add = player1->getBoard()->clear();
                    int now = player1->getScore()->getScore();
                    player1->getScore()->setScore(add + now);
                    if (add >0){
                        display->fillBlack(40,113,to_string(now));
                        display->fillString(40, 113, to_string(add+now));
                    }
                    if ((add == 0) && (player1->getLv()->getLv() == 4)){
                        player1->getScore()->countPlusOne();
                    }
                    else if ((add > 0) && (player1->getLv()->getLv() == 4)){
                        player1->getScore()->resetCount();
                    }
                    if ((player1->getScore()->getCount() % 5 == 0) && (player1->getScore()->getCount() > 0)){
                        player1->getBoard()->dropStar();
                    }
                }
                turn = 2;
                display->setTurn(2);
            }
            if (Command.substr(0,6) == "levelu"){
		display->fillBlack(40, 100, to_string(player1->getLv()->getLv()));
                for (int i = 0; i < pre; i++){
                    if (player1->getLv()->getLv() == 0){
                        delete player1->getLv();
                        player1->setLv(new LevelZero{file1});
                        player1->getBoard()->setLv(player1->getLv()->getLv());
                    }
                    else if (player1->getLv()->getLv() == 1){
                        delete player1->getLv();
                        player1->setLv(new LevelTwo{});
                        player1->getBoard()->setLv(player1->getLv()->getLv());
                    }
                    else if (player1->getLv()->getLv() == 2){
                        delete player1->getLv();
                        player1->setLv(new LevelThree{});
                        player1->getBoard()->setLv(player1->getLv()->getLv());
                    }
                    else if (player1->getLv()->getLv() == 3){
                        delete player1->getLv();
                        player1->setLv(new LevelFour{});
                        player1->getBoard()->setLv(player1->getLv()->getLv());
                    }
                }
		
		display->fillString(40, 100, to_string(player1->getLv()->getLv()));
                pre = 1;
            }
            if (Command.substr(0,6) == "leveld"){
		display->fillBlack(40, 100, to_string(player1->getLv()->getLv()));
                for (int i = 0; i < pre; i++){
                    if (player1->getLv()->getLv() == 1){
                        delete player1->getLv();
                        player1->setLv(new LevelZero{file1});
                        player1->getBoard()->setLv(player1->getLv()->getLv());
                    }
                    else if (player1->getLv()->getLv() == 2){
                        delete player1->getLv();
                        player1->setLv(new LevelOne{});
                        player1->getBoard()->setLv(player1->getLv()->getLv());
                    }
                    else if (player1->getLv()->getLv() == 3){
                        delete player1->getLv();
                        player1->setLv(new LevelTwo{});
                        player1->getBoard()->setLv(player1->getLv()->getLv());
                    }
                    else if (player1->getLv()->getLv() == 4){
                        delete player1->getLv();
                        player1->setLv(new LevelThree{});
                        player1->getScore()->resetCount();
                        player1->getBoard()->setLv(player1->getLv()->getLv());
                    }
                }
		display->fillString(40, 100, to_string(player1->getLv()->getLv()));
                pre = 1;
            }
            if ((Command == "I") || (Command == "S") || (Command == "J") || (Command == "T") ||
                (Command == "O") ||(Command == "Z") || (Command == "L")){
                Block* temp = generateBlock(player1, Command);
                player1->getBlock()->undraw();
                delete player1->getBlock();
                player1->setcurr(temp);
                player1->getBlock()->draw(player1->getBlock()->getType());
            }
            if (Command.substr(0,2) == "re"){
                display->fillString(180, 70, "Player1 requests restart.");
                cout << "Player1 requests restart." << endl;
                whoWin();
                RestartGame();
                display->fillBlack(180, 70, "Player1 requests restart.");
                display->fillBlack(180, 80, "Player 1 wins this time!");
                display->fillBlack(180, 80, "Player 2 wins this time!");
                display->fillBlack(180, 80, "It's tie this time!");
                turn = 1;
                display->setTurn(1);
            }
            if (Command.substr(0,1) == "n"){
                cin >> file1;
                if (player1->getLv()->getLv() >= 3){
                    nrd1 = true;
                }
            }
            if (Command.substr(0,2) == "ra"){
                if (player1->getLv()->getLv() >= 3){
                    nrd1 = false;
                }
            }
            if ((Command.substr(0,3) == "cha") && (isBonus)){
                for (int i = 0; i < pre; i++){
                    delete player1->getNext();
                    player1->setnext(new NextBlock{player1->getLv(), id1, player1->getBoard(), display});
                    int nowScore = player1->getScore()->getScore();
                    int nowLevel = player1->getLv()->getLv();
                    player1->getScore()->setScore(nowScore - (nowLevel + 1));
                    display->fillBlack(40,113,to_string(nowScore));
                    display->fillString(40, 113, to_string(nowScore - nowLevel - 1));
		}
                pre = 1;
            }
            if ((Command.substr(0,2) == "sk") && (isBonus)){
                for (int i = 0; i < pre; i++){
                    player1->getBlock()->undraw();
                    delete player1->getBlock();
                    player1->setcurr(player1->getNext()->getBlock());
                    player1->getBlock()->draw(player1->getBlock()->getType());
                    delete player1->getNext();
                    player1->setnext(new NextBlock{player1->getLv(), id1, player1->getBoard(), display});
                    
                    id1++;
                    int nowScore = player1->getScore()->getScore();
                    int nowLevel = player1->getLv()->getLv();
                    player1->getScore()->setScore(nowScore - (nowLevel + 1));
		    display->fillBlack(40,113,to_string(nowScore));
                    display->fillString(40, 113, to_string(nowScore - nowLevel - 1));

                }
                pre = 1;
            }
	    if ((Command.substr(0,3) == "che") && (isBonus) && (player1->getLv()->getLv() == 4)){
                cout << "Player 1 has " << 5 - player1->getScore()->getCount() << " more blocks before a star block will drop" << endl;
                string msg = "Player 1 has " + to_string(5 - player1->getScore()->getCount()) + " more blocks before a star block will drop";
		display->fillString(120, 70, msg);
	    }
            player1->checkEnd();
            if (player1->getEnd()){
                display->fillString(180, 70, "Player1 is game over!");
                cout << "Player1 is game over!" << endl;
                whoWin();
                display->fillString(180, 90, "Do you want to restart? (Y or N)");
                cout << "Do you want to restart? (Y or N)" << endl;
                string YesorNo;
		
                while(cin >> YesorNo){
		    
                    if ((YesorNo != "Y") && (YesorNo != "N")){
                        display->fillBlack(180, 80, "Player 1 wins this time!");
                        display->fillBlack(180, 80, "Player 2 wins this time!");
                        display->fillBlack(180, 80, "It's tie this time!");
		        display->fillString(180, 80, "Invalid Input! Please enter Y or N");
                        cout << "Invalid Input! Please enter Y or N" << endl;
                        
                    }
                    else{
                        break;
                    }
                }
		display->fillBlack(180, 70, "Player1 is game over!");
                display->fillBlack(180, 80, "Player 1 wins this time!");
                display->fillBlack(180, 80, "Player 2 wins this time!");
                display->fillBlack(180, 80, "It's tie this time!");
		display->fillBlack(180, 80, "Invalid Input! Please enter Y or N");
                display->fillBlack(180, 90, "Do you want to restart? (Y or N)");
                if (YesorNo == "Y"){
                    RestartGame();
                    player1->setEnd(false);
                    player2->setEnd(false);
                    turn = 1;
                    display->setTurn(1);
                }
                else if (YesorNo == "N"){
                    break;
                }
            }
        }
        
        
        
        else if (turn == 2){
            
            if (Command.substr(0,2) == "le"){
                for (int i = 0; i < pre; i++){
                    player2->getBlock()->move('l');
                    if (player2->getHeavy()){
                        player2->getBlock()->move('d');
                        player2->getBlock()->move('d');
                    }
                }
                pre = 1;
            }
            if (Command.substr(0,2) == "ri"){
                for (int i = 0; i < pre; i++){
                    player2->getBlock()->move('r');
                    if (player2->getHeavy()){
                        player2->getBlock()->move('d');
                        player2->getBlock()->move('d');
                    }
                }
                pre = 1;
            }
            if (Command.substr(0,2) == "do"){
                for (int i = 0; i < pre; i++){
                    player2->getBlock()->move('d');
                }
                pre = 1;
            }
            if (Command.substr(0,2) == "cl"){
                for (int i = 0; i < pre; i++){
                    player2->getBlock()->clockwise();
                }
                pre = 1;
            }
            if (Command.substr(0,2) == "co"){
                for (int i = 0; i < pre; i++){
                    player2->getBlock()->counterClockwise();
                }
                pre = 1;
            }
            if (Command.substr(0,2) == "dr"){
                for (int i = 0; i < pre; i++){
                    player2->getBlock()->drop();
                    delete player2->getBlock();
                    player2->setcurr(player2->getNext()->getBlock());
                    
                    if ((nrd2) && (player2->getLv()->getLv() >= 3)){
                        if (f2.size() == 0){
                            ifstream ff{file2};
                            string tp;
                            while(ff>>tp){
                                f2.emplace_back(tp);
                            }
                        }
                        Block* temp = player2->getBlock();
                        player2->setcurr(generateBlock(player2, f2[0]));
                        temp->draw(' ');
                        player2->getBlock()->draw(player2->getBlock()->getType());
                        delete temp;
                        f2.erase(f2.begin());
                    }
                    
                    delete player2->getNext();
                    player2->setnext(new NextBlock{player2->getLv(), id2, player2->getBoard(), display});
                    id2++;
                    int lines = player2->getBoard()->clearLines();
                    if (lines >= 2){
                        string msg = "Wow! You clear " + to_string(lines) + " rows! You can select one of the following action on your opponent:";
                        display->fillString(20, 70, msg);
                        cout << "Wow! You clear " << lines << " rows! You can select one of the following action on your opponent:" << endl;
                        display->fillString(150, 80, "Blind(b) Heavy(h) Force(f)");
                        cout << "Blind(b)\nHeavy(h)\nForce(f)" << endl;
                        SpecialAction(player1);
                        display->fillBlack(20, 70, msg);
                        display->fillBlack(150, 80, "Blind(b) Heavy(h) Force(f)");
                    }
                    player2->getBoard()->unBlind();
                    player2->getBlock()->draw(player2->getBlock()->getType());
                    int add = player2->getBoard()->clear();
                    int now = player2->getScore()->getScore();
                    player2->getScore()->setScore(add + now);
                    if (add >0){
                        display->fillBlack(340,113,to_string(now));
                        display->fillString(340, 113, to_string(add+now));
                    }
                    if ((add == 0) && (player2->getLv()->getLv() == 4)){
                        player2->getScore()->countPlusOne();
                    }
                    else if ((add > 0) && (player2->getLv()->getLv() == 4)){
                        player2->getScore()->resetCount();
                    }
                    if ((player2->getScore()->getCount() % 5 == 0) && (player2->getScore()->getCount() > 0)){
                        player2->getBoard()->dropStar();
                    }
                }
                turn = 1;
                display->setTurn(1);
            }
            if (Command.substr(0,6) == "levelu"){
		display->fillBlack(340, 100, to_string(player2->getLv()->getLv()));
                for (int i = 0; i < pre; i++){
                    if (player2->getLv()->getLv() == 0){
                        delete player2->getLv();
                        player2->setLv(new LevelZero{file2});
                        player2->getBoard()->setLv(player2->getLv()->getLv());
                        
                    }
                    else if (player2->getLv()->getLv() == 1){
                        delete player2->getLv();
                        player2->setLv(new LevelTwo{});
                        player2->getBoard()->setLv(player2->getLv()->getLv());
                    }
                    else if (player2->getLv()->getLv() == 2){
                        delete player2->getLv();
                        player2->setLv(new LevelThree{});
                        player2->getBoard()->setLv(player2->getLv()->getLv());
                    }
                    else if (player2->getLv()->getLv() == 3){
                        delete player2->getLv();
                        player2->setLv(new LevelFour{});
                        player2->getBoard()->setLv(player2->getLv()->getLv());
                    }
                }
		
                display->fillString(340, 100, to_string(player2->getLv()->getLv()));
                pre = 1;
            }
            if (Command.substr(0,6) == "leveld"){
		display->fillBlack(340, 100, to_string(player2->getLv()->getLv()));
                for (int i = 0; i < pre; i++){
                    if (player2->getLv()->getLv() == 1){
                        delete player2->getLv();
                        player2->setLv(new LevelZero{file2});
                        player2->getBoard()->setLv(player2->getLv()->getLv());
                    }
                    else if (player2->getLv()->getLv() == 2){
                        delete player2->getLv();
                        player2->setLv(new LevelOne{});
                        player2->getBoard()->setLv(player2->getLv()->getLv());
                    }
                    else if (player2->getLv()->getLv() == 3){
                        delete player2->getLv();
                        player2->setLv(new LevelTwo{});
                        player2->getBoard()->setLv(player2->getLv()->getLv());
                    }
                    else if (player2->getLv()->getLv() == 4){
                        delete player2->getLv();
                        player2->setLv(new LevelThree{});
                        player2->getScore()->resetCount();
                        player2->getBoard()->setLv(player2->getLv()->getLv());
                    }
                }
		display->fillString(340, 100, to_string(player2->getLv()->getLv()));
                pre = 1;
            }
            if ((Command == "I") || (Command == "S") || (Command == "J") || (Command == "T") ||
                (Command == "O") ||(Command == "Z") || (Command == "L")){
                Block* temp = generateBlock(player2, Command);
                player2->getBlock()->undraw();
                delete player2->getBlock();
                player2->setcurr(temp);
                player2->getBlock()->draw(player2->getBlock()->getType());
            }
            if (Command.substr(0,2) == "re"){
                display->fillString(180, 70, "Player2 requests restart.");
                cout << "Player2 requests restart." << endl;
                whoWin();
                RestartGame();
                display->fillBlack(180, 70, "Player2 requests restart.");
                display->fillBlack(180, 80, "Player 2 wins this time!");
                display->fillBlack(180, 80, "Player 1 wins this time!");
                display->fillBlack(180, 80, "It's tie this time!");
                turn = 1;
                display->setTurn(1);
            }
            if (Command.substr(0,1) == "n"){
                cin >> file2;
                if (player2->getLv()->getLv() >= 3){
                    nrd2 = true;
                }
            }
            if (Command.substr(0,2) == "ra"){
                if (player2->getLv()->getLv() >= 3){
                    nrd2 = false;
                }
            }
            if ((Command.substr(0,3) == "cha") && (isBonus)){
                for (int i = 0; i < pre; i++){
                    delete player2->getNext();
                    player2->setnext(new NextBlock{player2->getLv(), id2, player2->getBoard(), display});
                    int nowScore = player2->getScore()->getScore();
                    int nowLevel = player2->getLv()->getLv();
                    player2->getScore()->setScore(nowScore - nowLevel - 1);
                    display->fillBlack(340,113,to_string(nowScore));
                    display->fillString(340, 113, to_string(nowScore - nowLevel - 1));

		}
                pre = 1;
            }
            if ((Command.substr(0,2) == "sk") && (isBonus)){
                for (int i = 0; i < pre; i++){
                    player2->getBlock()->undraw();
                    delete player2->getBlock();
                    player2->setcurr(player2->getNext()->getBlock());
                    player2->getBlock()->draw(player2->getBlock()->getType());
                    delete player2->getNext();
                    player2->setnext(new NextBlock{player2->getLv(), id2, player2->getBoard(), display});
                    
                    id2++;
                    int nowScore = player2->getScore()->getScore();
                    int nowLevel = player2->getLv()->getLv();
                    player2->getScore()->setScore(nowScore - (nowLevel + 1));
                    display->fillBlack(340,113,to_string(nowScore));
                    display->fillString(340, 113, to_string(nowScore - nowLevel - 1));

		}
                pre = 1;
            }
	    if ((Command.substr(0,3) == "che") && (isBonus) && (player2->getLv()->getLv() == 4)){
                cout << "Player 2 has " << 5 - player2->getScore()->getCount() << " more blocks before a star block will drop" << endl;
                string msg = "Player 2 has " + to_string(5 - player2->getScore()->getCount()) + " more blocks before a star block will drop";
                display->fillString(120, 70, msg);
            }
            player2->checkEnd();
            if (player2->getEnd()){
                display->fillString(180, 70, "Player2 is game over!");
                cout << "Player2 is game over!" << endl;
                whoWin();
                
                display->fillString(180, 90, "Do you want to restart? (Y or N)");
                cout << "Do you want to restart? (Y or N)" << endl;
                string YesorNo;
                while(cin >> YesorNo){
                    if ((YesorNo != "Y") && (YesorNo != "N")){
		        display->fillBlack(180, 80, "Player 2 wins this time!");
                        display->fillBlack(180, 80, "Player 1 wins this time!");
                        display->fillBlack(180, 80, "It's tie this time!");
                        display->fillString(180, 80, "Invalid Input! Please enter Y or N");
                        cout << "Invalid Input! Please enter Y or N" << endl;
                        
                    }
                    else{
                        break;
                    }
                }
		display->fillBlack(180, 70, "Player2 is game over!");
                display->fillBlack(180, 80, "Player 2 wins this time!");
                display->fillBlack(180, 80, "Player 1 wins this time!");
                display->fillBlack(180, 80, "It's tie this time!");

		display->fillBlack(180, 80, "Invalid Input! Please enter Y or N");
                display->fillBlack(180, 90, "Do you want to restart? (Y or N)");
                if (YesorNo == "Y"){
                    RestartGame();
                    turn = 1;
                    display->setTurn(1);
                    player1->setEnd(false);
                    player2->setEnd(false);
                }
                else if (YesorNo == "N"){
                    break;
                }
            }
        }
        
    }
    player1->getScore()->setHiScore();
    player2->getScore()->setHiScore();
    if (player1->getScore()->getHi() > player2->getScore()->getHi()){
        string msg =  "Player 1 wins! Player 1 has the higest score: " + to_string(player1->getScore()->getHi()) + "!!";
        display->fillString(150, 70, msg);
        cout << "Player 1 wins! Player 1 has the higest score: " << player1->getScore()->getHi() << "!!" << endl;
    }
    if (player1->getScore()->getHi() == player2->getScore()->getHi()){
        string msg =  "Tie! Player 1 and Player 2 have the same highest score: " + to_string(player2->getScore()->getHi()) + "!!";
        display->fillString(150,70,msg);
        cout << "Tie! Player 1 and Player 2 have the same highest score: " << player1->getScore()->getHi() << "!!" << endl;
    }
    if (player1->getScore()->getHi() < player2->getScore()->getHi()){
        string msg =  "Player 2 wins! Player 2 has the higest score: " + to_string(player2->getScore()->getHi()) + "!!";
        display->fillString(150,70,msg);
        cout << "Player 2 wins! Player 2 has the highest score: " << player2->getScore()->getHi()  << "!!" << endl;
    }
}

Core::~Core(){
    delete player1->getBoard();
    delete player2->getBoard();
    delete player1->getBlock();
    delete player2->getBlock();
    delete player1->getNext()->getBlock();
    delete player2->getNext()->getBlock();
    delete player1->getNext();
    delete player2->getNext();
    delete player1->getLv();
    delete player2->getLv();
    delete player1->getScore();
    delete player2->getScore();
    delete player1;
    delete player2;
    delete display;
}
