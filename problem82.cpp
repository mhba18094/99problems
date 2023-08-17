//I modified the code for dfs for this task and the motivation for the technique was from https://www.geeksforgeeks.org/find-paths-given-source-destination/

#include <iostream>
#include <vector>
#include <algorithm>

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
void findCycle(vector<vector<int>>adjacensyList,bool visited[],int start,vector <int> path={},int prev=0){
    visited[start]=true; //Always set visited for that specific node
    path.push_back(start);//current node pushed back in path array
    for(int edge:adjacensyList[start]){ //traverse the path for the graph
        if(!visited[edge]){ //if node is not visted
            findCycle(adjacensyList,visited,edge,path,start); //then visit it by dfs algo
        }
        //else if the node is already visited but
        //the current neighbouring node and previous node not same
        //this means nodes like 1---2 in an undirected graph are not considered as a cycle
        //then do this
        else if(edge != prev){ 
            //find the location of cycle element and print only cycle instead of whole array
            auto startingPoint = find(path.begin(), path.end(), edge) - path.begin(); 
            for(int c = startingPoint;c<path.size();c++){
                cout<<path[c]<<" ";
            }
            //print the element on which the cylce ends i.e itself
            cout<<edge<<endl;
        }
    }
    //status of visiting of that node is turned false so that other possible cycles from other nodes to this nodes are not missed
    visited[start]=false;
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
    g = addEdge(g,0, 1);
    g = addEdge(g,0, 2);
    g = addEdge(g,0, 3);
    g = addEdge(g,1, 4);
    g = addEdge(g,2, 5);
    g = addEdge(g,3, 6);
    g = addEdge(g,4, 7);
    g = addEdge(g,5, 7);
    g = addEdge(g,6, 7);

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
    bool visited[g.size()];
    for(int c=0;c<g.size();c++){
        visited[c]=false;
    } 
    findCycle(g,visited,0);
}