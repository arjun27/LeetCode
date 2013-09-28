class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> maxEndsHere; maxEndsHere.resize(n);
        maxEndsHere[0] = A[0];
        for (int i = 1; i < n; i++) {
            maxEndsHere[i] = max(maxEndsHere[i-1], 0) + A[i];
        }
        return *max_element(maxEndsHere.begin(), maxEndsHere.end());
    }
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
};