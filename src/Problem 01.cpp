#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a meeting
struct Meeting {
    int start;
    int end;
    int index; // To keep track of original index
};

// Comparator function to sort meetings based on their end times
bool comparator(Meeting m1, Meeting m2) {
    return m1.end < m2.end;
}

int maxMeetings(int start[], int end[], int n) {
    // Create a vector of meetings
    vector<Meeting> meetings(n);
    for (int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].index = i + 1; // Assigning index to meetings
    }

    // Sort meetings based on their end times
    sort(meetings.begin(), meetings.end(), comparator);

    // Initialize variables to store result and previous meeting's end time
    int count = 1;
    int prev_end = meetings[0].end;

    // Iterate over meetings to find maximum number of meetings
    for (int i = 1; i < n; i++) {
        if (meetings[i].start > prev_end) {
            count++;
            prev_end = meetings[i].end;
        }
    }

    return count;
}

int main() {
    // Example usage
    int start1[] = { 1, 3, 0, 5, 8, 5 };
    int end1[] = { 2, 4, 6, 7, 9, 9 };
    int n1 = sizeof(start1) / sizeof(start1[0]);
    cout << "Example 1 Output: " << maxMeetings(start1, end1, n1) << endl;

    int start2[] = { 10, 12, 20 };
    int end2[] = { 20, 25, 30 };
    int n2 = sizeof(start2) / sizeof(start2[0]);
    cout << "Example 2 Output: " << maxMeetings(start2, end2, n2) << endl;

    return 0;
}
