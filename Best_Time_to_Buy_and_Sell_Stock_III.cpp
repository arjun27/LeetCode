class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // model as maximum subarray problem
        if (prices.size() <= 1) return 0;
        vector<int> diffs;
        for (int i = 0; i < prices.size() - 1; i++) {
            diffs.push_back(prices[i+1] - prices[i]);
        }
        return max(maxSub(diffs), 0);
    }
    int maxSub(vector<int> &v) {
        int n = v.size();
        vector<int> maxEndsHere; maxEndsHere.resize(n);
        vector<int> maxTillHere; maxTillHere.resize(n);
        maxEndsHere[0] = v[0];
        maxTillHere[0] = v[0];
        for (int i = 1; i < n; i++) {
            maxEndsHere[i] = max(maxEndsHere[i-1], 0) + v[i];
            maxTillHere[i] = max(maxTillHere[i-1], maxEndsHere[i]);
        }
        vector<int> max2Segs; max2Segs.resize(n);
        max2Segs[0] = maxTillHere[0];
        for (int i = 1; i < n; i++) {
            max2Segs[i] = max(max2Segs[i-1], maxTillHere[i-1], 0) + v[i];
        }
        return *max_element(max2Segs.begin(), max2Segs.end());
    }
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
    int max(int a, int b, int c) {
        return max(a, max(b, c));
    }
};