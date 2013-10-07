class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (ratings.size() == 0) return 0;
        if (ratings.size() == 1) return 1;
        int n = ratings.size();
        vector<int> lcandies(n, 1);
        vector<int> rcandies(n, 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) 
                lcandies[i] = lcandies[i-1] + 1;
        }
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1])
                rcandies[i] = rcandies[i+1] + 1;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(rcandies[i], lcandies[i]);
        }
        return sum;
    }
};