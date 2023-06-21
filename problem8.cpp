// more pointers
#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

vector <string> removeConsecutiveDuplicates(vector <string> arr){
    //For loop to traverse full array(vector)
    for(int c = 1; c<arr.size();c++){
        string previous = arr[c-1]; //Stores previous element to check for repitition
        if (previous == arr[c]){   
            arr.erase(arr.begin()+c);   //When an element is same to that element, it is removed
            c--;    //counter is decremented because wwhen an element is removed, the counter position of current element remains the same
            //loop will automatically incremented to point to the same counter position
        }
    }
    return arr;
}
int main (){
    vector <string> arr = {"a","b","c","d","e"};
    arr = removeConsecutiveDuplicates(arr);
    cout<<"[ ";
    for (int c = 0; c<arr.size();c++){
        cout<<arr[c]<<", ";
    }
    cout<<"]"<<endl;
}