//Help taken from https://www.programiz.com/dsa/binary-search-tree
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


Node* insertAnElement(int number, Node* root){
    if(root==NULL){
        return newNode(number);
    }
    else if(number>root->value){
        root->right = insertAnElement(number,root->right); //When number > value at current node and NULL appears, it must add it to the right
    }
    else if(number<root->value){
        root->left = insertAnElement(number,root->left); //When number < value at current node and NULL appears, it must add it to the left
    }
    return root; //Node returned at end as all remaining values of tree remain same
}   

void preOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->value<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
int main(){
    Node* root = newNode(6);
    root->right = newNode(10);
    root->left = newNode(4);
    root->left->left = newNode(2);
    root->left->right = newNode(5);
    preOrderTraversal(root);
    cout<<endl;
    insertAnElement(3,root);
    preOrderTraversal(root);

}