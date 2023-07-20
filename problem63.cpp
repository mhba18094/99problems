#include <iostream>
#include <math.h>
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

void createBinaryTreeOneLevel(int numberOfNodes,int valueOfAll,Node* root,int* count,int level){
    if(*count==numberOfNodes){
        return;
    }
    if(level==1){
        root->left = newNode(*count);
        *count=*count+1;
        if(*count==numberOfNodes) return;
        else{ 
            root->right = newNode(*count);
            *count=*count+1;
            }
    }
    else{
        createBinaryTreeOneLevel(numberOfNodes,valueOfAll,root->left,count,level-1);
        createBinaryTreeOneLevel(numberOfNodes,valueOfAll,root->right,count,level-1);
    }
    
    
}

Node* createFullBinaryTree(int numberOfNodes,int valueOfAll){
    Node* root = newNode(0);
    if(numberOfNodes>1){
        int count=1;
        for(int level=1;count<numberOfNodes;level++){
            createBinaryTreeOneLevel(numberOfNodes,valueOfAll,root,&count,level);
            cout<<"done"<<endl;
        }
    }
    return root;
    
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
    Node* root = createFullBinaryTree(15,1);
    preOrderTraversal(root);
}