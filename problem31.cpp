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

int main(){
    if(checkPrime(4)==1){
        cout<<"is Prime"<<endl;
    }else{
        cout<<"not Prime"<<endl;
    }
}