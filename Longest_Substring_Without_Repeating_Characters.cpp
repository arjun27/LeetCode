class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lastOcc[26];
        for (int i = 0; i < 26; i++) {
        	lastOcc[i] = -1;
        }
        int last = -1;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
        	if (lastOcc[s[i] - 'a'] >= 0) {
        		// found
        		if (lastOcc[s[i] - 'a'] > last)
        			last = lastOcc[s[i] - 'a'];
        		lastOcc[s[i] - 'a'] = i;
        	} else {
        		lastOcc[s[i] - 'a'] = i;
        	}
        	maxLen = max(maxLen, i-last);
        }
        return maxLen;
    }
};