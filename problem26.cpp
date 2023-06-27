// I used the recursion approach in which we can get all possible combinations of arrays

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> removeFirstVal(vector<char> v, int count)
{ // function to remove first value which I used in order to make different arrays
  // and will traverse through every combination
  // count means how many elements you want to remove from start
    for (int c = 0; c < count; c++)
    {
        v.erase(v.begin());
    }
    return v;
}

void combinations(int k, vector<char> v, vector<vector<char>> matrix = {}, int c = 0, vector<char> letter = {})
{ // only getting k and vector from user
    // k is r from nCr
    // v contains the number on which combination needs to be applied
    // matrix is 2d which will help me make combinations
    // c is for counter which will be for checking that combinations size must be equal to k
    // letter will store combination one by one and will then be used to output the combination

    if (c == 0)
    { // initital value to just make arrays for my approach
        for (int i = 0; i < k; i++)
        { // making subarrays for my 2d arrays
            matrix.push_back(removeFirstVal(v, i));
        }
        combinations(k, v, matrix, c + 1); //
    }
    else if (c > matrix.size() and letter.size() == k)
    { // if c(counter)>number of rows of matrix and also remember this code will generate
      // combinations of different sizes so display elements of letter array when both
      // of these conditions fulfilled
        for (int c = 0; c < letter.size(); c++)
        {
            cout << letter[c] << " ";
        }
        cout << endl;
    }
    else
    { // most important case which is making the combination
        for (char z : matrix[c - 1])
        {                                                                          // Taking every element of matrix
            auto positionOfCurrentIndex = find(v.begin(), v.end(), z) - v.begin(); // taking index position
                                                                                   // of current element of array
                                                                                   // from original vector

            auto positionOfLetterIndex = -1; // setting default value of this in case the vector is empty

            // when vector letter not empty then take position of last element of letter vector from original vector;s index
            if (!letter.empty())
            {
                positionOfLetterIndex = find(v.begin(), v.end(), letter[letter.size() - 1]) - v.begin();
            }
            if (positionOfCurrentIndex <= positionOfLetterIndex) // this equal-to in this code is used to ignore repeated combinations e.g aaa,abb,acc etc.
            // the less than in this code is used to check that for example we get acb but abc has already occured then to ignore the latter
            // combination by checking that the index position of current element (in original vector v) is always greater than the previous one
            {
            } // do nothing if this condtion true

            // if the current element is not being repeated or have occured before
            else
            {
                letter.push_back(z);                       // push back element in letter
                combinations(k, v, matrix, c + 1, letter); // pass letter and now pick element of the next array in 2d array until it reaches
                                                           // the last array
                letter.pop_back(); // when element traversed, then remove it to get other element
            }
        }
    }
}

int main()
{
    combinations(3, {'a', 'd', 'f', 'c', 'b', 'e', 'g'});
}