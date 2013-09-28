class Solution {
public:
    int paths[101][101];
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        initialize();
        return recurse(m,n);
    }
    int recurse(int m, int n) {
        if (paths[m][n] > 0) return paths[m][n];
        else return paths[m][n] =  recurse(m, n-1) + recurse(m-1, n);
    }
    void initialize() {
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                paths[i][j] = -1;
            }
        }
        for (int i = 1; i < 101; i++) {
            paths[1][i] = 1;
        }
        for (int i = 1; i < 101; i++) {
            paths[i][1] = 1;
        }
    }
};