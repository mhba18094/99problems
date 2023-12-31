//incomplete
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> addEdge(vector<vector<int>>adjacensyList,int source, int destination){
    adjacensyList[source].push_back(destination);
    adjacensyList[destination].push_back(source);
    return adjacensyList;
}



/*
    Parameters:- 
        1) adjacensyList is the graph 
        2) visited[] is a pointer to array to always store the latest status that the node is visited or not
        3) start is the starting of the desired path
        3) end is the ending of the desired path
        4) path vector is used to keep track of the path and then also used to display it
*/
void allPossibleSpanningTrees(vector<vector<int>>adjacensyList,bool visited[],int start,vector <int> path={}){
    visited[start]=true; //Always set visited for that specific node
    path.push_back(start); //also push it to the path vector
    for(int edge:adjacensyList[start]){ //traverse the path for the graph
        if(!visited[edge]){ //if node is not visted
            allPossibleSpanningTrees(adjacensyList,visited,edge,path); //then visit it by dfs algo
        }
    }
    visited[start]=false; //this line added so that when a node is traversed, it is again able to be traversed for other paths
}

int main(){
    // vector<vector<int>> g={};
    // g.push_back({});
    // g.push_back({});
    // g.push_back({});
    // g.push_back({});
    // g.push_back({});
    // g.push_back({});
    // g.push_back({});
    // g.push_back({});
    // g = addEdge(g,0, 1);
    // g = addEdge(g,0, 2);
    // g = addEdge(g,0, 3);
    // g = addEdge(g,1, 4);
    // g = addEdge(g,2, 5);
    // g = addEdge(g,3, 6);
    // g = addEdge(g,4, 7);
    // g = addEdge(g,5, 7);
    // g = addEdge(g,6, 7);

    // vector<vector<int>> g={};
    // g.push_back({});
    // g.push_back({});
    // g.push_back({});
    // g.push_back({});
    // g.push_back({});
    // g = addEdge(g,0, 1);
    // g = addEdge(g,0, 2);
    // g = addEdge(g,0, 3);
    // g = addEdge(g,1, 2);
    // g = addEdge(g,2, 4);

    vector<vector<int>> g={};
    g.push_back({});
    g.push_back({});
    g.push_back({});
    g.push_back({});
    g = addEdge(g,0, 1);
    g = addEdge(g,0, 2);
    g = addEdge(g,0, 3);
    g = addEdge(g,2, 1);
    g = addEdge(g,2, 3);
    g = addEdge(g,3, 1);
    bool visited[g.size()];
    for(int c=0;c<g.size();c++){
        visited[c]=false;
    } 
    allPossibleSpanningTrees(g,visited,0);
}