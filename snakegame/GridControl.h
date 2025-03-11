#ifndef GRIDCONTROL_H
#define GRIDCONTROL_H
#include "snakegame.h"
class GridControl:public snakegame{

    public:
    GridControl();
    GridControl(string plname, int gamedif); 
    void Grid();
    bool GridInput(char dir); //return false if game over conditions 
    void GridClear();
    void save(string filename);
    void load(string filename); 
    int getscore();  
    bool bconsum; 
    int bonuschoice();  
    void dsize(); //decrease size bonus
    void isize(); //increase size by 2 bonus
    void bonscore(int obj); //bonus socre
     
    protected:
    char grid[20][20];  // map 
    char direction; 
    bool spawned; //fruit 
    bool bonusspawn; //bonus
    int prevx,prevy; 
    int rangex; 
    int rangey; 
    int numbonus; 

    private:
    string Savefile; 

};

#endif