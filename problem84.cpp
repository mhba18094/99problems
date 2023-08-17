#include <iostream>
#include <vector>
using namespace std;

vector <vector<int>> graph = {
    {0,4,0,1,8,0,0,0,0},
    {4,0,2,2,6,1,0,0,0},
    {0,2,0,0,2,5,0,0,0},
    {1,2,0,0,11,0,9,8,0},
    {8,6,2,11,0,3,4,1,5},
    {0,1,5,0,3,0,0,7,8},
    {0,0,0,9,4,0,0,6,0},
    {0,0,0,8,1,7,6,0,3},
    {0,0,0,0,5,8,0,3,0}
};


class node{
    public:
    int parent;
    int distance;
    node(){
        parent = NULL;
        distance = 999999999;
    }
};
int main(){
    bool visited[9];
    for(int c=0;c<9;c++){
        visited[c]=false;
    }
    node nodes[9];
    nodes[0].distance = 0;
    nodes[0].parent=NULL;
    //check for every graph node
    for(int c =0; c<graph.size();c++){
        //finding minimum
        int nodeWithMinimumDistance;
        vector<int>distances;
        for(int counter=0;counter<9;counter++){
            distances.push_back(nodes[counter].distance);
        }
        if (c==0){
            nodeWithMinimumDistance=0;
        }
        else{
            int min = 9999999;
            for(int current=1;current<9;current++){
                if(distances[current]<min and visited[current]==false){
                    min = distances[current];
                    nodeWithMinimumDistance = current;
                }
            }
        }
        visited[nodeWithMinimumDistance]=true;
        for(int neighbours=0;neighbours<graph.size();neighbours++){
            if(graph[nodeWithMinimumDistance][neighbours]!=0){
                if((graph[nodeWithMinimumDistance][neighbours]<nodes[neighbours].distance)and(visited[neighbours]==false)){
                    nodes[neighbours].distance = graph[nodeWithMinimumDistance][neighbours];
                    nodes[neighbours].parent = nodeWithMinimumDistance;
                }
            }

        }
    }

    for(int c =0;c<9;c++){
        cout<<"node: "<<c<<endl;
        cout<<"parent: "<<nodes[c].parent<<endl;
        cout<<"distance: "<<nodes[c].distance<<endl;
    }
    
}