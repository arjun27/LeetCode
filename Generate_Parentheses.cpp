class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> empty;
        return builder(empty, n, n);
    }
    vector<string> builder(vector<string> &old, int open, int close) {
        vector<string> res;
        // assert close >= old
        if (close < open) return old;
        if (open == 0) {
            for (int j = 0; j < old.size(); j++) {
                for (int i = 0; i < close; i++) {
                    old[j] = old[j] + ")";
                }
                res.push_back(old[j]);
            }
            return res;
        }
        // open > 0 and close > 0
        if (open == close) {
            if (old.size() > 0) {
                for (int i = 0; i < old.size(); i++)
                    res.push_back(old[i] + "(");
            } else
                res.push_back("(");   
            return builder(res, open-1, close);
        }
        if (old.size() > 0) {
            for (int i = 0; i < old.size(); i++) {
                res.push_back(old[i] + "(");
            }
        } else 
            res.push_back("(");
        vector<string> go_right = builder(res, open-1, close);
        res.resize(0);
        if (old.size() > 0) {
            for (int i = 0; i < old.size(); i++) {
                res.push_back(old[i] + ")");
            }
        } else 
            res.push_back(")");
        vector<string> go_up = builder(res, open, close-1);
        go_right.insert(go_right.end(), go_up.begin(), go_up.end());
        return go_right;
    }
};