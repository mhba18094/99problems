//Given a matrix of integers matrix of size n*m, where each element represents the cost of passing from that cell,
//create a function that returns the cost of the minimum cost path to go from the top left cell to the right bottom
//cell, knowing that you can only move the right or bottom direction

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostPath(vector <vector<int>>v,int i=0,int j=0){
    if((i==v.size()-1) and j==(v[0].size()-1)){
        return v[i][j];
    }
    else if(i==v.size()-1){
        return v[i][j] + minCostPath(v,i,j+1);
    }
    else if(j==v[0].size()-1){
        return v[i][j] + minCostPath(v,i+1,j);
    }
    else{
        return v[i][j]+ min(minCostPath(v,i,j+1),minCostPath(v,i+1,j));
    }
}

int main(){
    vector <vector <int>>v = {
        {3,12,4,7,10},
        {8,15,11,4},
        {19,5,14,32,21},
        {1,20,2,9,7}
    };
    cout <<"Minimum path length is: "<<minCostPath(v)<<endl;
}
