#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's possible to allocate books to students such that no student gets more pages than 'maxPages'
bool isPossible(const vector<int>& A, int N, int M, int maxPages) {
    int students = 1;
    int pages = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > maxPages) // If any book has more pages than 'maxPages', it's not possible
            return false;
        if (pages + A[i] > maxPages) {
            students++;
            pages = A[i];
            if (students > M)
                return false;
        }
        else {
            pages += A[i];
        }
    }
    return true;
}

int findPages(int N, int A[], int M) {
    // Initialize the search space
    int low = A[0]; // Minimum possible maximum number of pages allocated to a student
    int high = 0; // Sum of all pages in all books
    for (int i = 0; i < N; i++) {
        high += A[i];
        low = max(low, A[i]);
    }

    int result = -1;

    // Perform binary search on the search space
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(vector<int>(A, A + N), N, M, mid)) {
            result = mid;
            high = mid - 1; // Search for a smaller maximum number of pages
        }
        else {
            low = mid + 1; // Search for a larger maximum number of pages
        }
    }

    return result;
}

int main() {
    // Example usage
    int N1 = 4, M1 = 2;
    int A1[] = { 12, 34, 67, 90 };
    cout << "Example 1 Output: " << findPages(N1, A1, M1) << endl;

    int N2 = 3, M2 = 2;
    int A2[] = { 15, 17, 20 };
    cout << "Example 2 Output: " << findPages(N2, A2, M2) << endl;

    return 0;
}
