//function to return number of occurences of a given number in a given array

#include <iostream>
#include <vector>
using namespace std;

int occurrences(vector <int> arr,int numToFind){
    if(arr.size()==0){
        return 0;
    }
    if (arr[0]==numToFind){
        arr.erase(arr.begin());
        return 1+occurrences(arr,numToFind);
    }
    else if (arr[0]!=numToFind){
        arr.erase(arr.begin());
        return 0+occurrences(arr,numToFind);
    }
}

int main(){
    vector <int> v = {1,2,1,3,1,2};
    cout<<"Occurences of 0 are: "<<occurrences(v,0)<<endl;
}