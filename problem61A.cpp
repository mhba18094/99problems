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

vector <int> leafs = {};
void leafList(Node* root){
    if(root->left ==NULL and root->right==NULL){
        leafs.push_back(root->value);
    }
    else if(root->left == NULL and root->right != NULL){
        leafList(root->right);
    }
    else if(root->left != NULL and root->right == NULL){
        leafList(root->left);
    }
    else{
        leafList(root->left);
        leafList(root->right);
    }
}

int main(){
    Node* root = newNode(1);
    root->right = newNode(2);
    root->left = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    leafList(root);
    for(int leaf:leafs){
        cout<<leaf<<" ";
    }
}