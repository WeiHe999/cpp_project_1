#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric> //accumulate
#include <sstream> //istringstream
#include <math.h> //roundf

using namespace std;

template < typename T > 
void print (T t)
{
    for (const auto & e:t)
        cout << e << " ";
      cout << endl;
}

vector<int> split(string str1)
{
    vector<int> vv;
    string word;
    istringstream ss(str1);
    while (getline(ss, word, ' '))
    {
        vv.push_back(stoi(word));
    }
    return vv;
}

int main () {
  // transform string to uppercase and reverse a string 
  cout << "transform string to uppercase and reverse a string" << endl;
  string str1 = "abcdefghijklmnopqrstuvwxyz";
  vector < char >v1;
  transform (str1.begin (), str1.end (), str1.begin (),::toupper);
  reverse (str1.begin (), str1.end ());
  copy (str1.begin (), str1.end (), back_inserter (v1));
  print (v1);

  // find max and min from a vector
  cout << "find max and min from a vector" << endl;
  vector < int >v2 = { 1, 3, 5, 2 };
  v2.emplace_back (6);
  auto it1 = max_element (v2.begin (), v2.end ());
  auto it2 = min_element (v2.begin (), v2.end ());
  cout << "max value: " << *it1 << "\n";
  cout << "max index: " << it1 - v2.begin () << "\n";
  cout << "min value: " << *it2 << "\n";
  cout << "min index: " << it2 - v2.begin () << "\n";


  //transform each element in a vector using lambda function
  cout << "transform each element in a vector using lambda function" << endl;
  vector < int >v3 = { 3, 6, 9, 12, 1 };
  float b = 3;
  transform(v3.begin (), v3.end (), v3.begin(), [b] (int n)
	     {
	     if (n % 3 == 0) return n / 3.0;
	     else return n * 2.0 + b;}
	     );
  print (v3);
  
  //filter elements in a vector
  cout << "filter elements in a vector" << endl;
  vector<int> foo = {25, 15, 5, -5, -15};
  vector<int> bar;
  copy_if(foo.begin(), foo.end(), back_inserter(bar), [](int i){return i>=0;} );
  print(bar);
  
    //vector1 = [1, 4, 6, 2, 7, 9], count the total elements and sum all elements
  vector<int> v4 = {1, 4, 6, 2, 7, 9};
  float s = accumulate(v4.begin(), v4.end(), 0);
  cout << s << " " << v4.size();
  cout << endl;
  
    //practice 1: vector2={9, 6, 9, -3, -15}, keep the positive elements, 
    //and then divided by 3 for each postive element, 
    //and then sort the elements from largest to smallest
    cout << "process and sort vector" << endl;
    vector<int> vec1 = {9, 6, 9, -3, -15};
    vector<int> vec2;
    copy_if (vec1.begin(), vec1.end(), back_inserter(vec2), [](int n){return !(n <= 0);} );
    transform(vec2.begin(), vec2.end(), vec2.begin(), [](int n){return (n / 3);});
    sort(vec2.begin(), vec2.end(), greater<int>());
    for (const auto x : vec2) cout << x << " "; 
    cout << endl;
    
    //vector of pairs and sort on the second element in reverse order
    vector <pair <string, int> > vp = {{"a", 1}, {"b", 4}, {"c", 2}};
    vp.emplace_back(make_pair("d", 5));
    sort(vp.begin(), vp.end(), [](
        pair <string, int> left, pair <string, int> right){return left.second>right.second;});
    for (const pair <string, int> e: vp) cout << e.first << ", " << e.second << endl;
    //extract the first elements into a vector
    vector <string> vs;
    transform(vp.begin(), vp.end(), back_inserter(vs), [](pair <string, int> x){return x.first;});
    print(vs);
    
    //split a string
    cout << "split a string" << endl;
    string str11 = "23 45 345 12";
    vector<int> vv;
    string word;
    istringstream ss(str11);
    while (getline(ss, word, ' '))
    {
        vv.push_back(stoi(word));
    }
    print(vv);
    //string to int, string to float, int to float, float to int
    string s1 = "23.451";
    string s2 = "123";
    double d1 = stod(s1);
    float f1 = stof(s1);
    int int1 = stoi(s2);
    float f2 = round(f1*100)/100; //round to 2 decimal points
    string str_float = to_string(f1) + "/" + s1;
    cout << d1 << " " << f1 << " " << int1 << " " << f2 << endl;
    cout << str_float << endl;
    
    

    
  return 0;
}




