#include <iostream>
#include <vector>
#include <string>
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

int height(Node* root){
    if (root==NULL){
        return 0;
    }
    else{
        return 1+max(height(root->left),height(root->right));
    }
}

int count=0;
vector<string>coordinates;
void inOrderNew(Node* root,int* c,int h){
    if (root==NULL){
        return;
    }
    inOrderNew(root->left,c,h);
    count++;
    coordinates.push_back(to_string(root->value) + "(" + to_string(count) + "," + to_string(h-height(root)+1) + ")");
    inOrderNew(root->right,c,h);
}

int main(){
    Node* root = newNode(1);
    root->right = newNode(3);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    inOrderNew(root,&count,height(root));
    for(string coordinate:coordinates){
        cout<<coordinate<<endl;
    }

}