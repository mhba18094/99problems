#include <iostream>

using namespace std;

int main(){
    int array[6] = {1,2,3,4,5,6};
    int length = sizeof(array)/sizeof(array[0]);
    cout<<array[length-1]<<endl;

}