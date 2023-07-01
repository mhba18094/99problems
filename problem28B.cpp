#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char>> lsortFreq(vector<vector<char>> v)
{ // sorting on basis of length frequency(the more the occurance of a length, the later will the row of that length it will occur in returned 2d array)
    // First of all, I am finding the max length of row to identify the length for my new 1d vector
    int largest = v[0].size();
    for (int count = 1; count < v.size(); count++)
    {
        if (v[count].size() > largest)
        {
            largest = v[count].size();
        }
    }
    vector<int> possibleOccurancesOnSizeIndex(largest + 1, 0); // initialising all values of this vector to 0 so that its index is
                                                               // the length of row and value stored at that index is how many times
                                                               // this length is repeated
    for (vector<char> row : v)
    { // updating occurances of length
        possibleOccurancesOnSizeIndex[row.size()]++;
    }
    vector<vector<char>> answer = {};                                                                                // 2d vector to be returned
    int currentOccurance = *max_element(possibleOccurancesOnSizeIndex.begin(), possibleOccurancesOnSizeIndex.end()); // finding the max element from 1d vector
    while (currentOccurance != 0)
    {                                  // ending condition explained later
        int indexFindingOnBasisOfSize; // now as we know, currentOccurance stores max length from 1d vector but we want length of
                                       // row for comparison with given 2d vector v, passed as parameter
        for (int row = 0; row < v.size(); row++)
        { // we will traverse all rows of vector v
            // we will find the index of most occured element which will show us which length occured the most
            indexFindingOnBasisOfSize = find(possibleOccurancesOnSizeIndex.begin(), possibleOccurancesOnSizeIndex.end(), currentOccurance) - possibleOccurancesOnSizeIndex.begin();
            // we compare that length with every row's length of vector v and if that length matches, we add it to the beginning
            // of the answer vector which means the row with the most length comes at the end
            if (v[row].size() == indexFindingOnBasisOfSize)
            {
                answer.insert(answer.begin(), v[row]);
            }
        }
        // after that length's rows are inserted into vector, its index value is changed to 0
        possibleOccurancesOnSizeIndex[indexFindingOnBasisOfSize] = 0;
        // now when the max element will be 0, loop will end as row of every length inserted into answer 2d vector and the returned
        currentOccurance = *max_element(possibleOccurancesOnSizeIndex.begin(), possibleOccurancesOnSizeIndex.end());
    }
    return answer;
}

int main()
{
    vector<vector<char>> v = {
        {'a', 'b', 'c'},
        {'d', 'e'},
        {'d', 'e'},
        {'m'},
        {'o'}};
    v = lsortFreq(v);
    for (vector<char> row : v)
    {
        cout << "[";
        for (char column : row)
        {
            cout << column << ", ";
        }
        cout << "], ";
    }
    cout << endl;
}