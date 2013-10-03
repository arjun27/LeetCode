class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s == NULL) return 0;
        string st(s);
        int len = 0, last = 0;
        for (int i = 0; i < st.length(); i++) {
            if (st[i] == ' ') {
                len = 0;
            } else {
                last = ++len;
            }
        }
        return last;
    }
};