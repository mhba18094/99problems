//Program with memory complexity of O(1)


#include <iostream>
#include <vector>
using namespace std;

vector <string> duplicate(vector <string> arr){
    for(int c=0;c<arr.size();c+=2){
        arr.insert(arr.begin()+c+1,arr[c]);
    }
    return arr;
}

int main(){
    vector <string> array = {"a","b","c","c","d"};
    array = duplicate(array);
    cout<<"{";
    for (string s:array){
        cout<<s<<",";
    }
    cout<<"}";
}