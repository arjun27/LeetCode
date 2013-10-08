class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = s.length();
        vector<bool> canBreak(n, false);
        if (dict.find(s.substr(0,1)) != dict.end()) canBreak[0] = true;
        for (int i = 1; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                int l = i-j+1;
                if (i-l < 0 || canBreak[i-l]) {
                    string sub = s.substr(j, l);
                    if (dict.find(sub) != dict.end()) {
                        canBreak[i] = true;
                        break;
                    }
                }
            }
        }
        return canBreak[n-1];
    }
};