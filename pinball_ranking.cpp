/******************************************************************************

Pinball is an arcade game in which an individual player controls a silver ball by means of flippers, with the objective of accumulating as many points as possible. At the end of each game, the player's score and rank are displayed. The score, an integer between 0 and 1 000 000 000, is that achieved by the player in the game just ended. The rank is displayed as "r of n". n is the total number of games ever played on the machine, and r is the position of the score for the just-ended game within this set.
More precisely, r is one greater than the number of games whose score exceeds that of the game just ended.
Input
You are to implement the pinball machine's ranking algorithm. The first line of input contains a positive integer, t, the total number of games played in the lifetime of the machine. t lines follow, given the scores of these games, in chronological order.
Output
You are to output the average of the ranks (rounded to two digits after the decimal) that would be displayed on the board.
At least one test case will have t ≤ 100. All test cases will have t ≤ 100 000.

Sample Input
5
100
200
150
170
50
Sample Output
2.20

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int a;
    cin >> a;
    vector <int> vec1;
    int s = 0;
    for (int x = 0; x < a; x++)
    {
        int n;
        cin >> n;
        vec1.push_back(n);
        sort(vec1.rbegin(), vec1.rend());
        auto it = find(vec1.begin(), vec1.end(), n);
        int index = it - vec1.begin();
        s += (index + 1);
    }
    float b = s / 1.0;
    cout << fixed << setprecision(2) <<  b / vec1.size();
    return 0;
}


