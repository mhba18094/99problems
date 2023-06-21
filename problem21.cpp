#include <iostream>
using namespace std;
#include <vector>

vector <string> insertAt(string element,int position,vector <string> v){//pair used as an alternate to tuple in python
    string temp = v[position];
    v.insert(v.begin()+position,element);
    return v;
}

int main(){
    vector <string> array = {"a","b","c","d","e","f","g","h","i","j","k"};
    array = insertAt("f",1,array);

    for (string s:array){
        cout<<s<<",";
    }
}