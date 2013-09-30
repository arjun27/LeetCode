class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> braces;
        int last = -1; // last position of ')'
        int maxLen = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') braces.push(i);
            else {
                if (!braces.empty()) {
                    braces.pop();
                    if (braces.empty()) maxLen = max(maxLen, i-last);
                    else maxLen = max(maxLen, i-braces.top());
                } else {
                    // nothing to pop
                    last = i;
                }
            }
        }
        return maxLen;
    }
};