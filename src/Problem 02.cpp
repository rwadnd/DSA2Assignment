#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int id;
    int deadline;
    int profit;
};

// Comparator function to sort jobs based on their profit
bool comparator(Job j1, Job j2) {
    return j1.profit > j2.profit;
}

vector<int> JobScheduling(Job arr[], int n) {
    // Sort jobs based on their profit in non-increasing order
    sort(arr, arr + n, comparator);

    // Array to keep track of which slots are occupied
    vector<bool> slots(n,false);

    // Variables to store result
    int count = 0;
    int profit = 0;

    // Iterate over sorted jobs
    for (int i = 0; i < n; i++) {
        // Find a slot for the job
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (!slots[j]) {
                slots[j] = true; // Mark slot as occupied
                count++;
                profit += arr[i].profit;
                break;
            }
        }
    }

    return { count, profit };
}

int main() {
    // Example usage
    Job jobs1[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    int n1 = sizeof(jobs1) / sizeof(jobs1[0]);
    vector<int> result1 = JobScheduling(jobs1, n1);
    cout << "Example 1 Input: " << "{(1,4,20),(2,1,10),(3,1,40),(4,1,30)}" << endl;
    cout << "Example 1 Output: " << result1[0] << " " << result1[1] << endl;

    Job jobs2[] = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15} };
    int n2 = sizeof(jobs2) / sizeof(jobs2[0]);
    vector<int> result2 = JobScheduling(jobs2, n2);
    cout << "Example 2 Input: " << "{(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,1,15)}" << endl;
    cout << "Example 2 Output: " << result2[0] << " " << result2[1] << endl;

    return 0;
}
