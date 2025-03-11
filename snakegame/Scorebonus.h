#ifndef SCOREBONUS_H
#define SCOREBONUS_H
#include "bonus.h"

class Scorebonus:public Bonus{
    public:
    Scorebonus(); 
    int bonuseffect(); 
    void bonuseffectSize();  
    void bonuseffectDSize(); 

    private: 
    int num; 
};  

#endif