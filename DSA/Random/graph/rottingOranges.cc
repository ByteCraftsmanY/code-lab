// https://leetcode.com/problems/rotting-oranges/

#include <bits/stdc++.h>
using namespace std;

class Data {
   public:
    int row, col, time;
    Data(int r, int c, int t) : row(r), col(c), time(t) {
        // cout << "Data: " << r << " " << c << " - " << t << endl;
    }
};

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size(), minTime = 0;
    queue<Data*> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push(new Data(i, j, 0));
                visited[i][j] = 2;
            }
        }
    }

    auto isSafe = [&grid, &visited, &n, &m](int nr, int nc) -> bool {
        return nr >= 0 &&
               nr < n &&
               nc >= 0 &&
               nc < m &&
               grid[nr][nc] == 1 &&
               !visited[nr][nc];
    };
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()) {
        Data* d = q.front();
        q.pop();
        for (auto dir : directions) {
            int nr = d->row + dir[0], nc = d->col + dir[1];
            if (isSafe(nr, nc)) {
                q.push(new Data(nr, nc, d->time + 1));
                visited[nr][nc] = 2;
            }
        }
        minTime = max(minTime, d->time);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return minTime;
}

int main() {
    vector<vector<int>> grid = {{2, 1, 1}, {2, 1, 0}, {0, 0, 1}};
    cout << orangesRotting(grid) << endl;
    return 0;
}