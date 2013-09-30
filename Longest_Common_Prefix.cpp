class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = strs.size();
        if (n == 0) return "";
        for (int i = 0; i < n; i++) {
            if (strs[0].length() == 0) return "";
        }
        return recurse(strs, 0);    
    }
    string recurse(vector<string> &strs, int index) {
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            if (strs[0].length() <= index) return "";
        }
        char now = strs[0][index];
        string nowstr(1, now);
        for (int i = 0; i < n; i++) {
            if (now != strs[i][index]) return "";
        }
        string result = nowstr + recurse(strs, index+1);
        return result;
    }
};
