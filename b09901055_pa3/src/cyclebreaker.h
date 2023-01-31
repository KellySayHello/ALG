#ifndef _CYCLEBREAKER_H
#define _CYCLEBREAKER_H

#include<vector>
#include <list>
#include <utility> 
#include<stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cstdint>
#include <fstream>

using namespace std;
typedef pair<int, int> iPair;

struct Edge{
    int u;
    int v;
    int weight;
    
};

struct set{
    int p;
    int rank;
};

class DisjointSet{
    public:
        DisjointSet(int &);
        void makeSet();
        int findSet(int &) ;
        void Union(int &,int &);
        void Link(int &,int&);
        int num=0;
        set *subset;

};

class U_Graph{
    public:
        U_Graph(int ,int ,bool);
        void addEdge(int u,int v,int weight);
        void MST(vector<Edge*> &);
        vector<Edge> edge;
       // list<iPair> *adjacencyList;
    private:
        int v_num=0;
        int e_num=0;
        bool d=false;
};

class D_Graph{
    public:
        D_Graph(int ,int ,bool);
        void addEdge_d(int u,int v,int weight);
        void MST_d(vector<Edge*> &);
        list<iPair> *adjacencyList;
        vector<Edge> edge;
        // void FindCycle(vector<Edge *> &);
        // void DFS(const iPair &, int, int *, bool *, vector<iPair> &, vector<Edge *> &, bool *);
        // void rEdge(int &, int &, int &, bool *, vector<iPair> &, vector<Edge *> &, bool *);
        // void reDFS(vector<Edge *> &);
        // bool hasCycle() const;
        // bool hasCycleDFS(int &, uint8_t *) const;
    private:
        int v_num_=0;
        int e_num_=0;
        bool d_=false;
        
};

class CycleBreaker{
    public:
             CycleBreaker(); // constructor
        void BreakCycle(); //processing
        void Printans(int ,int );
        bool readFile(const char *);
        bool writeFile(const char *);
    private:
        bool directed = false;
        U_Graph *u_graph;  
        //D_Graph *d_graph;
        vector<Edge*> removeEdge;
        int removeWeight = 0;
};

#endif
