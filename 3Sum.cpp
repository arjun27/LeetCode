class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		int n = num.size();
		sort(num.begin(), num.end());
		vector<vector<int> > res;
		for (int i = 0; i < n-2; i++) {
		    if (i > 0 && num[i] == num[i-1]) continue;
			int toSum = 0 - num[i];
			int l = i+1, r = n-1;
			while (l < r) {
				if (num[l] + num[r] == toSum) {
					int a[] = { num[i], num[l], num[r] };
					res.push_back(vector<int>(a, a+3));
					while (l < num.size() && num[l] == a[0]) l++;
					while (r >= 0 && num[r] == a[2]) r--;
				} else if (num[l] + num[r] < toSum)
					l++;
				else 
					r--;
			}
		}
		return res;
	}
};