// https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
using namespace std;

void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;

    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    auto isSafe = [&grid, &visited, &n, &m](int nr, int nc) -> bool {
        return nr >= 0 &&
               nr < n &&
               nc >= 0 &&
               nc < m &&
               grid[nr][nc] == '1' &&
               !visited[nr][nc];
    };
    
    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        i = p.first, j = p.second;
        for (auto direction : directions) {
            int nr = i + direction[0], nc = j + direction[1];
            if (isSafe(nr, nc)) {
                // printf("from {%d,%d} it can go {%d,%d}\n", i, j, nr, nc);
                q.push({nr, nc});
                visited[nr][nc] = 1;
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int n = grid.size(), m = grid[0].size(), count = 0;
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                bfs(i, j, grid, visited);
                count++;
            }
        }
    }
    return count;
}

int main() {
    return 0;
}