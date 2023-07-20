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

vector <int> internalNodes = {};
void internalList(Node* root){
    if(root->left ==NULL and root->right==NULL){
        return;
    }
    else if(root->left == NULL and root->right != NULL){
        internalNodes.push_back(root->value);
        internalList(root->right);
    }
    else if(root->left != NULL and root->right == NULL){
        internalNodes.push_back(root->value);
        internalList(root->left);
    }
    else{
        internalNodes.push_back(root->value);
        internalList(root->left);
        internalList(root->right);
    }
}

int main(){
    Node* root = newNode(1);
    root->right = newNode(2);
    root->left = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    internalList(root);
    for(int node:internalNodes){
        cout<<node<<" ";
    }
}