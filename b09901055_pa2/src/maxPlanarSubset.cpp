#include "maxPlanarSubset.h"
#include <cstring>
#include<iostream>
#include <fstream>
#include <stdlib.h>
#include<stdio.h>

#define Isupdate 2097152u //2^21
#define valueLocation  524287u //2^19-1

#define case1 524288u //2^19 01
#define case2 1048576u //2^20 10
#define case3 1572864u //2^19+2^20 11

// Constructor
MaxPlanarSubset::MaxPlanarSubset() {}

void MaxPlanarSubset::Printans(int start,int end){ 
    if(start==end){
        return ;
    }
    uint cas=plan[start][end] & case3 ;
    
    if(cas==case2){    
        //cout<<"case2 "<<cas<<endl;   
        fout<<start<<" "<<line[start]<< endl;
        Printans(start+1,end-1);
    }
    else if(cas==case1){
        //cout<<"case3 "<<cas<<endl;
        Printans(start,line[end]-1);
        fout<<line[end]<<" "<<line[line[end]]<< endl;
        Printans(line[end]+1,end-1);
    }
    else if(cas==case3){
        //cout<<"case3 "<<cas<<endl;
        Printans(start,end-1);
    }
    else{
        return ;
    }
    
}

int MaxPlanarSubset::Maxplan(int start,int end) {
    //printf("start: %d, end: %d\n", start, end);
    bool haveUpdated=plan[start][end] & Isupdate;    
    uint value;
    uint cas;
    uint k=line[end];
    if(start>=end){
        plan[start][end]=0;
        return plan[start][end]|Isupdate;
    }
    if(haveUpdated){
        return plan[start][end];
    }
    

    if(k==start){ 
        cas=case2;
        value=(Maxplan(start+1,end-1) & valueLocation)+1;      
    }
    
    else if(k>start && k<end){
        uint value1=(Maxplan(start,k-1)& valueLocation)+(Maxplan(k+1,end-1)&valueLocation)+1;
        uint value3=Maxplan(start,end-1)&valueLocation;
        if(value1>value3){
            cas=case1;
            value=value1;            
        }
        else{
            cas=case3;
            value=value3;          
        }
    }
    else{
        cas=case3;
        value=Maxplan(start,end-1) & valueLocation;       
    }
    plan[start][end]=value | cas | Isupdate;
    //cout<<"plan "<<plan[start][end]<<" start="<<start<<" end="<<end<<endl;
    return plan[start][end];
    //cout<<"plan "<<plan[start][end]<<" start="<<start<<" end="<<end<<endl;
    //return plan[start][end];
    
}

