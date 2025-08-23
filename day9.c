#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    // Start with the first string as prefix
    string prefix = strs[0];

    // Compare with each string in the array
    for (int i = 1; i < strs.size(); i++) {
        // Reduce prefix until it matches the start of strs[i]
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

int main() {
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Output: " << longestCommonPrefix(strs1) << endl;

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Output: " << longestCommonPrefix(strs2) << endl;

    vector<string> strs3 = {"apple", "ape", "april"};
    cout << "Output: " << longestCommonPrefix(strs3) << endl;

    vector<string> strs4 = {""};
    cout << "Output: " << longestCommonPrefix(strs4) << endl;

    vector<string> strs5 = {"alone"};
    cout << "Output: " << longestCommonPrefix(strs5) << endl;

    return 0;
}
