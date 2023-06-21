#include <iostream>
using namespace std;
#include <vector>

int main(){
    vector <int> answer={};
    int start,end;
    cout<<"Starting range? ";
    cin >> start;
    cout<<"Ending range? ";
    cin >> end;
    for(int c=start;c<=end;c++){
        answer.push_back(c);
    }
    cout<<"{";
    for (int i:answer){
        cout<<i<<",";
    }
    cout<<"}\n";
}