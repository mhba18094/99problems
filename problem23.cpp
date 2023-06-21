#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>

int main(){
    srand((unsigned)time(NULL)); //seed value of srand set to a a value which will always change unlike '1' by default
    vector <string> array = {"a","b","c","d","e","f","g","h"};
    int count;
    cout<<"How many random elements you want to extract? ";
    cin>>count;
    vector <string> answer={};
    for(int c=0;c<count;c++){
        int offset = 0;
        int range = array.size();
        answer.push_back(array[(offset + rand()%range)]);//generating random index and then storing that element in answer vector
    }
    cout<<"{";
    for (string i:answer){
        cout<<i<<",";
    }
    cout<<"}\n";
}