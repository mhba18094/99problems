#include <iostream>
using namespace std;

int sumOfDigits(int num){
    if (num/10 == 0){
        return num;
    }
    return (num%10)+sumOfDigits(num/10);
}

int main(){
    cout<<"Sum of 999 is: "<<sumOfDigits(123)<<endl;
}