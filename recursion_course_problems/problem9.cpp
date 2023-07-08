#include <iostream>
#include <vector>
using namespace std;

vector<string> possibleBinaries={};

void generateBinariesWithTwoZeros(int totalBits,int numOfZeros=0,string binary=""){
    if(numOfZeros > 2){
        return;
    }
    if(binary.size()==totalBits){
        possibleBinaries.push_back(binary);
        cout<<binary<<", ";
    }
    else{
        generateBinariesWithTwoZeros(totalBits,numOfZeros+1,binary+"0");
        generateBinariesWithTwoZeros(totalBits,numOfZeros,binary+"1");
    }
}

int main(){
    generateBinariesWithTwoZeros(4);
}