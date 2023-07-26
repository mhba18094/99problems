#include <iostream>
using namespace std;


bool checkPrime(int n,int divisor = 2){
    if (divisor == n){
        return true;
    }
    else if(n%divisor==0){
        return false;
    }
    else{return checkPrime(n,divisor+1);}
}

pair<int,int> goldbach(int n){
    int firstNum,secondNum;
    for(int count=2;count<=n;count++){
        if(checkPrime(count)){
            if(checkPrime(n-count)){
                firstNum=count;
                count=n;
            }
        }
    }
    secondNum = n-firstNum;
    return make_pair(firstNum,secondNum);
}

int main(){
    pair<int,int> solution = goldbach(741396);
    cout<<"("<<solution.first<<","<<solution.second<<")"<<endl;
}