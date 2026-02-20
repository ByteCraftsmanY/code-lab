// Topological Sort DFS
// Step: Graph
// Difficulty: Hard
// Post Link: https://takeuforward.org/data-structure/topological-sort-using-dfs/
// LeetCode Link: https://practice.geeksforgeeks.org/problems/topological-sort/1
// GFG Link: https://practice.geeksforgeeks.org/problems/topological-sort/1

// https://claude.ai/share/9963230c-1bf5-4fe8-a365-7b8282299bd4

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited, stack<int>& st) {
    visited[node] = 1;
    for (auto i : adjList[node]) {
        if (!visited[i]) {
            dfs(i, adjList, visited, st);
        }
    }
    // explore all the dependents once
    st.push(node);
}

vector<int> getTopologicalOrder(vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<int> visited(n + 1, 0);
    stack<int> st;
    for (int i = 1; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adjList, visited, st);
        }
    }
    vector<int> res;
    while (st.empty() == false) {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

vector<vector<int>> generateAdjList(vector<vector<int>>& edges, int nodes) {
    vector<vector<int>> adjList(nodes + 1);
    for (auto& r : edges) {
        adjList[r[0]].push_back(r[1]);
    }
    return adjList;
}

int main() {
    vector<vector<int>> edges = {
                            {1, 2},
                            {2, 3},
                            {3, 4},
                            {3, 5},
                            {4, 6},
                            {5, 6},
                        },
                        adjList = generateAdjList(edges, 6);
    vector<int> res = getTopologicalOrder(adjList);
    for (auto x : res) {
        cout << x << " ";
    }
    return 0;
}
