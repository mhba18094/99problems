#include <iostream>
#include <vector>
using namespace std;

vector <int> primeFactors(int n){
    vector<int> answer={};
    //loop until divisor value is smaller or equal to number (which will change whenever it will be divided by a prime factor)
    for (int divisor = 2;divisor<=n;divisor++){//division must start from 2 so divisor's initial value is 2
        if(n%divisor==0){ //if number divides
            answer.push_back(divisor); //divisor pushed into answer array
            n/=divisor--;//n is divided with current divisor's value and then divisor is decremeneted 
                         //after this line so when it is incremented after this line, due to loop,
                         //its value does not change as same number can divide multiple times
        }
    }
    return answer;
}

int main(){
    vector <int> factors = primeFactors(112);
    for(int element:factors){
        cout<<element<<" ";
    }
    cout<<endl;
}