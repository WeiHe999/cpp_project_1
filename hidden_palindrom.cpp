/******************************************************************************

Hidden Palindrome
A palindrome is a word which is the same when read forwards as it is when read backwards. 
For example, mom and anna are two palindromes.
A word which has just one letter, such as a, is also a palindrome.
Given a word, what is the longest palindrome that is contained in the word? 
That is, what is the longest palindrome that we can obtain, if we are allowed to delete 
characters from the beginning and/or the end of the string?

Input Format
The input will consist of one line, containing a sequence of at least 1 and at most 40 lowercase letters.

Output Format
Output the total number of letters of the longest palindrome contained in the input word.

Sample Input 1
banana
Sample Output 1
5

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool is_palindrome(string n)
{
    vector<char> vec1;
    copy(n.begin(), n.end(), back_inserter(vec1));
    vector<char> vec2 (vec1.rbegin(), vec1.rend());
    if (vec1 == vec2) return true;
    else return false;
}

int main()
{
    //string n = "abracadabra";
    string n = "banana";
    // getline(cin, n);
    int maximum1 = 0;
    for (int x = 0; x < n.length() - 1; x++)
    {
        for (int a = x + 1; a < n.length() + 1; a++)
        {
            string substr1 = n.substr(x, a-x);
            bool b = is_palindrome(substr1);
            if (b == true and (a - x) > maximum1)
            {
                maximum1 = a - x;
            }
        }
    }
    cout << maximum1;
    return 0;
}

