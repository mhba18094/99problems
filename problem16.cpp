#include <iostream>
#include <vector>

using namespace std;

vector <string> drop(vector <string> v,int n){
    for (int c=n-1; c<v.size();c+=n){
        v.erase(v.begin()+c);
    }
    return v;
} 

int main(){
    vector <string> array = {"a","b","c","c","d"};
    array = drop(array,2);
    cout<<"{";
    for (string s:array){
        cout<<s<<",";
    }
    cout<<"}";
}