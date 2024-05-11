#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    int N = arr1.size();
    int M = arr2.size();

    // Make sure arr1 is smaller or equal in size compared to arr2
    if (N > M)
        return kthElement(arr2, arr1, k);

    int low = max(0, k - M);
    int high = min(k, N);

    while (low <= high) {
        int cut1 = low + (high - low) / 2;
        int cut2 = k - cut1;

        int leftMax1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int leftMax2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int rightMin1 = (cut1 == N) ? INT_MAX : arr1[cut1];
        int rightMin2 = (cut2 == M) ? INT_MAX : arr2[cut2];

        if (leftMax1 <= rightMin2 && leftMax2 <= rightMin1) {
            return max(leftMax1, leftMax2);
        }
        else if (leftMax1 > rightMin2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1;
        }
    }

    return -1; // Shouldn't reach here
}

int main() {
    // Example usage
    vector<int> arr1 = { 2, 3, 6, 7, 9 };
    vector<int> arr2 = { 1, 4, 8, 10 };
    int k1 = 5;
    cout << "Example 1 Output: " << kthElement(arr1, arr2, k1) << endl;

    vector<int> arr3 = { 100, 112, 256, 349, 770 };
    vector<int> arr4 = { 72, 86, 113, 119, 265, 445, 892 };
    int k2 = 7;
    cout << "Example 2 Output: " << kthElement(arr3, arr4, k2) << endl;

    return 0;
}