#include "cyclebreaker.h"
#include <cstring>
#include<iostream>
#include <fstream>
#include <stdlib.h>
#include<stdio.h>
#include <utility> 
#include <queue>
#include <climits>
#include <algorithm>

// Constructor
typedef pair<int, int> iPair;
//disjointSet
DisjointSet::DisjointSet(int &number):num(number){
    subset=new set[num];
    makeSet();
}
void DisjointSet::makeSet(){
    for(int i=0;i<num;++i){
        subset[i].p=i;
        subset[i].rank=0;
    }
}
int DisjointSet::findSet(int &i){
    if(subset[i].p==i) return i;
    else{
        subset[i].p=findSet(subset[i].p);
        return subset[i].p;
    }
}

void DisjointSet::Union(int &x,int &y){
    int x_p=findSet(x);
    int y_p=findSet(y);
    if (subset[x_p].rank>subset[y_p].rank){
        subset[y_p].p=x_p;
    }
    else if (subset[x_p].rank<subset[y_p].rank){
        subset[x_p].p=y_p;
    }
    else{
        subset[y_p].p=x_p;
        subset[x_p].rank++;
    }
}

U_Graph::U_Graph(int vertex_num,int edge_num,bool directed):v_num(vertex_num),e_num(edge_num),d(directed){
   if(!d)
        edge.reserve(edge_num);
}
void U_Graph::addEdge(int u, int v ,int weight){
    if(!d){
         edge.push_back(Edge{u,v,weight});
    }
}

void U_Graph::MST(vector<Edge *> &removeEdge){
    DisjointSet set(v_num);
    sort(edge.begin(),edge.end(),[](const Edge &a,const Edge &b){
         return a.weight > b.weight;
    });

    for(int i=0;i<e_num;i++){
        if (set.findSet(edge[i].u) != set.findSet(edge[i].v)){
            set.Union(edge[i].u, edge[i].v);
        }
        else{
            removeEdge.push_back(&edge[i]);
        }
    }
}

D_Graph::D_Graph(int vertex_num,int edge_num,bool directed):v_num_(vertex_num),e_num_(edge_num),d_(directed){
    if (d_){
        edge.reserve(edge_num);
        adjacencyList = new list<iPair>[v_num_]; 
    }      
}
void D_Graph::addEdge_d(int u, int v ,int weight){
    if(d_){
        edge.push_back(Edge{u,v,weight});
        adjacencyList[u].push_back(make_pair(v, weight));
    }
}
// void D_Graph::FindCycle(vector<Edge *> &removeEdge){
//     vector<iPair> parents(v_num_);
//     // const int nv=v_num_;
//     // int ev=e_num_;
//     for (int v = 0; v < v_num_; ++v)
//     {
//         bool inCycle[v_num_] = {false};
//         bool addEdge[e_num_] = {false};
//         int color[v_num_] = {0};

//         DFS(make_pair(v, 0), -1, color, inCycle, parents, removeEdge, addEdge);
//     }
// }
// void D_Graph::DFS(const iPair &ap, int p, int *color, bool *inCycle, vector<iPair> &parent, vector<Edge *> &removeEdge, bool *addEdge){
//     int u = ap.first; 
//     color[u] = 1;//gray

//     parent[u] = make_pair(p, ap.second);
//     cerr << "[" << p << "] -> [" << u << "] " << ap.second << endl;

//     for (auto i = adjacencyList[u].begin(); i !=adjacencyList[u].end(); ++i)
//     {
//         int v = (*i).first;

//         // for (int i = 0; i < v_num_; ++i)
//         //     cerr << (int)color[i] << " ";
//         // cerr << endl;
//         // cerr << "(p, curr, next) = " << p << " -> " << u << ", " << v << endl;
        
//         if (inCycle[v])
//         {
//             continue;
//         }
        
//         if (color[v] == 1)
//         {
//             rEdge(v, u, (*i).second, inCycle, parent, removeEdge, addEdge);
//             parent.clear();
//         }
//         else if (color[v] == 0)//white
//             DFS(*i, u, color, inCycle, parent, removeEdge, addEdge);
//     }

//     color[u] = 2;//black
// }

// void D_Graph::rEdge(int &start, int &end, int &last_weight, bool *inCycle, vector<iPair> &parents, vector<Edge *> &removeEdge, bool *addEdge){
//     vector<Edge> cycleE;
//     Edge end_e{end, start, last_weight};
//     Edge min_e{0, 0, INT_MAX};

//     // backtrace edges in the cycle
//     inCycle[end] = inCycle[start] = true;

//     cycleE.push_back(end_e);
//     for (int v = end; v != start; v = parents[v].first)
//     {
//         inCycle[v] = true;
//         Edge e{parents[v].first, v, parents[v].second};
//         cycleE.push_back(e);
//     }
//     for (uint32_t i = 0; i < cycleE.size(); ++i)
//     {
//         if (cycleE[i].weight < min_e.weight)
//             min_e = cycleE[i];
//     }
//     for (uint32_t i = 0; i < edge.size(); ++i)
//     {
//         if (edge[i].weight == min_e.weight && !addEdge[i])
//         {
//             removeEdge.push_back(&edge[i]);
//             addEdge[i] = true;
//         }
//     }

//    // for (uint32_t i = 0; i < v_num_; ++i)
//     //     cout << (int)inCycle[i] << " ";
//     // cout << endl;
// }

// void D_Graph::MST_d(vector<Edge *> &removeEdge){
//     DisjointSet set(v_num_);
//     sort(edge.begin(),edge.end(),[](const Edge &a,const Edge &b){
//          return a.weight > b.weight;
//     });

//     for(int i=0;i<e_num_;i++){
//         if (set.findSet(edge[i].u) != set.findSet(edge[i].v)){
//             set.Union(edge[i].u, edge[i].v);
//         }
//         else{
//             removeEdge.push_back(&edge[i]);
//         }
//     }
// }

// void reDFS(vector<Edge *> &removeEdge){
//     vector<Edge *> tmp;
//     MST_d(tmp);

//     for (uint32_t i = 0; i < tmp.size(); ++i)
//     {
//         Edge e = *tmp[i];
//         list<iPair>::iterator it = std::find( adjacencyList[e.u].begin(), adjacencyList[e.u].end(), make_pair(e.v, e.weight));
//         adjacencyList[e.u].erase(it);
//     }

//     for (uint32_t i = 0; i < tmp.size(); ++i)
//     {
//         if ((*tmp[i]).weight <= 0) // only remove negative weight edges
//         {
//             removeEdge.push_back(tmp[i]);
//             continue;
//         }

//         adjacencyList[(*tmp[i]).u].push_back(make_pair((*tmp[i]).v, (*tmp[i]).weight));
//         //bool c=;
//         if (hasCycle())
//         {
//             adjacencyList[(*tmp[i]).u].pop_back();
//             removeEdge.push_back(tmp[i]);
//         }
//     }
// }

// bool D_Graph::hasCycle() const
// {
//     uint8_t color[v_num_] = {0};//white
//     for (int v = 0; v < int(v_num_); ++v)
//     {
//         if(color[v] == 0)
//         {
//             if (hasCycleDFS(v, color))
//                 return true;
//         }
//     }
//     return false;
// }

// bool D_Graph::hasCycleDFS(int &u, uint8_t *color) const
// {
//     color[u] = 1;//gray
//     for (auto i = adjacencyList[u].begin(); i != adjacencyList[u].end(); ++i)
//     {
//         int v = (*i).first;
//         if (color[v] == 1)
//             return true;
//         else if (color[v] == 0 && hasCycleDFS(v, color))
//             return true;
//     }
//     color[u] = 2;//black
//     return false;
// }


CycleBreaker::CycleBreaker() {}
bool CycleBreaker::readFile(const char *filename){
    ifstream ifs(filename);
    if (!ifs.is_open())
        return false;

    int v_num = 0, e_num = 0;
    char type;
    ifs >> type;
    if (type == 'd')
       directed = true;
   
    ifs >> v_num;
    ifs >> e_num;
    if (!directed){
         u_graph = new U_Graph(v_num, e_num, directed); 
        for (int k = 0; k < e_num; ++k)
        {
            int i, j;
            int w;
            ifs >> i >> j >> w;
            u_graph->addEdge(i, j, w);
        }
    }
    else{

    }
       

    ifs.close();
    return true;
}

void CycleBreaker::BreakCycle(){
    if(directed)
    {
        //d_graph->reDFS(removedEdge);
    }else
    {
        u_graph->MST(removeEdge);
    }
    for (uint32_t i = 0; i < removeEdge.size(); ++i)
        removeWeight += removeEdge[i]->weight;
}

bool CycleBreaker::writeFile(const char *filename)
{
    ofstream ofs(filename);
    if (!ofs.is_open())
        return false;
    
    if(removeEdge.empty())
        ofs << "0" << endl;
    else
    {
        ofs << removeWeight << endl;
        for (uint32_t i = 0; i < removeEdge.size(); ++i)
            ofs << removeEdge[i]->u << " " << removeEdge[i]->v
            << " " << removeEdge[i]->weight << "\n";
    }
    ofs.flush();
    ofs.close();
    delete u_graph;
    return true;
}


