// tricky greedy solution!

class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) return 0;
        int i = 0, steps = 1;
        while (i + A[i] < n-1) {
            int j = i + A[i];
            int max = j + A[j];
            int rmax = j;
            while (j > i) {
                if (j + A[j] > max) {
                    max = j + A[j];
                    rmax = j;
                }
                j--;
            }
            i = rmax;
            steps++;
        }
        return steps;
    }
};
