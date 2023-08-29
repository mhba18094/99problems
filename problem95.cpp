#include <iostream>
#include <vector>
using namespace std;

void fullWords(int number){
    vector<string>dict={
        "zero","one","two","three","four",
        "five","six","seven","eight","nine"
    };
    vector<string>answer;
    int divisor = 1;
    while(number!= 0){
        int digit = number%10;
        
        answer.push_back(dict[digit]);
        number/=10;
    }

    for(int c=answer.size()-1;c>-1;c--){
        cout<<answer[c]<<"-";
    }
}   
int main(){
    fullWords(21742421);
}