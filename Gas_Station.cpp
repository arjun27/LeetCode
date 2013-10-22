class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = gas.size();
        vector<int> savings(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            savings[i] = gas[i] - cost[i];
            sum += savings[i];
        }
        if (sum < 0) return -1;
        int start = 0; sum = 0;
        for (int i = 0; i < n; i++) {
            sum += savings[i];
            if (sum < 0) {
                start = i+1;
                sum = 0;
            }
        }
        return start;
    }
};