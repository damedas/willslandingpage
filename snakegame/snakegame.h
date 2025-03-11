#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include <vector>
#include <iostream>
using namespace std; 
class snakegame{

    public: 
    snakegame(); 
    snakegame(string pname, int diffy); 
    snakegame(string pname, int diffy, int sx, int sy, int sscore, vector<int> tx, vector<int> ty, int sslength);
    
    protected:
    string player; 
    int x,y; //snake head
    int fruitx,fruity; //fruit location 
    int score;
    vector<int> tailx;
    vector<int> taily; 
    int width;
    int height;
    bool gameend;  //false if game not over 
    int itemx,itemy; //item location 
    int diff; //difficulty 1,2,3
    int slength; //length of snake 
};



#endif