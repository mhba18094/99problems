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

//I used a kind of stack approach to generate the string from the tree
//The modified code is of inOrder traversal as charachters had to be read in that way from the tree
vector<char>String = {};
void stringOfTree(Node* root,int index=0){ //I took index as a parameter to check that I am accessing
                                           //root->left or root->right
    if(index==0){//Special case for first node as no bracket required
        String.push_back(root->value);
        stringOfTree(root->left,(2*index)+1);
        stringOfTree(root->right,(2*index)+2);
    }
    //Whenever left node
    else if(index % 2 != 0){
        //On insertion of every left node, we must show addition of new level by adding '('
        String.push_back('(');
        //The value is then added
        String.push_back(root->value);
        //Special cases needs to be considered which are as follows:-
        //when no right node but only left node, add ',)' by myself to cater for missing right node
        if(root->right==NULL and root->left!=NULL){
            stringOfTree(root->left,(2*index)+1);
            String.push_back(',');
            String.push_back(')');
        }
        //when no left node but only right node, add '(' by myself to cater for missing left node
        else if(root->right!=NULL and root->left==NULL){
            String.push_back('(');
            stringOfTree(root->right,(2*index)+2);
        }
        //when both nodes present, simply check for both
        else if(root->right!=NULL and root->left!=NULL){
            stringOfTree(root->left,(2*index)+1);
            stringOfTree(root->right,(2*index)+2);
        }
    }
    else if(index % 2 == 0){
        //'(' already pushed so ',' and 'value' need to be pushed according to the format given in the question
        String.push_back(',');
        String.push_back(root->value);
        //Special cases needs to be considered which are as follows:-
        //when no right node but only left node, add ',)' by myself to cater for missing right node
        if(root->right==NULL and root->left!=NULL){
            stringOfTree(root->left,(2*index)+1);
            String.push_back(',');
            String.push_back(')');
        }
        
        //when no left node but only right node, add '(' by myself to cater for missing left node
        else if(root->right!=NULL and root->left==NULL){
            String.push_back('(');
            stringOfTree(root->right,(2*index)+2);
        }
        //when both nodes present, simply check for both
        else if(root->right!=NULL and root->left!=NULL){
            stringOfTree(root->left,(2*index)+1);
            stringOfTree(root->right,(2*index)+2);
        }
        String.push_back(')');//Add this after whole code of right is executed
    }
}

Node* fromStringToTree(vector <char> String,int count=0,Node* originalRoot,Node* root){
    if(count==String.size()){
        return originalRoot;
    }
    if(count == 0){
        originalRoot = newNode(String[count]);
        count++;
        root = originalRoot;
    }
    if(String[count] == '('){
        count++;
        if(String[count] == ','){
            count++;
            root->right = newNode(String[count]);
            fromStringToTree(String,count+1,originalRoot,root->right);
        }
        else{
            root->left = newNode(String[count]);
            fromStringToTree(String,count+1,originalRoot,root);
        }
    }
    else if(String[count] == ','){
        count++;

    }

}

int main(){
    Node* root = newNode('a');
    root->right = newNode('c');
    root->left = newNode('b');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->left = newNode('f');
    root->right->left->left = newNode('g');

    stringOfTree(root);
    for(char s:String){
        cout<<s;
    }
}