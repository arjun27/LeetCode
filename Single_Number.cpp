class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n == 0) return 0;
        sort(A, A+n);
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) s += A[i];
            else s -= A[i];
        }
        return s;
    }
};