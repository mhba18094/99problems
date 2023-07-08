#include <iostream>
#include <vector>
using namespace std;

bool wordSearch(vector<vector<char>>board,string word,int index,int row,int column,vector<vector<bool>>visited){
    if(index==word.size()){
        return true;
    }
    else if((row<0 or row>=board.size()) or (column<0 or column>=board[0].size()) or (visited[row][column]==true) or (word[index]!=board[row][column])){
        return false;
    }
    else{
        visited[row][column]=true;
        if(
            (wordSearch(board,word,index+1,row,column+1,visited)) or
            (wordSearch(board,word,index+1,row,column-1,visited)) or
            (wordSearch(board,word,index+1,row-1,column,visited)) or
            (wordSearch(board,word,index+1,row+1,column,visited))
        ){
            return true;
        }
        else{
            visited[row][column]=false;
            return false;
        }
    }
}

int main(){
    vector<vector<char>> board = {
        {'k','i','n','t'},
        {'b','i','n','s'},
        {'g','n','y','i'},
        {'u','o','e','d'},
        {'d','i','b','v'},
        {'h','i','r','t'}
    };
    vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
    for(int row=0;row<board.size();row++){
        for(int column=0;column<board[0].size();column++){
            if(wordSearch(board,"inside",0,row,column,visited)){
                cout<<"present"<<endl;
            }
        }
    }
}