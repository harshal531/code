#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;

    for (string s : strs) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());
        anagramMap[sortedStr].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& pair : anagramMap) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> groups = groupAnagrams(strs);
    
    // Print result
    for (auto& group : groups) {
        cout << "[ ";
        for (auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}
