class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) return 1;
        if (n == 2) return 2;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            // i is root
            sum += numTrees(i-1) * numTrees(n-i);
        }
        return sum;
    }
};