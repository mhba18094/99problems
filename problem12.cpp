#include <iostream>
#include <vector>
using namespace std;

vector<pair <int,string>> packed(vector <string> vec){ //taking original vector and returning 1D vector containing count and element paired
    int count=0; //variable to store number of consecutive occurences of an element
    string temp=""; //Will store repeating element
    vector <pair<int,string>> row; //Will store repeating element and number of occurences and this will be appended to 2D List
    for (string element:vec){   
        if(element!=temp){  //when element not equal to temporary element i.e element not being repeated
            row.push_back(make_pair(count,temp)); //row will contain the element and count of element
            temp = element; //replace temporary with that repeating element so that next repeating element can be catered
            count=0; //count of element restarted
        }
        count++;
    }
    row.push_back(make_pair(count,temp));//Making of last pair which was missed above
    return row;
}

vector <string> uncompressed(vector <pair<int,string>> v){ //returning an uncompressed array by taking a tuple
    vector <string> answer;
    for(pair<int,string>element:v){ //For each element
        for(int c=0;c<element.first;c++){//Loop to append element in returning array number of times its count is
            answer.push_back(element.second);
        }
    }
    return answer;
}

int main(){
    vector <string> array = {"a","a","b","b","c","c","d"};
    vector <pair<int,string>> answer = packed(array);
    for (pair<int,string> element:answer){
        if(element.first!=0) cout<<"("<<element.first<<","<<element.second<<"),";
    }
    array = uncompressed(answer);
    cout<<"{";
    for (string s:array){
        cout<<s<<",";
    }
    cout<<"}";
}