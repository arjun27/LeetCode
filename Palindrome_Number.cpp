class Solution {
public:
    bool isPalindrome(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string s;
        stringstream ss;
        ss<<x;
        s = ss.str();
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n-1-i]) return false;
        }
        return true;
    }
};