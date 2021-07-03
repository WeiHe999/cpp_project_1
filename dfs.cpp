/******************************************************************************

# note: need to define a global list: visited=[]
def dfs(graph, node):
    if node not in visited:
        visited.append(node)
        neighbours = graph[node]
        for x in neighbours:
            dfs(graph, x)

# test
graph = {}
graph[0] = [1, 2]
graph[1] = [0, 3, 4]
graph[2] = [0, 3]
graph[3] = [1, 2, 4]
graph[4] = [1, 3]

visited = []
dfs(graph, 0)
print(visited)
# [0, 1, 3, 2, 4]
*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;
vector<int> visited;
void dfs(unordered_map<int, vector<int> > graph, int start_node)
{
    if (find(visited.begin(), visited.end(), start_node) == visited.end())
    {
        visited.push_back(start_node);
        for (const int x : graph[start_node])
        {
            dfs(graph, x);
        }
    }
}

/*
test case:
input:
4 # the number of nodes, 4 lines followed
1 2 3 # node 1 has neighbors of 2 and 3
2 4 # node 2 has neighbors of 4
3 4 # node 3 has neighbors of 3
4 # node 4 has no neighbor
*/

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

int main()
{
    // use getline to get user input
    // and then construct the unordered_map graph
    string str1;
    getline(cin, str1);
    int n = stoi(str1);
    unordered_map<int, vector<int> > graph;
    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);
        vector<int> vec1 = split(line);
        if (vec1.size() > 1)
        {
            vector<int> slice_of_vec(vec1.begin() + 1, vec1.end());
            graph[vec1[0]] = slice_of_vec;
        }
        else
        {
            vector<int> slice_of_vec;
            graph[vec1[0]] = slice_of_vec;
        }
    }
    
    // vector<int> v1 = {2, 3};
    // vector<int> v2 = {4};
    // vector<int> v3 = {4};
    // vector<int> v4 = {};
    // graph[4] = v4;
    // graph[3] = v3;
    // graph[2] = v2;
    // graph[1] = v1;
    dfs(graph, 1);
    for (const auto x : visited)
    {
        cout << x << " ";
    }
}









