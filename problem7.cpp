// C++ program to illustrate the use
// of the unions
#include <iostream>
#include <variant>
#include <vector>
using namespace std;



// Driver Code
int main()
{
	variant <int,vector<string>> num,array;
	num = 5;
	array = {1,2,3,4,5};
	vector <string> v = get<vector<string>> array;
	for(int c=0; c<v.size();c++){
		cout<<v[c]<<endl;
	}
}
