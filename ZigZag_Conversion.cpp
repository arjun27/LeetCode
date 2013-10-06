class Solution {
public:
    string convert(string s, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        if (n == 1) return s;
        stringstream ss;
        for (int i = 0; i < n; i++) {
            // printing ith row
            int start = i;
            int rows_below = n - 1 - i;
            int rows_above = i;
            int inc_below = 2*rows_below - 1;
            int inc_above = 2*rows_above - 1;
            if (inc_below > 0 && inc_above > 0) {
                bool below = true;
                int j = start;
                while (j < s.length()) {
                    ss<<s[j];
                    if (below) {
                        j += inc_below+1;
                        below = false;
                    } else {
                        j += inc_above+1;
                        below = true;
                    }
                }
            } else {
                int inc = max(0, max(inc_below, inc_above))+1;
                int j = start;
                while (j < s.length()) {
                    ss<<s[j];
                    j += inc;
                }
            }
        }
        string o; ss>>o;
        return o;
    }
};