#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

vector <pair<int,int>> primeFactors(int n){
    vector<pair<int,int>> answer={};//pair returned to show output as tuple
    //loop until divisor value is smaller or equal to number (which will change whenever it will be divided by a prime factor)
    for (int divisor = 2;divisor<=n;divisor++){//division must start from 2 so divisor's initial value is 2
        bool found=false;//status checker to indicate element already present
        if(n%divisor==0){ //if number divides
            for(int count=0;count<answer.size();count++){//for every pair present in answer array
                if(answer[count].first==divisor){ //if the divisor is already present
                    ++answer[count].second; //then increment its occurance count
                    found=true;//found status flag updated
                    count=answer.size();//loop exited
                }
            }
            if(!found){//if the element is not found
                answer.push_back(make_pair(divisor,1)); //divisor pushed into answer array
            }
            n/=divisor--;//n is divided with current divisor's value and then divisor is decremeneted 
                         //after this line so when it is incremented after this line, due to loop,
                         //its value does not change as same number can divide multiple times
        }
    }
    return answer;
}

int totient(int n){
    vector<pair<int,int>>primeFactorsWithMultiplicities = primeFactors(n);
    int answer=1;
    for(pair<int,int>factor:primeFactorsWithMultiplicities){
        answer*=((factor.first-1) * pow(factor.first,factor.second-1));
    }
    return answer;
}

int main(){
    int num;
    cout<<"Enter number for which you want to find euler totient function: ";
    cin>>num;
    auto start = high_resolution_clock::now();
    cout<<"Euler Totient function is: "<<totient(num)<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by function : "<< duration.count() << " microseconds"<<endl;
}