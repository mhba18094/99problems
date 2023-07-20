#include <iostream>
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


int leafCount(Node* root){
    if(root->left ==NULL and root->right==NULL){
        return 1;
    }
    else if(root->left == NULL and root->right != NULL){
        return leafCount(root->right);
    }
    else if(root->left != NULL and root->right == NULL){
        return leafCount(root->left);
    }
    else{
        return leafCount(root->left)+leafCount(root->right);
    }
}

int main(){
    Node* root = newNode(1);
    root->right = newNode(2);
    root->left = newNode(3);
    root->left->left = newNode(4);
    // root->left->right = newNode(5);
    cout<<leafCount(root)<<endl;
}