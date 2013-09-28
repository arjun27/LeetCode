class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.length();
        if (n == 0) return 0;
        vector <int> ways (n);
        if (canStand(s[0])) ways[0] = 1;
        else ways[0] = 0;
        
        if (canStand(s[1])) {
            // add ways[0]
            ways[1] = ways[0];
        } else {
            // don't add ways[0]
            ways[1] = 0;
        }
        int code = (s[0] - '0') * 10 + (s[1] - '0');
        if (code >= 1 && code <= 26 && s[0] > '0') ways[1] += 1;
        
        for (int i = 2; i < n; i++) {
            if (canStand(s[i])) ways[i] = ways[i-1];
            else ways[i] = 0;
            int code = (s[i-1] - '0') * 10 + (s[i] - '0');
            if (code >= 1 && code <= 26 && s[i-1] > '0') ways[i] += 1*ways[i-2];
        }

        return ways[n-1];
    }
    bool canStand(char a) {
        return (a >= '1' && a <= '9') ? true : false;
    }
};