#include <iostream>
using namespace std;
#include <vector>

vector <string> slice(int i,int k,vector<string> v){
    vector <string> answer={};//contains the sliced vector
    for(int c=0;c<v.size();c++){
        if(c>=i and c<k){ //i<=c<k does not work in cpp
            answer.push_back(v[c]);
        }
    }
    return answer;
}

int main(){
    vector <string> array = {"a","b","c","d","e","f","g","h","i","j"};
    array = slice(3,7,array);
    cout<<"{";
    for (string s:array){
        cout<<s<<",";
    }
    cout<<"}";
}