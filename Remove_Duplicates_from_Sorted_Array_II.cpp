class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1) {
            return 0;
        }
        int write = 1;
        int prev = 0; // prev can be 0 or 1 for write
        for (int i = 1; i < n; i++) {
            if (A[i] == A[i-1]) {
                prev++;
            } else {
                prev = 0;
            }
            if (prev == 0 || prev == 1) {
                A[write++] = A[i];
            }
        }
        return write;
    }
};