//making all possible phrases from words in 2d array words must be in order of rows of array


#include <iostream>
#include <vector>
using namespace std;

void allPhrases(vector<vector<string>>v,int i,vector<string>phrase){
    if (i==v.size()){
        {
        for (int c = 0; c < phrase.size(); c++)
        {
            cout << phrase[c] << " ";
        }
        cout << endl;
    }
    }
    else{
        for(string s:v[i]){
            phrase.push_back(s);
            allPhrases(v,i+1,phrase);
            phrase.pop_back();
        }
    }
}

int main(){
    vector <vector <string>> v = {
        {"John","Tom","Jack"},
        {"cooks","eats"},
        {"chicken","rice","spaghetti","fish"}
    };
    vector<string>temp;
    allPhrases(v,0,temp);
}