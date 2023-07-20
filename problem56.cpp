//Not my own code but taken from stack overflow as was unable to derive code by myself

#include <iostream>
#include <vector>
using namespace std;

struct Node{ //Tree node blueprint
    public:
    int item;
    Node* left;
    Node* right;
    Node(int value){
        item = value;
        left=right=NULL;
    }
};

Node* newNode(int value){
    Node* root = new Node(value);
    return root;
}

//Solution function
bool checkSymmetric(Node* left,Node* right){  //Taking left and right nodes to check for mirror image. Value not important for tree to prove mirror in this case
    if(left==NULL or right==NULL){ //when any one node (being compared) is NULL or both NULL
        return left==NULL&&right==NULL; //If both NULL then mirror image will return true else return false
    }
    //If both nodes exist then sub-problem implemented that which again checks left and right nodes of left->left and right->right
    //and then left->right and right->left 
    //e.g we have a tree 
    //          1
    //         / \
    //        2   2
    //       /     \
    //      3       3
    //we will get first comapare root->left = 2 and root->right = 2
    //which will further check root->left->left and root->right->right and will return true
    //then it will check root->left->right and root->right->left and return true
    //at the end will return true
    return checkSymmetric(left->left,right->right) 
    && checkSymmetric(left->right,right->left);
}

int main(){
    Node* root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->right->right = newNode(4);
    cout<<checkSymmetric(root->left,root->right)<<endl;
}