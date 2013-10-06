class Solution {
public:
    string countAndSay(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n == 1) return "1";
        string prev = countAndSay(n-1);
        int l = prev.length();
        char last = prev[0];
        int occ = 1;
        stringstream res;
        for (int i = 1; i < l; i++) {
            if (prev[i] != last) {
                res<<occ<<last;
                occ = 1;
                last = prev[i];
            } else {
                occ++;
            }
        }
        if (occ > 0) {
            res<<occ<<last;
        }
        return res.str();
    }
};