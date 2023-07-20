#include <iostream>
#include <vector>
using namespace std;

struct Node{
    public:
        int item;
        Node* left;
        Node* right;
};

Node* newNode(int value){
    Node* node = new Node();
    node->item = value;
    node->left = NULL;
    node->right = NULL;
}

vector<Node*>allPossibleCompleteBinaryTrees ={};

void findAllPossibleCompleteBinaryTrees(int numberOfNodes,vector<int>values){
    for(int maxTrees=0;maxTrees<numberOfNodes;maxTrees++){
        Node* rootNode;
        for(unsigned int value=0;value<values.size();value++){
            if(value==0){
                rootNode = newNode(values[value]);
                allPossibleCompleteBinaryTrees.push_back(rootNode);
            }
            else if(value%2==0){
                
            }
        }
    }
}