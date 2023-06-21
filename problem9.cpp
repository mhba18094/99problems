#include <iostream>
#include <vector>
using namespace std;

//Returning a 2D array containing sublists. No other way found to make 1D lists dynamically and then return them 


vector<vector<string>> packed(vector <string> vec){ //taking original vector and returning 2D vector
    vector <vector<string>>answer;
    string temp=""; //Will store repeating element
    vector <string> row; //Will store sublist of repeating element and this will be appended to 2D List
    for (string element:vec){   
        if(element!=temp){  //when element not equal to temporary element i.e element not being repeated
            temp = element; //replace temporary with that repeating element so that next repeating element can be catered
            answer.push_back(row); //Sublist is appended to 2D list which will be returned
            row.clear(); //row is cleared so that next repeating element can be stored
        }
        row.push_back(element); //element must be entered in row to make sublist of repeating element
    }
    answer.push_back(row); //Added so that last sublist can be appended
    return answer;
}


int main(){
    vector <string> vec = {"a","a","a","b","c","c","c","d","e","a","a","e"};
    vector <vector <string>>result = packed(vec);
    for(int c =1; c<result.size(); c++){
        cout<<"[";
        for(int d =0; d<result[c].size(); d++){
            cout<<result[c][d]<<", ";
        }
        cout<<"]";
    }
    cout<<endl;
}