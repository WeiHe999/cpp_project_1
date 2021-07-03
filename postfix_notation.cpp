/******************************************************************************

Postfix Notation
 We are familiar with infix notation for representing expressions, 
 where the operator is placed infix between the operands, as in 5 * 5 . 
 Given an expression in postfix notation, such as 5 5 * , 
 evaluate the expression and print it to standard output, rounded to one decimal place.
Valid operands are * (multiplication), / (division), + (addition), - (subtraction), % (mod), 
and ^ (exponentiation).

Input Format
A valid postfix expression. The input will have no more than characters, and the value 
of each number in the input and each intermediate result will be less than or equal to .
Output Format
The result of the evaluation. The answer will be considered correct if its absolute 
or relative error does not exceed .

Sample Input
5 5 +
Sample Output
10.0

Sample Input
5 5 + 6 * 8 -
Sample Output
52.0   

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric> //accumulate
#include <sstream> //istringstream
#include <math.h> //roundf
#include <stack>
#include <iomanip>

using namespace std;

template < typename T > 
void print (T t)
{
    for (const auto & e:t)
        cout << e << " ";
      cout << endl;
}

vector<string> split(string str1)
{
    vector<string> vv;
    string word;
    istringstream ss(str1);
    while (getline(ss, word, ' '))
    {
        vv.push_back(word);
    }
    return vv;
}
int main()
{
    string a;
    getline(cin, a);
    vector<string> vec1 = split(a);
    stack<float> st;
    for (const auto s : vec1)
    {
        if (s!="+" & s!="-" & s!="*" & s!="/" & s!="%" & s!="^") 
        {
            st.push(stof(s));
        }
        else
        {
            float n1 = st.top();
            st.pop();
            float n2 = st.top();
            st.pop();
            if (s == "+")
            {
                st.push(n1 + n2);
            }
            if (s == "-")
            {
                st.push(n2 - n1);
            }
            if (s == "*")
            {
                st.push(n1 * n2);
            }
            if (s == "/")
            {
                st.push(n2 / n1);
            }
            if (s == "%")
            {
                st.push(int(n2) % int(n1));
            }
            if (s == "^")
            {
                st.push(pow(n2, n1));
            }
        }
    }
    float abc = st.top() / 1.0;
    cout << fixed << setprecision(1) << abc;
    return 0;
}





