#include <iostream>
#include <vector>
using namespace std;

struct Node{
    public:
    char value;
    vector <Node*> subtrees;
};

Node* newNode(char val){
    Node* node = new Node;
    node->value = val;
    return node;
}

int nodeCount(Node* root){
    if(root->subtrees.empty()){ //if no subtrees/child of a node then return only it count i.e 1
        return 1;
    }
    int count = 0; //else initialise count varible to count all nodes including node and subtrees
    for(Node* child : root->subtrees){ //for every child
        if(count==0){ // if first child traversed
            count += 1+ nodeCount(child);//also add parent's count with the child count
        }
        else{
            count += nodeCount(child); //else only add child's count
        }
    }
    return count; //return count after all childs are traversed
}

int main(){
    Node* root = newNode('a');
    root->subtrees = {newNode('b'),newNode('c'),newNode('d')};
    root->subtrees[0]->subtrees = {newNode('e'),newNode('f'),newNode('g')};
    root->subtrees[1]->subtrees = {newNode('h'),newNode('i'),newNode('j')};
    root->subtrees[2]->subtrees = {newNode('k'),newNode('l')};
    cout<<nodeCount(root)<<endl;

}