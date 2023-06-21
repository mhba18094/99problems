#include <iostream>
using namespace std;

int main(){
    int n = 0;
    cout<<"Enter number of elements you want to enter: ";
    cin >> n;
    int *array = new int(n); // dynamically allocating memory
    for(int c=0;c<n;c++){   //Filling array
        cout<<"Enter "<<c+1<<" element: ";
        cin >> *(array+c);
    }
    cout<<endl;
    int en; //Determining element number (en)
    cout<<"Now which element you want to find? ";
    cin>>en;
    cout<<*(array+en-1)<<endl; //Finding and displaying the requested element
    delete [] array;
    array = NULL;
}