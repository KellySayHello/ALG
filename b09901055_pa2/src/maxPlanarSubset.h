#ifndef _MAXPLANARSUBSET_H
#define _MAXPLANARSUBSET_H
#define MaxInput 180000

#include<vector>
#include<stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cstdint>
#include <fstream>

using namespace std;
 
class MaxPlanarSubset{
    public:
                    MaxPlanarSubset(); // constructor
        int         Maxplan(int ,int );
        void        Printans(int ,int );
        uint*        plan[MaxInput];
        uint*        line;
        fstream fout;
        
};

#endif
