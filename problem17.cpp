#include <iostream>
#include <vector>
using namespace std;

vector <vector<string>> split(vector <string> v,int breakPoint){ //returning a 2d vector which contains splitted vectors
    vector <vector <string>> answer; //return type
    for(int c=0; c<v.size(); c++){  
        if (c<=breakPoint-1){ //until breakpoint, insert in first row of 2d array
            if(c==0){answer.push_back({});} //have to push back brackets as cpp throws segmentation fault if next line directly added
            answer[0].push_back(v[c]);
        }
        else{//when breakpoint is reached, another array is made 
            if(c==breakPoint){answer.push_back({});}
            answer[1].push_back(v[c]);
        }
    }
    return answer; //splitted array is returned
}

int main(){
    vector <string> v = {"1","2","3","4","5","6","7"};
    vector <vector <string>> vect = split(v,3);
    for (int c=0;c<vect.size();c++){
        for(int d=0;d<vect[c].size();d++){
            cout<<vect[c][d]<<" ";
        }
        cout<<endl;
    }
}
