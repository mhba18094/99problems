#include <iostream>
#include <vector>
using namespace std;
//incomplete

struct Node{
    char value;
    Node* left;
    Node* right;
    Node(int v){
        value = v;
        left=right=NULL;
    }
};

Node* newNode(char value){
    Node* root = new Node(value);
    return root;
}

void toDotString(Node* root){
    if(root==NULL){
        cout<<".";
    }
    else{
        cout<<root->value;
        toDotString(root->left);
        toDotString(root->right);
    }
}

int main(){
    Node* root = newNode('a');
    root->right = newNode('c');
    root->left = newNode('b');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->right = newNode('f');
    root->right->right->left = newNode('g');
    toDotString(root);
}