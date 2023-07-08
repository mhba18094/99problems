// Checking if a binary tree is height balanced in C++

#include <iostream>
#include <algorithm>
using namespace std;

#define bool int

class node {
   public:
  int item;
  node *left;
  node *right;
};

// Create anew node
node *newNode(int item) {
  node *Node = new node();
  Node->item = item;
  Node->left = NULL;
  Node->right = NULL;

  return (Node);
}

int height(node* root){
    if (root==NULL){
        return 0;
    }
    else{
        return 1+max(height(root->left),height(root->right));
    }
}

// Check height balance
bool checkHeightBalance(node *root) {
    if(root==NULL) return true;
    if(abs(height(root->left)-height(root->right))>1){
        return false;
    }
    else{
        return checkHeightBalance(root->left) and checkHeightBalance(root->right);
    }
    return true;
}

int main() {
//   int height = 0;

  node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left = newNode(6);
  root->right->left = newNode(7);
  root->right->right = newNode(8);
  root->right->right->left = newNode(9);
  root->right->right->left->left = newNode(10);


  cout<<checkHeightBalance(root)<<endl;
//   if (checkHeightBalance(root, &height))
//     cout << "The tree is balanced";
//   else
//     cout << "The tree is not balanced";
}