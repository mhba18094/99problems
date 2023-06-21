#include <iostream>
#include <vector>
using namespace std;

vector <string> rotateLeft(int n,vector <string> v){
    vector <string> temp;
    if (n>=0){//for normal rotation
        for(int c=0;c<n;c++){//modifying original array 
            temp.push_back(v[0]); //storing rotating elements in temp (in this case first elements)
            v.erase(v.begin()); //erasing those elements from original array
        }
        for(int c=0;c<temp.size();c++){
        v.push_back(temp[c]); //adding those elements in temp array to original array(end of the array)
    }
    }
    else{ //for reverse/right rotation
        n*=-1;
        for(int c=0;c<n;c++){//modifying original array
            temp.push_back(v[v.size()-1]);//storing rotating elements in temp(in this case last elements)
            v.erase(v.begin()+v.size());//erasing those elements from original array
        }
        for(int c=0;c<temp.size();c++){
        v.insert(v.begin(),temp[c]);//adding those elements in temp array to original array(beginning of the array)
    }
    }
    return v;
}   

int main(){
    vector <string> array = {"a","b","c","d","e","f","g","h","i","j","k"};
    array = rotateLeft(-10,array);
    cout<<"{";
    for (string s:array){
        cout<<s<<",";
    }
    cout<<"}";
}