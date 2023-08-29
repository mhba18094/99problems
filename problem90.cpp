//code understanding and help taken from https://www.youtube.com/watch?v=KTygpUDUJ6Q
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>board,int i,int j){
    int jRight = j;
    int jLeft = j;
    while(i>=0){
        if((board[i][j]==1) or (jLeft>=0 and board[i][jLeft]==1) or (jRight<board.size() and board[i][jRight]==1)){
            return false;
        }
        i--;
        jRight++;
        jLeft--;
    }
    return true;
}

int queensCombinations(vector<vector<int>>board,int i){
    if(i==board.size()) return 1;
    else{
        int answer=0;
        for(int j=0;j<board[i].size();j++){
            if(isSafe(board,i,j)){
                board[i][j]=1;
                answer+=queensCombinations(board,i+1);
                board[i][j]=0;
            }
        }
        return answer;
    }
}

int main(){
    vector<vector<int>>board(8,vector<int>(8,0));
    cout<<queensCombinations(board,0)<<endl;
}