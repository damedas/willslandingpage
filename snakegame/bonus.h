#ifndef BONUS_H
#define BONUS_H
#include "GridControl.h"

class Bonus:public GridControl{

public:
Bonus(); 
void bonusout(); 
virtual int bonuseffect()=0;
virtual void bonuseffectSize()=0;  
virtual void bonuseffectDSize()=0;

};
#endif