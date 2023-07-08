#include <iostream>
#include <vector>
using namespace std;

vector<string> possibleSubstrings={};

void generateSubstrings(string originalStr,int index=0,string substring=""){
    if(index==originalStr.size()){
        possibleSubstrings.push_back(substring);
    }
    else{
        generateSubstrings(originalStr,index+1,substring+originalStr[index]);
        generateSubstrings(originalStr,index+1,substring);
    }    
}

int main(){
    generateSubstrings("abcd");
    for(string substring:possibleSubstrings){
        cout<<substring<<", ";
    }
    cout<<endl;
}