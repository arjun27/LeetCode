class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int uniques = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                A[uniques] = A[i];
                uniques ++;
            } else {
                if (A[i] != A[i-1]) {
                    A[uniques] = A[i];
                    uniques++;
                }
            }
        }
        return uniques;
    }
};