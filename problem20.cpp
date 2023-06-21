#include <iostream>
using namespace std;
#include <vector>

pair <vector <string>,string> removeAt(int position,vector <string> v){//pair used as an alternate to tuple in python
    string temp = v[position];
    v.erase(v.begin()+position);
    return make_pair(v,temp);//pair containing vector after removal and element removed is returned
}

int main(){
    vector <string> array = {"a","b","c","d","e","f","g","h","i","j","k"};
    pair <vector<string>,string> p = removeAt(1,array);
    cout<<"(";
    cout<<"{";
    for (string s:p.first){
        cout<<s<<",";
    }
    cout<<"},";
    cout<<p.second;
    cout<<"),\n";
}