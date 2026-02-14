#include <bits/stdc++.h>

#include "graph.h"
using namespace std;

template <typename T>
void printList(vector<T>& arr) {
    for (auto x : arr) cout << x << " ";
    cout << endl;
}

vector<int> bfs(int start, vector<vector<int>>& adjList) {
    vector<int> result;
    int n = adjList.size() - 1;

    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        for (auto& c : adjList[vertex]) {
            if (!visited[c]) {
                visited[c] = 1;
                q.push(c);
            }
        }
        result.push_back(vertex);
        // printList<bool>(visited);
    }
    return result;
}

void dfsHelper(int n, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& result) {
    visited[n] = 1;
    result.push_back(n);

    for (auto& c : adjList[n]) {
        if (!visited[c]) {
            dfsHelper(c, adjList, visited, result);
        }
    }
}

vector<int> dfs(int start, vector<vector<int>>& adjList) {
    vector<int> result;
    vector<bool> visited(adjList.size(), 0);
    dfsHelper(start, adjList, visited, result);
    return result;
}

int main() {
    auto l = generateIntAdjcencyList();
    auto r = dfs(3, l);
    printList<int>(r);
    return 0;
}