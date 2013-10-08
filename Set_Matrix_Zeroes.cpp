// O(m + n) space

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int c, r = matrix.size();
        if (r > 0) c = matrix[0].size();
        else return;
        vector<bool> rows(r, false);
        vector<bool> cols(c, false);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for (int i = 0; i < r; i++) {
            if (rows[i]) {
                for (int j = 0; j < c; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < c; j++) {
            if (cols[j]) {
                for (int i = 0; i < r; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};