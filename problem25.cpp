#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <algorithm>

int main(){
    srand((unsigned)time(NULL)); //seed value of srand set to a a value which will always change unlike '1' by default
    vector <string> array = {"a","b","c","d","e","f","g","h"};
    vector <string> answer={};
    for(int c=0;array.size()!=answer.size();c++){
        int offset = 0;
        int range = array.size();
        string temp = array[(offset + rand()%range)];
        while(find(answer.begin(),answer.end(),temp)!=answer.end()){//checking whether element exists already in array
            temp = array[(offset + rand()%range)];
        }
        answer.push_back(temp);
    }
    cout<<"{";
    for (string i:answer){
        cout<<i<<",";
    }
    cout<<"}\n";
}