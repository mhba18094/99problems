vector<pair<int,int>>answer = possibleLocations(board,2,7);
    for(int c=0;c<answer.size();c++){
        board[answer[c].first][answer[c].second]=1;
    }