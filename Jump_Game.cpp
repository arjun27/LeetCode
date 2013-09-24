class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        vector <bool> can; can.resize(n);
        for (; i < n; i++) {
            can[i] = false;
        }
        can[n-1] = true;
        i = n - 2;
        int last = n-1; // last true
        while (i >= 0) {
            if (A[i] + i >= last) {
                can[i] = true;
                last = i;
            }
            i--;
        }
        return can[0];
    }
};

class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector <bool> can; can.resize(n, false);
        can[n-1] = true;
        int i = n - 2;
        int last = n - 1;
        while ( i >= 0 ) {
            if (A[i] + i >= last) {
                can[i] = true;
                last = i;
            }
            i--;
        }
        return can[0];
    }
};