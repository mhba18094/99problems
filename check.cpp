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


bool checkBST(Node* root) {
		if(root->right == NULL and root->left == NULL){
            return true;
        }
        else if (root->left!=NULL and root->right == NULL){
            if(root->left<root){
                return checkBST(root->left);
            }
            else{
                return false;
            }
        }
        else if (root->left==NULL and root->right != NULL){
            if(root->right>root){
                return checkBST(root->right);
            }
            else{
                return false;
            }
        }
        else{
            if(root->left<root){
                if(root->right>root){
                    return (checkBST(root->left) and checkBST(root->right));
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        
	}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout<<checkBST(root);
}