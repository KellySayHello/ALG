// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>
#include <math.h>
#include <climits>
#include <stdlib.h>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int> &data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    int key=0;
    for (int i=1;i<data.size();i++){
        key=data[i];
        int j=i-1;
        while (j>=0 && data[j]>key){
            data[j+1]=data[j];
            j=j-1;
        }
        data[j+1]=key;
    }
}

// Quick sort method
void SortTool::QuickSort(vector<int>& data){
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    if(low<high){
        int q=RandomizedPartition(data, low , high);
        QuickSortSubVector(data, low , q-1);
        QuickSortSubVector(data, q+1 , high);
    }

}

int SortTool::RandomizedPartition(vector<int>& data, int low, int high) {
    // Function : Partition the vector 
    // TODO : Please complete the function
    int i=rand()%(high-low+1)+low;
    swap(data[i],data[high]);
    return Partition(data,low,high);
}

int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector 
    // TODO : Please complete the function
    // Hint : Textbook page 171
    int x=data[high];
    int i=low-1;
    for (int j=low;j<high;j++){
        if (data[j]<=x){
            i++;
            swap(data[i],data[j]);
        }
    }
    swap(data[i+1],data[high]);
    return i+1;
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    int q=floor((low+high)/2);
    if(low<high){
        MergeSortSubVector(data, low , q);
        MergeSortSubVector(data, q+1 , high);
        Merge(data, low , q , q+1 ,high);
    }
    //cout <<q;
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    vector<int> L;
    vector<int> R;
    for (int i=low;i<=middle1;i++){
        L.push_back(data[i]);
    }
    for (int j=middle2;j<=high;j++){
        R.push_back(data[j]);
    }
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);
    int i=0;
    int j=0;
    for (int k=low;k<=high;k++){
        if(L[i]<=R[j]){
            data[k]=L[i];
            i++;
        }
        else{
            data[k]=R[j];
            j++;
        }
    }
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
    int left_children=2*root+1;
    int right_children=2*root+2;
    int largest=root;
    if(left_children<heapSize && data[left_children]>data[root]) {
        largest=left_children;
    }
    if(right_children<heapSize && data[right_children]>data[largest]) {
        largest=right_children;
    }
    if(largest!=root){
        swap(data[largest],data[root]);
        MaxHeapify(data, largest);
    }
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
    for (int i= heapSize / 2;i>=0;i--){
        MaxHeapify(data, i);
    }
    
}
