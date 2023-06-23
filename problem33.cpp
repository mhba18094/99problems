#include <iostream>
using namespace std;

int gcd(int first,int difference,int answer=1,int divisor=1){
    if(divisor>first){ //base case for recursion
        return answer; //return answer part which will be the gcd
    }
    else if((first%divisor == 0)and(difference%divisor == 0)){ //when both of the numbers divide by the divisor
        return gcd(first,difference,divisor,divisor+1); //update answer with new number 
    }
    else if((first%divisor != 0)or(difference%divisor != 0)){//when any one of the number does not divide by divisor
        return gcd(first,difference,answer,divisor+1); //answer will be same but divisor will be incremented to check for further numbers
    }
}

int main(){
    int firstNum,secondNum;
    cout<<"Enter first number for gcd(must be smaller from next number): ";
    cin>>firstNum;
    cout<<"Enter second number for gcd(must be larger than first number): ";
    cin>>secondNum;
    int difference = secondNum-firstNum;
    if (difference<firstNum){
        if (gcd(difference,firstNum)==1){
            cout<<"is coPrime";
        }
        else{
            cout<<"not coPrime";
        }
    }else{
        if (gcd(firstNum,difference)==1){
            cout<<"is coPrime";
        }
        else{
            cout<<"not coPrime";
        }
    }
}