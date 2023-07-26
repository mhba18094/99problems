#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> addEdge(vector<vector<int>>adjacensyList,int source, int destination){
    adjacensyList[source].push_back(destination);
    adjacensyList[destination].push_back(source);
    return adjacensyList;
}


void dfs(vector<vector<int>>adjacensyList,bool visited[],int start){
    visited[start]=true;
    cout<<start<<" ";
    for(int edge:adjacensyList[start]){
        if(!visited[edge]){
            dfs(adjacensyList,visited,edge);
        }
    }
}

int main(){
    vector<vector<int>> g={};
    g.push_back({});
    g.push_back({});
    g.push_back({});
    g.push_back({});
    g.push_back({});
    g = addEdge(g,0, 1);
    g = addEdge(g,0, 2);
    g = addEdge(g,0, 3);
    g = addEdge(g,1, 2);
    g = addEdge(g,2, 4);
    bool visited[g.size()];
    for(int c=0;c<g.size();c++){
        visited[c]=false;
    } 
    dfs(g,visited,0);
}