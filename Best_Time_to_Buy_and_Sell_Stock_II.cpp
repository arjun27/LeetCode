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
        int sum = 0;
        for (int i = 0; i < diffs.size(); i++) {
            if (diffs[i] > 0) sum += diffs[i];
        }
        return sum;
    }
};