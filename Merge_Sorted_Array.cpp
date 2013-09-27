class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int w = 0;
        int i = 0, j = 0;
        vector<int> A_copy; A_copy.resize(m);
        for (int k = 0; k < m; k++) {
            A_copy[k] = A[k];
        }
        while (i < m && j < n) {
            if (A_copy[i] < B[j]) {
                A[w++] = A_copy[i++];
            } else {
                A[w++] = B[j++];
            }
        }
        if (i == m) {
            while (j < n) {
                A[w++] = B[j++];
            }
        }
        if (j == n) {
            while (i < m) {
                A[w++] = A_copy[i++];
            }
        }
    }
};

// better solution (without copying A): write from end?