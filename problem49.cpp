#include <iostream>
#include <math.h>
#include <string>
using namespace std;


char newXor(bool v1,bool v2){//from question # 46
    if(v1 == v2){
        return '0';
    }
    return '1';
}

string binaryConvertor(int n,int placeValue=1){
    if(n==0){return "0";}//Special case for this program
    string answer = "";//answer string which will store the binary of the number
    //Instead of constant division by 2 method, I have used place Value method
    //As we know, in place value method, we go from left to right i.e first find the largest number which can be subtracted
    //so first largest number found
    while((placeValue*2)<=n){ 
        placeValue*=2;
    }
    //original number subtracted as if largest number found, we subtract original number from largest found
    n -= placeValue;
    answer+="1";//1 appended in answer
    //Now check until placeValue becomes 1 i.e backtrack all the remaining numbers
    while(placeValue>1){
        placeValue/=2;//place value divided by 2 on every run
        if((n-placeValue)>=0){//if we can subtract placeValue from the remaining number
            answer+="1";//it means that bit must be on so 1 appended
            n -= placeValue;//and n is subtracted
        }
        else{
            answer+="0";//if placeValue cannot be subtracted from the number, then append 0 in string
        }
    }
    return answer;
}

string binaryToGrey(string b){
    string answer = "";
    answer+=b[0];
    for(int c=0;c<b.size()-1;c++){
        int temp = newXor(b[c],b[c+1]);
        //Apparently, the code commented is behaving weirdly as c is storing temp value as '/001' instead of 1
        // char c = temp;
        // answer+=c;

        answer+=temp;
    }
    return answer;
}

int main(){
    string a = binaryConvertor(8);
    cout<<binaryToGrey(a)<<endl;
}