#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if the given cell is valid to move to
bool isValid(int x, int y, int N, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && !visited[x][y]);
}

// Function to recursively find all possible paths from source to destination
void findPaths(int x, int y, int N, vector<vector<int>>& maze, vector<vector<bool>>& visited, string path, vector<string>& result) {
    // Base case: If the current cell is the destination, add the path to the result
    if (x == N - 1 && y == N - 1) {
        result.push_back(path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Possible directions: up, down, left, right
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };
    char direction[] = { 'U', 'D', 'L', 'R' };

    // Explore all possible directions
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(newX, newY, N, maze, visited)) {
            findPaths(newX, newY, N, maze, visited, path + direction[i], result);
        }
    }

    // Backtrack: Mark the current cell as unvisited
    visited[x][y] = false;
}

vector<string> printPath(int N, vector<vector<int>>& m) {
    vector<string> result;
    if (m[0][0] == 0 || m[N - 1][N - 1] == 0) // If source or destination is blocked
        return result;

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    findPaths(0, 0, N, m, visited, "", result);
    sort(result.begin(), result.end()); // Sort paths lexicographically
    return result;
}

int main() {
    // Example usage
    vector<vector<int>> maze1 = { {1, 0, 0, 0},
                                 {1, 1, 0, 1},
                                 {1, 1, 0, 0},
                                 {0, 1, 1, 1} };
    int N1 = 4;
    vector<string> paths1 = printPath(N1, maze1);
    if (paths1.empty()) {
        cout << "-1" << endl;
    }
    else {
        for (const string& path : paths1) {
            cout << path << " ";
        }
        cout << endl;
    }

    vector<vector<int>> maze2 = { {1, 0},
                                 {1, 0} };
    int N2 = 2;
    vector<string> paths2 = printPath(N2, maze2);
    if (paths2.empty()) {
        cout << "-1" << endl;
    }
    else {
        for (const string& path : paths2) {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}
