#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> lsort(vector<vector<char>>v){
    for(int count=1;count<v.size();count++){
        vector <char> key = v[count];
        int jCounter;
        for(jCounter=count-1;jCounter>=0 and key.size()<v[jCounter].size();jCounter--){
            v[jCounter+1]=v[jCounter];
        }
        cout<<jCounter<<endl;
        v[jCounter+1]=key;
    }
    return v;
}

int main(){
    vector<vector<char>>v = {
        {'a','b','c'},
        {'d','e'},
        {'f','g','h'},
        {'d','e'},
        {'i','j','k','l'},
        {'m','n'},
        {'o'}
    };
    v = lsort(v);
    for(vector<char>row:v){
        cout<<"[";
        for(char column:row){
            cout<<column<<", ";
        }
        cout<<"], ";
    }
    cout<<endl;

}