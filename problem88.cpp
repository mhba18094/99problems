#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>adjacensyList,bool visited[],int start){
    visited[start]=true;
    cout<<start<<" ";
    for(int edge:adjacensyList[start]){
        if(!visited[edge]){
            dfs(adjacensyList,visited,edge);
        }
    }
}

void allComponents(vector<vector<int>>adjacensyList,bool visited[]){
    for(int node=0;node<adjacensyList.size();node++){
        if(visited[node]==false){
            dfs(adjacensyList,visited,node);
            cout<<endl;
        }
    }
}
vector<vector<int>> addEdge(vector<vector<int>>adjacensyList,int source, int destination){
    adjacensyList[source].push_back(destination);
    adjacensyList[destination].push_back(source);
    return adjacensyList;
}


int main(){
    vector<vector<int>> g={};
    g.push_back({});
    g.push_back({});
    g.push_back({});
    g.push_back({});
    g.push_back({});
    g.push_back({});
    g.push_back({});
    g.push_back({});
    g.push_back({});
    g = addEdge(g,0, 1);
    g = addEdge(g,2, 6);
    g = addEdge(g,3, 4);
    g = addEdge(g,5, 7);
    g = addEdge(g,1, 7);
    g = addEdge(g,6, 8);
    bool visited[g.size()];
    for(int c=0;c<g.size();c++){
        visited[c]=false;
    } 
    allComponents(g,visited);
}