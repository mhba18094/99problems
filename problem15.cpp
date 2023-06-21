#include <iostream>
#include <vector>
using namespace std;

vector <string> duplicate(vector <string> arr, int count){
    for(int c=0;c<arr.size();c+=count){//Checking every element and incrementing so that the code checks NEXT element according to the original array
        for(int d=0;d<count-1;d++){//Running code one less than count times as element is already present
            arr.insert(arr.begin()+c+1+d,arr[c]);//Inserting in appropriate position everytime
        }
    }
    return arr;
}

int main(){
    vector <string> array = {"a","b","c","c","d"};
    array = duplicate(array,3);
    cout<<"{";
    for (string s:array){
        cout<<s<<",";
    }
    cout<<"}";
}