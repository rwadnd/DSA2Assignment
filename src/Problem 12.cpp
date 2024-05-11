#include <iostream>
#include <vector>

using namespace std;

int numberSequence(int m, int n) {
    // Initialize a 2D DP array
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base case: For length 1, there is only 1 sequence ending with each number from 1 to m
    for (int j = 1; j <= m; j++)
        dp[1][j] = 1;

    // Populate the DP array
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= j / 2; k++) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    // Calculate the total number of special sequences of length n
    int total = 0;
    for (int j = 1; j <= m; j++)
        total += dp[n][j];

    return total;
}

int main() {
    // Example usage
    int m1 = 10, n1 = 4;
    cout << "Example 1 Output: " << numberSequence(m1, n1) << endl;

    int m2 = 5, n2 = 2;
    cout << "Example 2 Output: " << numberSequence(m2, n2) << endl;

    return 0;
}
