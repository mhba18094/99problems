#include <iostream>
using namespace std;

bool syntaxChecker(string identifier,char previous=' '){
    if(identifier.length()==1){
        if(identifier=="-"){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        if((int(identifier[0])>=65 and int(identifier[0])<=90) or (int(identifier[0])>=97 and int(identifier[0])<=122) or 
        (int(identifier[0])>=48 and int(identifier[0])<=57)){
            return syntaxChecker(identifier.substr(1,identifier.length()-1),identifier[0]);
        }
        else if(identifier[0]=='-'){
            if(previous == '-'){
                return false;
            }
            else{
                return syntaxChecker(identifier.substr(1,identifier.length()-1),identifier[0]);
            }
        }
    }
}

int main(){
    cout<<syntaxChecker("")<<endl;
}