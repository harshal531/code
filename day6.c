#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> findZeroSumSubarrays(vector<int>& arr) {
    unordered_map<long long, vector<int>> prefixMap; // prefixSum -> list of indices
    vector<pair<int,int>> result;
    long long prefixSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // If prefixSum itself is zero, subarray from 0 to i
        if (prefixSum == 0) {
            result.push_back({0, i});
        }

        // If prefixSum was seen before
        if (prefixMap.find(prefixSum) != prefixMap.end()) {
            for (int startIndex : prefixMap[prefixSum]) {
                result.push_back({startIndex + 1, i});
            }
        }

        // Store index for this prefixSum
        prefixMap[prefixSum].push_back(i);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};
    vector<pair<int,int>> res = findZeroSumSubarrays(arr);

    cout << "Output: [";
    for (int i = 0; i < res.size(); i++) {
        cout << "(" << res[i].first << ", " << res[i].second << ")";
        if (i < res.size() - 1) cout << ", ";
    }
    cout << "]\n";
    return 0;
}
