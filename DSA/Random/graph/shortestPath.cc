#include <bits/stdc++.h>

#include "graph.h"
using namespace std;

struct Data {
    int node;
    int distance;
    Data(int n, int d) {
        this->node = n;
        this->distance = d;
    }
};

vector<int> findShortestPath(int start, vector<vector<int>>& adjList) {
    vector<int> result(adjList.size(), INT_MAX);

    queue<Data*> q;
    q.push(new Data(start, 0));
    result[start] = 0;

    while (!q.empty()) {
        Data* d = q.front();
        q.pop();
        for (auto c : adjList[d->node]) {
            int dist = d->distance + 1;
            if (result[c] > dist) {
                q.push(new Data(c, dist));
                result[c] = dist;
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int>> lst = generateIntAdjcencyList();
    vector<int> result = findShortestPath(1, lst);
    for (auto c : result)
        cout << c << " ";
    return 0;
}