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

// Comparator function to sort jobs based on their deadline
bool comparator(Job j1, Job j2) {
    return j1.deadline < j2.deadline;
}

vector<int> JobScheduling(Job arr[], int n) {
    // Sort jobs based on their deadlines in non-decreasing order
    sort(arr, arr + n, comparator);

    // Initialize a table to store the maximum profit at each deadline
    vector<int> dp(n + 1, 0);

    // Initialize a table to store the count of jobs scheduled at each deadline
    vector<int> countJobs(n + 1, 0);

    // Iterate over each job
    for (int i = 0; i < n; i++) {
        // Find the latest available slot before the deadline
        int slot = min(n, arr[i].deadline);

        // Find the maximum profit that can be obtained by including or excluding the current job
        for (int j = slot; j >= 1; j--) {
            if (dp[j - 1] + arr[i].profit > dp[j]) {
                dp[j] = dp[j - 1] + arr[i].profit;
                countJobs[j] = countJobs[j - 1] + 1;
            }
        }
    }

    // Find the maximum profit among all deadlines
    int maxProfit = *max_element(dp.begin(), dp.end());
    // Find the number of jobs that can be done to achieve the maximum profit
    int maxJobs = *max_element(countJobs.begin(), countJobs.end());

    return { maxJobs, maxProfit };
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
