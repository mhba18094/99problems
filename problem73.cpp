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

void lispyTree(Node* root){
    if(root->subtrees.empty()){ //whenever no child
        cout<<root->value;//simply print the node
    }
    else{ //if child present 
        cout<<"("; //add bracket also
        cout<<root->value; //print that node

        //traverse all childs
        for(int childno = 0;childno<root->subtrees.size();childno++){
            lispyTree(root->subtrees[childno]); //passing child turn by turn
            if(childno==root->subtrees.size()-1){ //whenever last child traversed, end the bracket
                cout<<")";
            }
        }

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
    
    lispyTree(root);

}