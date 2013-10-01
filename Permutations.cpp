class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        vector<vector<int> > res;
        if (n == 0) return res;
        if (n == 1) {
            res.push_back(num);
            return res;
        }
        if (n == 2) {
            vector<int> perm;
            perm.push_back(num[1]); perm.push_back(num[0]);
            res.push_back(num);
            res.push_back(perm);
            return res;
        } 
        int cur = num[n-1];
        num.pop_back();
        vector<vector<int> > perms = permute(num);
        for (int i = 0; i < perms.size(); i++) {
            vector<vector<int> > extendBy = putIn(perms[i], cur);
            res.insert(res.end(), extendBy.begin(), extendBy.end());
        }
        return res;
    }
    vector<vector<int> > putIn(vector<int> perm, int cur) {
        int n = perm.size();
        vector<vector<int> > res;
        // n+1 possible positions for cur
        for (int i = 0; i <= n; i++) {
            vector<int> now;
            int w = 0;
            for (int j = 0; j <= n; j++) {
                if (j == i) {
                    now.push_back(cur);
                } else {
                    now.push_back(perm[w++]);
                }
            }
            res.push_back(now);
        }
        return res;
    }
};