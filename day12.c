#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        // If it's an opening bracket, push to stack
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } 
        else {
            // If stack is empty, there's no matching opening bracket
            if (st.empty()) return false;

            // Check top of stack for matching pair
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
            st.pop(); // Valid pair found
        }
    }

    // If stack is empty, all brackets were matched
    return st.empty();
}

int main() {
    string s;
    cin >> s;

    if (isValid(s))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
