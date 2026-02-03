#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0;
        map<vector<int>, int> columnsCounter;
        for (int i = 0; i < grid.size(); i++) {
            vector<int> arr;
            for (int j = 0; j < grid.size(); j++) {
                arr.push_back(grid[j][i]);
            }
            columnsCounter[arr]++;
        }
        for (int i = 0; i < grid.size(); i++) {
            count += columnsCounter[grid[i]];
        }
        return count;
    }
};

int main() {
    Solution* s = new Solution();
    vector<vector<int>> grid = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    grid = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
    cout << (s->equalPairs(grid));
}