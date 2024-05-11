#include <iostream>
#include <vector>

using namespace std;

// Function to check if it is safe to assign the given color to the vertex
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

// Recursive function to assign colors to vertices using backtracking
bool graphColoringUtil(int v, vector<vector<int>>& graph, vector<int>& color, int M) {
    // Base case: If all vertices are assigned a color, return true
    if (v == graph.size())
        return true;

    // Try assigning colors one by one
    for (int c = 1; c <= M; c++) {
        // Check if it is safe to assign this color to the vertex
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // Assign the color
            // Recur for the next vertex
            if (graphColoringUtil(v + 1, graph, color, M))
                return true;
            // Backtrack: If assigning color c doesn't lead to a solution, try other colors
            color[v] = 0;
        }
    }
    return false; // If no color can be assigned to this vertex
}

bool graphColoring(vector<vector<int>>& graph, int M) {
    vector<int> color(graph.size(), 0); // Initialize color array with 0

    // Call the recursive helper function to assign colors to vertices
    if (!graphColoringUtil(0, graph, color, M))
        return false; // If no solution exists

    return true;
}

int main() {
    // Example usage
    int N1 = 4, M1 = 3;
    vector<vector<int>> graph1 = { {0, 1, 0, 1},
                                   {1, 0, 1, 0},
                                   {0, 1, 0, 1},
                                   {1, 0, 1, 0} };
    cout << "Example 1 Output: " << graphColoring(graph1, M1) << endl;

    int N2 = 3, M2 = 2;
    vector<vector<int>> graph2 = { {0, 1, 1},
                                   {1, 0, 1},
                                   {1, 1, 0} };
    cout << "Example 2 Output: " << graphColoring(graph2, M2) << endl;

    return 0;
}
