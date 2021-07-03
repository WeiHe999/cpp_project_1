/******************************************************************************

def find_min_node(costs, visited):
    minimum_node = None
    minimum_cost = float('inf')
    for x in costs.keys():
        if x not in visited and costs[x] < minimum_cost:
            minimum_node = x
            minimum_cost = costs[x]
    return minimum_node

def dijkstra(start_node, end_node, graph):
    list_nodes = sorted(list(graph.keys()))
    costs = {}
    for x in graph.keys():
        if x == start_node:
            costs[x] = 0
        else:
            costs[x] = float('inf')
    
    parents = {}
    parents[start_node] = None
    visited = []
    while True:
        min_node = find_min_node(costs, visited) 
        if min_node == None:
            break
        visited.append(min_node)
        for x in graph[min_node].keys():
            c = costs[min_node] + graph[min_node][x]
            if c < costs[x]:
                costs[x] = c
                parents[x] = min_node
    return costs[end_node]

# test case
graph = {}
graph['A'] = {}
graph['A']['B'] = 3
graph['A']['C'] = 6
graph['B'] = {}
graph['B']['C'] = 4
graph['B']['D'] = 4
graph['C'] = {}
graph['C']['D'] = 8
graph['D'] = {}
dijkstra('A', 'D', graph)

# function to complete the leaf nodes in a weighted graph 
def complete_weighted_graph(graph):
    list_keys = list(graph.keys())
    for x in list_keys:
        for a in graph[x]:
            if a not in list_keys:
                graph[a] = {}
    return graph

# user input:
4 5 # 4 nodes 5 edges
A B 3.0
A C 6.0
B C 4.0
B D 4.0
C D 8.0

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <limits>
using namespace std;

string find_min_node(unordered_map <string, float> costs, vector <string> visited)
{
    string minimum_node = "None";
    float minimum_cost = numeric_limits<float>::infinity();
    for (const auto x : costs)
    {
        if (find(visited.begin(), visited.end(), x.first) == visited.end() && costs[x.first] < minimum_cost)
        {
            minimum_node = x.first;
            minimum_cost = costs[x.first];
        }
    }
    return minimum_node;
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

// # function to complete the leaf nodes in a weighted graph 
// def complete_weighted_graph(graph):
//     list_keys = list(graph.keys())
//     for x in list_keys:
//         for a in graph[x]:
//             if a not in list_keys:
//                 graph[a] = {}
//     return graph
    
unordered_map < string, unordered_map<string, float> > complete_weighted_graph(
    unordered_map < string, unordered_map<string, float> > graph)
{
    vector <string> list_keys;
    for (const auto x : graph)
    {
        list_keys.push_back(x.first);
    }
    for (const auto x : graph)
    {
        for (const auto a : graph[x.first])
        {
            if (find(list_keys.begin(), list_keys.end(), a.first) == list_keys.end())
            {
                graph[a.first] = unordered_map <string, float> {};
            }
        }
    }
    
    return graph;
}

int main()
{
    
    // step 1: create the weighted graph
    // unordered_map < string, unordered_map<string, int> > graph;
    // graph["A"] = unordered_map<string, int> {{"B", 3}, {"C", 6}};
    // graph["B"] = unordered_map<string, int> {{"C", 4}, {"D", 4}};
    // graph["C"] = unordered_map<string, int> {{"D", 8}};
    // graph["D"] = unordered_map<string, int> {};
    
    // get user input to construct a weighted graph
//     4 5 # 4 nodes 5 edges
// A B 3.0
// A C 6.0
// B C 4.0
// B D 4.0
// C D 8.0
    unordered_map < string, unordered_map<string, float> > graph;
    string a;
    getline(cin, a);
    vector <string> vec1 = split(a);
    for (int x = 0; x < stoi(vec1[1]); x++)
    {
        string line;
        getline(cin, line);
        vector <string> vec1 = split(line);
        if (graph.find(vec1[0])==graph.end()) 
        {
            graph[vec1[0]] = unordered_map<string, float> { {vec1[1], stof(vec1[2]) } };
            
        }
        else
        {
            graph[vec1[0]].insert( {vec1[1], stof(vec1[2]) } );
        }
        
    }
    //complete the graph
    graph = complete_weighted_graph(graph);
    //print the graph
    for (const auto x : graph)
    {
        cout << x.first << ": ";
        for (const auto y : graph[x.first])
        {
            cout << y.first << ", " << y.second << " ";
        }
    }
    cout << "\n";
    
    vector<string> list_nodes;
    for (const auto x : graph)
    {
        list_nodes.push_back(x.first);
    }
    string start_node = "A";
    string end_node = "D";
    unordered_map <string, float> costs;
    for (const auto a : list_nodes)
    {
        if (a == start_node)
        {
            costs[a] = 0;
        }
        else
        {
            costs[a] = numeric_limits<float>::infinity();
        }
    }
    unordered_map <string, string> parents;
    parents[start_node] = "None";
    vector <string> visited {};
    while (true)
    {
        string min_node = find_min_node(costs, visited);
        if (min_node == "None") break;
        visited.push_back(min_node);
        for (const auto a : graph[min_node])
        {
            float c = costs[min_node] + graph[min_node][a.first];
            if (c < costs[a.first])
            {
                costs[a.first] = c;
                parents[a.first] = min_node;
            }
        }
    }
    cout << "The min cost from " << start_node << " to " << end_node + " is " << costs[
        end_node] << "." << "\n";
    return 0;
}





