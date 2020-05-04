

#ifndef Level_hpp
#define Level_hpp

class Level{
    int lv;
public:
    Level(int lv): lv{lv}{};
    virtual ~Level() = default;
    virtual char createBlock() = 0;
    virtual int getLv(){ return lv;};
};

#endif /* Level_hpp */
