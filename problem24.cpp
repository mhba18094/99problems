#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector <int> lotto(int n, int upperlimit){
    vector <int> answer={};
    int offset=1,range=upperlimit;
    for (int c=0;c<n;c++){
        answer.push_back(offset+(rand()%range));
    }
    return answer;
    
}

int main(){
    srand((unsigned)time(NULL));
    vector <int> v = lotto(6,49);
    cout<<"{";
    for (int i:v){
        cout<<i<<",";
    }
    cout<<"}\n";
}