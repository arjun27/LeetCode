class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            rotateRing(matrix, n, i);
        }
    }
    void rotateRing(vector<vector<int> > &matrix, int n, int i) {
        for (int j = 1; j < n-(2*i); j++) {
            rotateRingOnce(matrix, n, i);
        }
    }
    void rotateRingOnce(vector<vector<int> > &matrix, int n, int i) {
        /*
        (i,i) --------- (i,n-1-i)
        |                   |
        |                   |
        |                   |
        |                   |
        (n-1-i,i)------ (n-1-i,n-1-i)
        */
        int topRowRight = matrix[i][n-1-i], lastRowLeft = matrix[n-1-i][i];
        int rightColumnDown = matrix[n-1-i][n-1-i], leftColumnUp = matrix[i][i];
        for (int j = n-1-i; j >= i+2; j--) {
            matrix[i][j] = matrix[i][j-1];
            matrix[n-1-i][n-1-j] = matrix[n-1-i][n-j];
        }
        for (int j = n-1-i; j >= i+2; j--) {
            matrix[j][n-1-i] = matrix[j-1][n-1-i];
            matrix[n-1-j][i] = matrix[n-j][i];
        }
        if (n > 1) {
            matrix[i][i+1] = leftColumnUp; matrix[n-1-i][n-2-i] = rightColumnDown;
            matrix[i+1][n-1-i] = topRowRight; matrix[n-2-i][i] = lastRowLeft;
        }
    }
};