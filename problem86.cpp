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

node answer[11];//array to store colors of the graph
void welshPowell(vector<vector<int>> graph){
    //getting degrees of every node
    vector<vector<int>>degreesOnly = indegreesAndOutdegreesOfNodes(graph);
    //making pairs of degrees first with the node numbers as second
    vector<pair<int,int>>degrees;
    //filling degrees array
    for(int count=0;count<graph.size();count++){
        degrees.push_back(make_pair(degreesOnly[count][0],count));
    }
    //sorting in ascending order
    sort(degrees.begin(), degrees.end());
    //reversing order to convert it in descending order as not able to sort in
    //descending order directly with respect to degrees
    reverse(degrees.begin(), degrees.end());
    //making this array to keep track of which nodes can be coloured at any point
    //in graph
    vector<int>canColor(graph.size(),true);
    //assgning unique colour number to every colour
    int colorNo=1;
    //until all nodes are visited in degrees array
    while(!degrees.empty()){
        //only degrees[0] accessed as we will operate on top node and then delete it
        //degrees[0].second stores original node number
        //degrees[0].first stores degree of that node


        //if it is allowed to colour as we cannot colour when already coloured
        if(canColor[degrees[0].second]==true){
            //assign the current colour number to that node in answer
            answer[degrees[0].second].color=colorNo;
            //as that node is coloured, we cannot colour it again
            canColor[degrees[0].second]=false;
            //now colouring other nodes with the same colour
            for(int others=1;others<degrees.size();others++){
                //if node neighbour of current node, cannot colour it with same colour

                //but if node is not adjacent and also allowed to colour
                if(graph[degrees[0].second][degrees[others].second]==0 and canColor[degrees[others].second]==true){
                    //colour it
                    answer[degrees[others].second].color=colorNo;
                    //cannot again colour it
                    canColor[degrees[others].second]=false;
                    //now check neighbours of that adjacent node
                    for(int others2=0;others2<degrees.size();others2++){
                        //if any neighbour of neighbour found which is also not adjacent 
                        //of the the original node
                        if(graph[degrees[others].second][degrees[others2].second]!=0
                        and graph[degrees[0].second][degrees[others2].second]==0){
                            //it can also not be visited
                            canColor[degrees[others2].second]=false;
                        }
                    }
                }
            }
            //now for every node which is not adjacent to the original node
            //and remains uncoloured, it can be coloured if previously not after this
            //iteration is completed 
            for(int others=1;others<degrees.size();others++){
                if((graph[degrees[0].second][degrees[others].second]==0) and (answer[degrees[others].second].color==0)){
                    canColor[degrees[others].second]=true;
                }
            }
            //new colour after one node visited
            colorNo++;
        }
        degrees.erase(degrees.begin());
    }
}

int main(){
    // vector <vector<int>> graph = {
    // {0,1,0,0,0,0,0,1,0,0,0},
    // {1,0,0,1,0,0,0,0,0,0,0},
    // {0,0,0,1,0,0,0,0,0,0,0},
    // {0,1,1,0,0,0,0,0,1,0,1},
    // {0,0,0,0,0,1,0,0,0,0,1},
    // {0,0,0,0,1,0,1,0,0,0,0},
    // {0,0,0,0,0,1,0,1,0,0,1},
    // {1,0,0,0,0,0,1,0,1,1,1},
    // {0,0,0,1,0,0,0,1,0,1,0},
    // {0,0,0,0,0,0,0,1,1,0,1},
    // {0,0,0,1,1,0,1,1,0,1,0}
    // };

    vector <vector<int>> graph = {
    {0,1,1,0,1,0,0,0},
    {1,0,0,1,0,1,0,0},
    {1,0,0,1,0,0,1,0},
    {0,1,1,0,0,0,0,1},
    {1,0,0,0,0,1,1,0},
    {0,1,0,0,1,0,0,1},
    {0,0,1,0,1,0,0,1},
    {0,0,0,1,0,1,1,0},
    };
    welshPowell(graph);
    for(int row=0;row<graph.size();row++){
        node temp = *(answer+row);
        cout<<"node: "<<row<<endl;
        cout<<"color: "<<temp.color<<endl;
        cout<<endl;
    }
}