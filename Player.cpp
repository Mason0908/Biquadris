

#include "Player.hpp"
#include "LevelZero.hpp"

void Player::checkEnd(){
    for (int i = 0; i < 11; i++){
        if (board->getBoard()[3][i].GetType() != ' '){
            isEnd = true;
            break;
        }
    }
}
