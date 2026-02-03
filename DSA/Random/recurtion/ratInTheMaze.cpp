/**
 * Rat in a Maze Problem
 *
 * This program finds all possible paths for a rat to reach the destination
 * in a maze where 1 represents a valid path and 0 represents a wall.
 * The rat can move in four directions: Right (R), Down (D), Left (L), Up (U).
 */

#include <bits/stdc++.h>
using namespace std;

// Direction mappings with their corresponding coordinate changes
const map<char, pair<int, int>> DIRECTIONS = {
    {'D', {1, 0}},   // Down: next row, same column
    {'L', {0, -1}},  // Left: same row, previous column
    {'R', {0, 1}},   // Right: same row, next column
    {'U', {-1, 0}}   // Up: previous row, same column
};

/**
 * Helper function to find all valid paths in the maze using DFS
 * @param solutions Vector to store all valid paths
 * @param visited 2D vector to track visited cells
 * @param maze The input maze
 * @param currentPath Current path being explored
 * @param size Size of the maze (n x n)
 * @param row Current row position
 * @param col Current column position
 */
void findPaths(
    vector<string>& solutions,
    vector<vector<bool>>& visited,
    const vector<vector<int>>& maze,
    string currentPath,
    int size,
    int row,
    int col) {
    // Base case: reached destination
    if (row == size - 1 && col == size - 1) {
        solutions.push_back(currentPath);
        return;
    }

    // Check if current position is valid
    if (row < 0 || col < 0 || row >= size || col >= size ||
        maze[row][col] == 0 || visited[row][col]) {
        return;
    }

    // Mark current cell as visited
    visited[row][col] = true;

    // Try all possible directions
    for (const auto& [direction, offset] : DIRECTIONS) {
        int newRow = row + offset.first;
        int newCol = col + offset.second;

        currentPath.push_back(direction);
        findPaths(solutions, visited, maze, currentPath, size, newRow, newCol);
        currentPath.pop_back();
    }

    // Backtrack: mark current cell as unvisited
    visited[row][col] = false;
}

/**
 * Main function to find all valid paths in the maze
 * @param maze The input maze
 * @param size Size of the maze (n x n)
 * @return Vector of all valid paths sorted lexicographically
 */
vector<string> findMazePaths(const vector<vector<int>>& maze, int size) {
    vector<string> solutions;
    vector<vector<bool>> visited(size, vector<bool>(size, false));
    findPaths(solutions, visited, maze, "", size, 0, 0);
    return solutions;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n, 0));
    for (auto& row : maze) {
        for (auto& col : row) {
            cin >> col;
        }
    }
    auto result = findMazePaths(maze, n);
    for (auto path : result) {
        cout << path << endl;
    }
    return 0;
}

/*
    https://www.naukri.com/code360/problems/rat-in-a-maze_1215030?leftPanelTabValue=SUBMISSION
    https://www.youtube.com/watch?v=bLGZhJlt4y0

https://bitbucket.org/samast/discovery-api/pipelines/results/5424/steps/%7Be050bfef-f8bd-4705-b74a-192b966cdb69%7D
    4
    1 0 0 0
    1 1 0 1
    1 1 0 0
    0 1 1 1

*/
