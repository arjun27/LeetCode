class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // recursive: nCr = n-1Cr + n-1Cr-1
        vector<vector<int> > res = builder(n, k, 1);
        for (int i = 0; i < res.size(); i++) {
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
    vector<vector<int> > builder(int n, int k, int start) {
        vector<vector<int> > res;
        if (k == 0 || start > n) return res;
        if (k == 1) {
            while (start <= n) {
                vector<int> row(1, start++);
                res.push_back(row);
            }
            return res;
        }
        if (k == n-start+1) {
            vector<int> row;
            while (start <= n) row.push_back(start++);
            res.push_back(row);
            return res;
        }
        vector<vector<int> > first = builder(n, k, start+1);
        vector<vector<int> > second = builder(n, k-1, start+1);
        if (second.size() > 0) {
            for (int i = 0; i < second.size(); i++) {
                second[i].push_back(start);
            }
        } else {
            vector<int> one(1, start);
            second.push_back(one);
        }
        first.insert(first.end(), second.begin(), second.end());
        return first;
    }
};
