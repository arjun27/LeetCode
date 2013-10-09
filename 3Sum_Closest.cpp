class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		int n = num.size();
		sort(num.begin(), num.end());
		int closest = target;
		for (int i = 0; i < n; i++) {
			int l = i+1, r = n-1;
			while (l < r) {
				int sum = num[i] + num[l] + num[r];
				if (sum == target) return sum;
				else if (closest == target || (closest != target && abs(sum - target) < abs(closest - target))) {
					closest = sum;
				}
				if (sum < target) l++;
				else r--;
			}
		}
		return closest;
	}
};