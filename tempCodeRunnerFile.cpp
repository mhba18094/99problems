
            matrix.push_back(removeFirstVal(v,i));
        }
    }
}

int main(){
    vector<vector<string>>v={{}};
    v.push_back({"a","b"});
    for(int j=0;j<2;j++){
        cout<<v[0][j]<<endl;