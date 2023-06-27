//checking if a string has adjacent duplicates

#include <iostream>
using namespace std;

bool hasAdjacentDuplicates(string s,char prev=' '){
    if(prev == s[0]){
        return true;
    }
    else if(s.size()==1){
        return false;
    }
    else if(prev != s[0]){
        return hasAdjacentDuplicates(s.substr(1,s.size()-1),s[0]);
    }
}

int main(){
    string s = "aa";
    hasAdjacentDuplicates(s)==1?cout<<"The word "<<s<<" has adjacent duplicate"<<endl: cout<<"The word "<<s<<" has no adjacent duplicate"<<endl;
}