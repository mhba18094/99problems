#include <iostream>
#include <vector>
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

vector<int> listPrimesInRange(int start,int end){
    vector <int> answer;
    for(int count=start;count<=end;count++){
        if(checkPrime(count)){
            answer.push_back(count);
        }
    }
    return answer;
}

int main(){
    vector<int> solution = listPrimesInRange(7,31);
    for(int c:solution){
        cout<<c<<", ";
    }
    cout<<endl;
}