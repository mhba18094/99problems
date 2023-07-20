#include <iostream>
#include <vector>
using namespace std;


struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int v){
        value = v;
        left=right=NULL;
    }
};

Node* newNode(int value){
    Node* root = new Node(value);
    return root;
}

vector<int> nodes = {};
void atLevel(Node* root,int level){
    if (root == NULL)
        return;
    if(level == 1){
        nodes.push_back(root->value);
    }
    else{
        atLevel(root->left,level-1);
        atLevel(root->right,level-1);
    }
}

int main(){
    Node* root = newNode(1);
    root->right = newNode(3);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    atLevel(root,2);
    for(int node:nodes){
        cout<<node<<" ";
    }
}