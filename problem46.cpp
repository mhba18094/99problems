#include <iostream>
using namespace std;

bool newNot(bool v1){
    if(v1==false)return true;
    return false;
}

bool newAnd(bool v1,bool v2){
    if(v1 == false or v2 == false){
        return false;
    }
    return true;
}

bool newOr(bool v1,bool v2){
    if(v1 == false and v2 == false){
        return false;
    }
    return true;
}

bool newXor(bool v1,bool v2){
    if(v1 == v2){
        return false;
    }
    return true;
}

bool newNand(bool v1,bool v2){
    if(v1 == false and v2 == false){
        return true;
    }
    else if(v1==true and v2==true){
        return false;
    }
    return true;
}

bool newNor(bool v1,bool v2){
    if(v1 == false and v2 == false){
        return true;
    }
    else if(v1==true or v2==true){
        return false;
    }
}

bool newImplication(bool v1, bool v2){
    return newOr(newNot(v1),v2);
}

bool newEquality(bool v1, bool v2){
    if(v1==v2)return true;
    return false;
}

int main(){
    cout<<" A       B       result"<<endl;
    for(int column1=0;column1<2;column1++){
        for(int column2=0;column2<2;column2++){
            cout<<" "<<column1<<"       "<<column2<<"       "<<newXor(column1,column2)<<endl;
        }
    }
}