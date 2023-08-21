//Whenever I return pointer to an array from the function, it somehow returns an 
//empty array


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> indegreesAndOutdegreesOfNodes(vector<vector<int>> graph){
    vector<vector<int>> degrees(graph.size(),vector<int>(2,0));
    for(int row=0;row<graph.size();row++){
        for(int column=0;column<graph.size();column++){
            if(graph[row][column]>0){
                degrees[row][0]++; //increase outdegree of current node
                degrees[column][1]++; //increase indegree of neighbour node
            }
        }
    }
    return degrees;
}

class node{
    public:
    int color;
    node(){
        color = 0;
    }
};

node answer[11];
int welshPowell(vector<vector<int>> graph){
    vector<vector<int>>degreesOnly = indegreesAndOutdegreesOfNodes(graph);
    vector<pair<int,int>>degrees;
    for(int count=0;count<graph.size();count++){
        degrees.push_back(make_pair(degreesOnly[count][0],count));
    }
    sort(degrees.begin(), degrees.end());
    reverse(degrees.begin(), degrees.end());
    vector<int>canColor(graph.size(),true);
    int colorNo=1;
    while(!degrees.empty()){
        if(canColor[degrees[0].second]==true){
            answer[degrees[0].second].color=colorNo;
            canColor[degrees[0].second]=false;
            for(int others=1;others<degrees.size();others++){
                if(graph[degrees[0].second][degrees[others].second]==0 and canColor[degrees[others].second]==true){
                    answer[degrees[others].second].color=colorNo;
                    canColor[degrees[others].second]=false;
                    for(int others2=0;others2<degrees.size();others2++){
                        if(graph[degrees[others].second][degrees[others2].second]!=0
                        and graph[degrees[0].second][degrees[others2].second]==0){
                            canColor[degrees[others2].second]=false;
                        }
                    }
                }
            }
            for(int others=1;others<degrees.size();others++){
                if((graph[degrees[0].second][degrees[others].second]==0) and (answer[degrees[others].second].color==0)){
                    canColor[degrees[others].second]=true;
                }
            }
            colorNo++;
        }
        degrees.erase(degrees.begin());
    }
    return colorNo-1;
}

int main(){
    vector <vector<int>> graph = {
    {0,1,0,0,0,0,0,1,0,0,0},
    {1,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0,1,0,1},
    {0,0,0,0,0,1,0,0,0,0,1},
    {0,0,0,0,1,0,1,0,0,0,0},
    {0,0,0,0,0,1,0,1,0,0,1},
    {1,0,0,0,0,0,1,0,1,1,1},
    {0,0,0,1,0,0,0,1,0,1,0},
    {0,0,0,0,0,0,0,1,1,0,1},
    {0,0,0,1,1,0,1,1,0,1,0}
    };

    // vector <vector<int>> graph = {
    // {0,1,1,0,1,0,0,0},
    // {1,0,0,1,0,1,0,0},
    // {1,0,0,1,0,0,1,0},
    // {0,1,1,0,0,0,0,1},
    // {1,0,0,0,0,1,1,0},
    // {0,1,0,0,1,0,0,1},
    // {0,0,1,0,1,0,0,1},
    // {0,0,0,1,0,1,1,0},
    // };
    int totalColours=welshPowell(graph);
    if(totalColours==2){
        cout<<"Graph is bipartite"<<endl;
    }
    else{
        cout<<"Graph is not bipartite"<<endl;
    }
}