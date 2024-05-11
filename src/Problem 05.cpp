#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a pair of numbers
struct Pair {
    int first;
    int second;
};

// Comparator function to sort pairs based on their first number
bool comparator(Pair p1, Pair p2) {
    return p1.first < p2.first;
}

int maxChainLen(Pair arr[], int n) {
    // Sort pairs based on their first number in increasing order
    sort(arr, arr + n, comparator);

    // Initialize a table to store the length of the longest chain ending at each pair
    vector<int> dp(n, 1);

    // Compute the length of the longest chain ending at each pair
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i].first > arr[j].second && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // Find the maximum length of the chain
    int maxLength = *max_element(dp.begin(), dp.end());

    return maxLength;
}

int main() {
    // Example usage
    Pair pairs1[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n1 = sizeof(pairs1) / sizeof(pairs1[0]);
    cout << "Example 1 Output: " << maxChainLen(pairs1, n1) << endl;

    Pair pairs2[] = { {5, 10}, {1, 11} };
    int n2 = sizeof(pairs2) / sizeof(pairs2[0]);
    cout << "Example 2 Output: " << maxChainLen(pairs2, n2) << endl;

    return 0;
}
