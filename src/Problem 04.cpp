#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a pair of numbers
struct Pair {
    int first;
    int second;
};

// Comparator function to sort pairs based on their second number
bool comparator(Pair p1, Pair p2) {
    return p1.second < p2.second;
}

int maxChainLen(Pair arr[], int n) {
    // Sort pairs based on their second number in increasing order
    sort(arr, arr + n, comparator);

    // Initialize variables to keep track of the length of the longest chain and the ending of the last chain
    int maxLength = 1;
    int lastEnding = arr[0].second;

    // Iterate through the sorted pairs
    for (int i = 1; i < n; i++) {
        // If the first number of the current pair is greater than the ending of the last chain,
        // increment the length of the longest chain and update the ending of the last chain
        if (arr[i].first > lastEnding) {
            maxLength++;
            lastEnding = arr[i].second;
        }
    }

    return maxLength;
}

int main() {
    // Example usage
    Pair pairs1[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n1 = sizeof(pairs1) / sizeof(pairs1[0]);
    cout << "Example 1 Input: " << "{5 24 , 39 60 , 15 28 , 27 40 , 50 90}" << endl;
    cout << "Example 1 Output: " << maxChainLen(pairs1, n1) << endl;

    Pair pairs2[] = { {5, 10}, {1, 11} };
    int n2 = sizeof(pairs2) / sizeof(pairs2[0]);
    cout << "Example 2 Input: " << "{5 10 , 1 11}" << endl;
    cout << "Example 2 Output: " << maxChainLen(pairs2, n2) << endl;

    return 0;
}
