#include <bits/stdc++.h>
using namespace std;

void printMat(vector<vector<int>>& mat) {
    for (auto const& row : mat) {
        for (auto& ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
}

int main() {
    // store graph

    int n, e, n1, n2;
    cin >> n >> e;
    // way 1
    vector<vector<int>> adjMat(n + 1, vector<int>(n + 1, 0));
    // way 2
    vector<vector<int>> adjList(n + 1);

    for (int i = 0; i < e; i++) {
        cin >> n1 >> n2;

        // way 1
        adjMat[n1][n2] = 1;
        adjMat[n2][n1] = 1;

        // way 2
        adjList[n1].push_back(n2);
        adjList[n2].push_back(n1);
    }
    cout << "matrix--" << endl;
    printMat(adjMat);
    cout << "list--" << endl;
    printMat(adjList);

    return 0;
}