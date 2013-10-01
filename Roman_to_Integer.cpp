class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> val;
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
        return romanToInt(s, 0, s.length()-1, val);
    }
    int romanToInt(string s, int start, int end, map<char, int> &val) {
        if (end < start) return 0;
        if (end == start) return val[s[start]];
        int sign = 1;
        if (val[s[start+1]] > val[s[start]]) sign = -1;
        return (sign*val[s[start]]) + romanToInt(s, start+1, end, val);
    }
};