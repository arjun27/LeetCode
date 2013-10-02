class Solution {
public:
    int maxArea(vector<int> &h) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = h.size();
        int m = min(h[0], h[n-1]) * (n-1);
        int l = 0, r = n-1;
        while (l < r) {
            if (h[l] < h[r]) {
                l++;
                m = max(m, min(h[l], h[r]) * (r-l));
            } else {
                r--;
                m = max(m, min(h[l], h[r]) * (r-l));
            }
        }
        return m;
    }
};