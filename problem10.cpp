#include <iostream>
#include <vector>
using namespace std;

//Returning a 2D array containing sublists. No other way found to make 1D lists dynamically and then return them 


vector<vector<pair <int,string>>> packed(vector <string> vec){ //taking original vector and returning 2D vector
    vector <vector<pair <int,string>>>answer;
    int count=0; //variable to store number of consecutive occurences of an element
    string temp=""; //Will store repeating element
    vector <pair<int,string>> row; //Will store repeating element and number of occurences and this will be appended to 2D List
    for (string element:vec){   
        if(element!=temp){  //when element not equal to temporary element i.e element not being repeated
            row.push_back(make_pair(count,temp)); //row will contain the element and count of element
            temp = element; //replace temporary with that repeating element so that next repeating element can be catered
            answer.push_back(row); //Pair is appended to 2D list which will be returned
            row.clear(); //row is cleared so that next repeating element can be stored
            count=0; //count of element restarted
        }
        count++;
    }
    row.push_back(make_pair(count,temp));//Making of last pair which was missed above
    answer.push_back(row); //Added so that last sublist can be appended
    return answer;
}


int main(){
    vector <string> vec = {"a","a","a","b","c","c","c","d","e","a","a","e"};
    vector<vector<pair <int,string>>> result = packed(vec);
    for(int c =1; c<result.size(); c++){
        cout<<"(";
        for(int d =0; d<result[c].size(); d++){
            cout<<result[c][d].first<<", ";
            cout<<result[c][d].second;
        }
        cout<<")";
    }
    cout<<endl;
}