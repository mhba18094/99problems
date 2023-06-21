#include <iostream>
using namespace std;

int main(){
    int n=0;
    cout<<"How many elements you want to enter: ";
    cin >> n;
    int *arr = new int(n);
    for (int c = 0; c<n ; c++){
        cout<<"Enter element # "<<c+1<<": ";
        cin >> arr[c];
    }
    for (int c=0;c<n/2;c++){//Using the same array so that memory complexity is O(1) for this task
        int temp = arr[c]; //Temporarily storing the element at cth position as it will be needed but we will lose the original one
        arr[c] = arr[n-c-1];
        arr[n-c-1] = temp;
    }   
    cout<<"Array reversed is: [";
    for (int c=0;c<n;c++){
        cout<<arr[c]<<", ";
    }
    cout<<"]"<<endl;
}