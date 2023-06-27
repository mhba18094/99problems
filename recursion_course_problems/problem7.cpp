#include <iostream>
#include <vector>
using namespace std;

vector <vector<char>>combinationArray = {
    {'+'},
    {','},
    {'A','B','C'},
    {'D','E','F'},
    {'G','H','I'},
    {'J','K','L'},
    {'M','N','O'},
    {'P','Q','R','S'},
    {'T','U','V'},
    {'W','X','Y','Z'}
};

void telCombinations(string nums,vector<vector<char>>v,int i,vector<char>letter){
    if(i>=nums.size()){
        {
        for (int c = 0; c < letter.size(); c++)
        {
            cout << letter[c] << " ";
        }
        cout << endl;
    }
    }
    else{
        int temp = int(nums[i])-48;
        for(char j: v[temp]){
            letter.push_back(j);
            telCombinations(nums,v,i+1,letter);
            letter.pop_back();
        }
    }
}

int main(){
    string num = "374";
    vector<char>temp;
    telCombinations(num,combinationArray,0,temp);
}