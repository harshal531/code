#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& arr) {
    // Phase 1: Find intersection point
    int slow = arr[0];
    int fast = arr[0];
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    // Phase 2: Find entrance to cycle
    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main() {
    vector<int> arr = {3, 1, 3, 4, 2};
    cout << "Duplicate number: " << findDuplicate(arr) << endl;
    return 0;
}
// This code finds the duplicate number in an array where each integer is between 1 and n (inclusive)
// and there is exactly one duplicate. It uses Floyd's Tortoise and Hare algorithm to detect the cycle.
// The time complexity is O(n) and the space complexity is O(1).
