#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.length();
        vector <int> ways (n);
        ways[0] = 1;
        int first = (s[0] - '0') * 10 + (s[1] - '0');
        if (first <= 26)
            ways[1] = 2;
        else 
            ways[1] = 1;
        for (int i = 2; i < n; i++) {
            int now = (s[i-1] - '0') * 10 + (s[i] - '0');
            if (now <= 26)
                ways[i] = ways[i-1] + ways[i-2];
            else
                ways[i] = ways[i-1];
        }
        return ways[n-1];
    }
};

int main() {
    Solution sol;
    cout<<sol.numDecodings("3612")<<endl;
    return 0;
}