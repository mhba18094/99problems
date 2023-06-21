#include <iostream>
using namespace std;

bool checkPalindrome(string arr[],int length);

int main(){
    string array[5] = {"1","2","3","2","1"};
    cout<<checkPalindrome(array,sizeof(array)/sizeof(array[0]))<<endl;
}

bool checkPalindrome(string arr[],int length){
    int half = length/2;

    //Code which checks from middle to end
    // bool isEven;
    // length%2==0 ? isEven=true:isEven=false;
    // for (int c =0; c<half; c++){
    //     if (isEven){
    //         if(arr[half+c] != arr[half-c-1]){return false;}
    //     }
    //     else{
    //         if(arr[half+c+1] != arr[half-c-1]){return false;}
    //     }
    // }

    //code which checks from ends to middle
    for (int c=0;c<half;c++){//Using the same array so that memory complexity is O(1) for this task
        if(arr[c] != arr[length-c-1]){return false;} 
    }   
    return true;
}