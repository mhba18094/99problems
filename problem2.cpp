#include <iostream>
using namespace std;

int main(){
    int array[4] = {4,2,5,1};
    int length = sizeof(array)/sizeof(array[0]);
    cout<<array[length-2]<<endl;
}