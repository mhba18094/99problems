#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> possibleLocations(vector<vector<int>>board,int row, int column){
    vector<pair<int,int>> answer;
    for(int i = row-2;i < row+3; i++){
        if(i == row-2){
            for(int j = column-1; j < column+2; j=j+2){
                if(i >= 0 and j >= 0 and j < board[i].size() and board[i][j] == 0){
                    answer.push_back(make_pair(i,j));
                }
            }
        }
        else if(i == row-1){
            for(int j = column-2; j < column+3; j=j+4){
                if(i >= 0 and j >= 0 and j < board[i].size() and board[i][j] == 0){
                    answer.push_back(make_pair(i,j));
                }
            }
        }
        else if(i == row+1){
            for(int j = column-2; j < column+3; j=j+4){
                if(i < board.size() and j >= 0 and j < board[i].size() and board[i][j] == 0){
                    answer.push_back(make_pair(i,j));
                }
            }
        }
        else if(i == row+2){
            for(int j = column-1; j < column+2; j=j+2){
                if(i < board.size() and j >= 0 and j < board[i].size() and board[i][j] == 0){
                    answer.push_back(make_pair(i,j));
                }
            }
        }
    }
    return answer;
}


void knightTour(vector<vector<int>>board,int row=0,int column=0,int turn=0){
    vector<pair<int,int>> possibilites = possibleLocations(board,row,column);
    if(possibilites.size()==0){
        if(turn!=63){
            board[row][column]=0;
        }
        else{
            for(int row=0;row<8;row++){
                for(int col=0;col<8;col++){
                    cout<<board[row][col]<<" ";
                }
                cout<<endl;
            }
            return;
        }
    }
    else{
        board[row][column] = turn;
        turn++;
        for(int c=0;c<possibilites.size();c++){
            if(board[possibilites[c].first][possibilites[c].second]==0){
                board[possibilites[c].first][possibilites[c].second]=turn;
                knightTour(board,possibilites[c].first,possibilites[c].second,turn);
            }
        }
    }

}
int main(){
    vector<vector<int>>board(8,vector<int>(8,0));
    // vector<pair<int,int>>answer = possibleLocations(board,2,7);
    // for(int c=0;c<answer.size();c++){
    //     board[answer[c].first][answer[c].second]=1;
    // }
    knightTour(board);
}
