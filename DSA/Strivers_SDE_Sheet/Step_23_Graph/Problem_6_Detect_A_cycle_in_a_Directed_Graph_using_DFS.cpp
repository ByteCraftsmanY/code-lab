// Detect A cycle in a Directed Graph using DFS
// Step: Graph
// Difficulty: Hard
// Post Link: https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-topological-sort-kahns-algorithm-g-23/
// LeetCode Link: https://leetcode.com/problems/course-schedule/
// GFG Link: None

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& adjList, vector<int>& path, vector<int>& visited) {
    visited[node] = 1;
    path[node] = 1;

    for (auto i : adjList[node]) {
        if (!visited[i]) {
            if (dfs(i, adjList, path, visited)) {
                return true;
            }
        } else if (path[node]) {
            return true;
        }
    }

    path[node] = 0;
    return false;
}

bool hasCycle(vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<int> path(n, 0), visited(n, 0);
    return dfs(1, adjList, path, visited);
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
                            {3, 1}
                            // {2, 4},
                            // {4, 3},
                            // {4, 6},
                            // {6, 7},
                        },
                        adjList = generateAdjList(edges, 7);
    cout << hasCycle(adjList);
    return 0;
}
