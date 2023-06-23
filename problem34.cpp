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

int totient(int n){
    int count = 0;
    for (int c=1;c<n;c++){
        if(gcd(c,n)==1){
            count++;
        }
    }
    return count;
}

int main(){
    int num;
    cout<<"Enter number for which you want to find euler totient function: ";
    cin>>num;
    cout<<"Euler Totient function is: "<<totient(num)<<endl;
}