#include "Scorebonus.h"
#include <iostream>

Scorebonus::Scorebonus(){
    num=1;
}
int Scorebonus::bonuseffect(){
    cout<<"*****SCOREMULTIPLER*****\n";
    num=num*2;
    return num; 
} 

void Scorebonus::bonuseffectSize(){
    cout<<"Wrong bonus\n";
}
void Scorebonus::bonuseffectDSize(){
    cout<<"Wrong bonus\n"; 
}