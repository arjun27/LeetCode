class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ones = 0, twos = 0, bitmask = 0;
        for (int i = 0; i < n; i++) {
            twos = twos | (ones & A[i]);
            ones = ones ^ A[i];
            bitmask = ~(ones & twos);
            ones &= bitmask;
            twos &= bitmask;
        }
        return ones;
    }
};