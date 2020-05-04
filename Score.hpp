

#ifndef Score_hpp
#define Score_hpp

class Score{
    int currScore;
    int hiScore = 0;
    int countNotClear = 0;
public:
    void setScore(int score);
    void setHiScore();
    void countPlusOne(){countNotClear++;};
    void resetCount(){countNotClear = 0;};
    int getCount(){ return countNotClear;};
    int getScore(){return currScore;};
    int getHi(){return hiScore;};
};

#endif /* Score_hpp */
