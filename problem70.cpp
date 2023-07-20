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

void toString(Node* root){
    if(root->subtrees.empty()){
        return;
    }
    for(Node* child : root->subtrees){
        cout<<child->value;
        toString(child);
        cout<<"^";
    }
}

int main(){
    // Node* root = newNode('a');
    // root->subtrees = {newNode('b'),newNode('c'),newNode('d')};
    // root->subtrees[0]->subtrees = {newNode('e'),newNode('f'),newNode('g')};
    // root->subtrees[1]->subtrees = {newNode('h'),newNode('i'),newNode('j')};
    // root->subtrees[2]->subtrees = {newNode('k'),newNode('l')};

    Node* root = newNode('a');
    root->subtrees = {newNode('f'),newNode('c'),newNode('b')};
    root->subtrees[0]->subtrees = {newNode('g')};
    root->subtrees[2]->subtrees = {newNode('d'),newNode('e')};
    cout<<root->value;
    toString(root);
}