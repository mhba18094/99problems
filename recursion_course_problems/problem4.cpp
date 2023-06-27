//reversing a string problem

#include <iostream>
using namespace std;

string reverseString(string s){
    if(s.size()==1){
        return s;
    }
    return s[s.size()-1]+reverseString(s.substr(0,s.size()-1));
}

int main(){
    cout<<reverseString("inside code")<<endl;
}