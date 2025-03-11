#include "GridControl.h"
#include <random>
#include <ctime>
#include <fstream>
#include <iostream> 

GridControl::GridControl(){} 
GridControl::GridControl(string plname, int gamedif):snakegame(plname,gamedif){
    spawned=false;
    bonusspawn= false;
}

void GridControl::GridClear(){ //create clear grid 
    for (int i=0;i<height;i++){
        for (int a=0;a<width;a++){
            grid[a][i]='X'; 
        }
    }
    slength=0; 
}

void GridControl::Grid(){ //display grid 

    //spawn bonus and fruit 
    grid[x][y]='S'; 
    rangex= (width-1)-0+1; 
    rangey= (height-1)-0+1;  
    if (spawned==false){
        srand ( time(NULL) );
        fruitx= rand()% rangex+0;
        fruity= rand()% rangey+0; 
        if (fruitx==x || fruitx==itemx){fruitx= rand()% rangex+0;} //if fruitx in same as head or fruit
        if (fruity==y || fruity==itemy){fruity= rand()% rangex+0;}  //if fruity same as head or fruit 
        grid[fruitx][fruity]='F';
        spawned=true; 
    }
    if (bonusspawn==false){
        srand ( time(NULL) );
        numbonus=0; //reset choice 
        itemx= rand()% rangex+0; 
        itemy= rand()% rangey+0; 
        if (itemx==x || itemx==fruitx){itemx= rand()% rangex+0;} //if itemx is same as fruit or head
        if (itemy==y || itemy==fruity){itemy= rand()% rangey+0;} //if itemy is the same as fruit or head
        grid[itemx][itemy]='B'; 
        bonusspawn=true; 
    }
    cout<<"       ~~SNAKE~~     \n"; 
    cout<<"------------------------"<<endl<<endl;
    for (int i=0;i<height;i++){
        cout<<"| "; 
        for (int j=0;j<width;j++){
            cout<<grid[j][i]<<" | ";
        }
        cout<<endl<<endl;
    }
    cout<<"------------------------"<<endl;
    cout<<player<<" score: "<<score<<endl; 
    
}


bool GridControl::GridInput(char dir){ //ONLY THAT CHANGES POSITIONS AND HEAD CORD
    int j;
    bool endcondition=true; 
    direction=dir; 
    int tailholdx,tailholdy;
    switch(direction){
        case 'w': //move up 
            prevx=x;
            prevy=y; 
            y=y-1; 
            grid[x][y]='S';
            if (slength==0){grid[prevx][prevy]='X';} //if snake has no tail
            else if (slength!=0){ 
                for (j=0;j<slength;j++){
                    grid[prevx][prevy]='$';
                    tailholdx=prevx; 
                    tailholdy=prevy;
                    prevx=tailx.at(j); //tail
                    prevy=taily.at(j); 
                    tailx.at(j)=tailholdx;
                    taily.at(j)=tailholdy; 
                    grid[prevx][prevy]='X'; 
                }
            }
            break;
        case 'a': //move left 
            prevx=x;
            prevy=y; 
            x=x-1;
            grid[x][y]='S';
            if (slength==0){grid[prevx][prevy]='X';} //if snake has no tail
            else if (slength!=0){ 
                for (j=0;j<slength;j++){
                    grid[prevx][prevy]='$';
                    tailholdx=prevx; 
                    tailholdy=prevy;
                    prevx=tailx.at(j); 
                    prevy= taily.at(j); 
                    tailx.at(j)=tailholdx;
                    taily.at(j)=tailholdy; 
                    grid[prevx][prevy]='X'; 
                }
            }
            break;
        case 's': //down
            prevx=x;
            prevy=y; 
            y=y+1;
            grid[x][y]='S';
            if (slength==0){grid[prevx][prevy]='X';} //if snake has no tail
            else if (slength!=0){ 
                for (j=0;j<slength;j++){
                    grid[prevx][prevy]='$';
                    tailholdx=prevx; 
                    tailholdy=prevy;
                    prevx=tailx.at(j); 
                    prevy= taily.at(j);
                    tailx.at(j)=tailholdx;
                    taily.at(j)=tailholdy; 
                    grid[prevx][prevy]='X'; 
                }
            }
            break;
        case 'd': //right
            prevx=x;
            prevy=y;
            x=x+1;
            grid[x][y]='S';
            if (slength==0){grid[prevx][prevy]='X';} //if snake has no tail
            else if (slength!=0){ 
                for (j=0;j<slength;j++){
                    grid[prevx][prevy]='$'; 
                    tailholdx=prevx; 
                    tailholdy=prevy;
                    prevx=tailx.at(j); 
                    prevy=taily.at(j);
                    tailx.at(j)=tailholdx;
                    taily.at(j)=tailholdy; 
                    grid[prevx][prevy]='X'; 
                }
            }
            break;
        case 'E': //user wants to end game
            endcondition=false;
            break; 
    }
    if (x==width+1 || y==height+1){endcondition=false;}
    if (x<0 || y<0){endcondition=false;}
    if (y>height-1){endcondition=false;} 

    if (slength!=0){ //snake hit its tail
        for (int a=0;a<slength;a++){
            if (x==tailx.at(a) && y==taily.at(a)){endcondition=false;}
        }
    }

    if (x==fruitx && y==fruity){ //snake consumed fruit 
        spawned=false; 
        score=score+1; 
        if (y!=height-1 && slength==0){ //add tail down if blank space 
        tailx.push_back(x);  
        taily.push_back(y+1); 
        }
        else if (y==height-1 && slength==0){ //add tail up in blank space 
            tailx.push_back(x);  
            taily.push_back(y-1); 
        }
        else if (slength!=0){
            int endtailx= tailx.at(slength-1); 
            int endtaily= taily.at(slength-1); 
            if (grid[endtailx][endtaily+1]=='X'){
                    tailx.push_back(endtailx);  
                    taily.push_back(endtaily+1);
                }
            else if (grid[endtailx][endtaily-1]=='X'){
                    tailx.push_back(endtailx);  
                    taily.push_back(endtaily-1);
                }
            else if (grid[endtailx+1][endtaily]=='X'){
                tailx.push_back(endtailx+1);  
                taily.push_back(endtaily);
            }
            else if (grid[endtailx-1][endtaily]=='X'){
                tailx.push_back(endtailx-1);  
                taily.push_back(endtaily);
            }
            
            
        }
        grid[tailx.at(slength)][taily.at(slength)]='$'; //add tail 
        slength=slength+1; //tail increase 1+
    }
    if (x==itemx && y==itemy){ //snake consumed bonus item
        bonusspawn=false; //reset for new fruit location 
        bconsum=true; //establish bonus conditions 
    }
    
    return endcondition; //if false end the game
}

void GridControl::save(string filename){
    ofstream myfile(filename); 
    if (myfile.is_open()){
        myfile<<player<<endl;
        myfile<<diff<<endl;
        myfile<<x<<endl;
        myfile<<y<<endl;
        myfile<<score<<endl;
        myfile<<slength<<endl;
        for (int b=0;b<slength;b++){
            myfile<<tailx.at(b)<<" "; 
        }
        myfile<<endl;
        for (int b=0;b<slength;b++){
            myfile<<taily.at(b)<<" "; 
        }
        myfile<<endl; 
        cout<<"Game Saved"<<endl; 

    }
    else {
        cout<<"Save failed"<<endl; 
    }
    myfile.close(); 
}

void GridControl::load(string filename){
    ifstream infs(filename); 
    string lname;
    int ldif,lx,ly,lscore,lslength;
    vector<int> ltx;
    vector<int> lty; 
    if (infs.is_open()){
        infs>>lname; 
        infs>>ldif;
        infs>>lx;
        infs>>ly;
        infs>>lscore;
        infs>>lslength;
        for (int a=0;a<lslength;a++){
            infs>>ltx.at(a); 
        }
        for (int z=0;z<lslength;z++){
            infs>>lty.at(z);
        }
        snakegame(lname,ldif,lx,ly,lscore,ltx,lty,lslength); 
        cout<<"File loaded succesfully\n"; 
    }
    else {
        cout<<"Failed to load game"<<endl; 
    }
    infs.close(); 
}
int GridControl::getscore(){
    return score; 
}


int GridControl::bonuschoice(){ //establish probabilities 
    numbonus=0;  
    srand ( time(NULL) );
    bool scorebonus;
    bool sizedown;
    bool increasesize;
    if (diff==1){
    scorebonus=(rand() % 100) < 50; //50% chance 
    sizedown=(rand() % 100) < 10; 
    increasesize=(rand() % 100) < 40;
    }
    
    else if (diff==2){
    scorebonus=(rand() % 100) < 50;
    sizedown=(rand() % 100) < 20;
    increasesize=(rand() % 100) < 30;
    }
    else if (diff==3){
    scorebonus=(rand() % 100) < 50;
    sizedown=(rand() % 100) < 30;
    increasesize=(rand() % 100) < 20;
    }

    if (scorebonus==true){numbonus=1;} //score
    else if (sizedown==true){numbonus=2;} //size down
    else if (increasesize==true){numbonus=3;} //size increase 

    return numbonus; 
    
}
void GridControl::bonscore(int obj){
    score=score*obj; 
}
void GridControl::isize(){
    for (int i=1;i<3;i++){ 
        score=score+1; 
        if (y!=height-1 && slength==0){ //add tail down if blank space 
        tailx.push_back(x);  
        taily.push_back(y+1); 
        }
        else if (y==height-1 && slength==0){ //add tail up in blank space 
            tailx.push_back(x);  
            taily.push_back(y-1); 
        }
        else if (slength!=0){
            int endtailx= tailx.at(slength-1); 
            int endtaily= taily.at(slength-1); 
            if (grid[endtailx][endtaily+1]=='X'){
                    tailx.push_back(endtailx);  
                    taily.push_back(endtaily+1);
                }
            else if (grid[endtailx][endtaily-1]=='X'){
                    tailx.push_back(endtailx);  
                    taily.push_back(endtaily-1);
                }
            else if (grid[endtailx+1][endtaily]=='X'){
                tailx.push_back(endtailx+1);  
                taily.push_back(endtaily);
            }
            else if (grid[endtailx-1][endtaily]=='X'){
                tailx.push_back(endtailx-1);  
                taily.push_back(endtaily);
            }
            
        }
        grid[tailx.at(slength)][taily.at(slength)]='$'; //add tail(s)
        slength=slength+1; 
    }
}
void GridControl::dsize(){
    slength=slength-1; 
    grid[tailx.at(slength)][taily.at(slength)]='X'; //remove tail 
    tailx.erase(tailx.begin()+slength); 
    taily.erase(taily.begin()+slength); 
}