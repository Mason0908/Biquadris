

#include "Score.hpp"

void Score::setScore(int score){
    currScore = score;
}

void Score::setHiScore(){
    hiScore = (currScore > hiScore) ? currScore : hiScore;
}
