class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rows = triangle.size();
        vector<int> sums(rows, 0);
        vector<int> nextsums(rows, 0);
        sums[0] = triangle[0][0];
        for (int i = 1; i < rows; i++) {
            // triangle[i] is the row vector
            for (int j = 0; j <= i; j++) {
                if (j == 0) nextsums[j] = sums[j] + triangle[i][j];
                else if (j == i) nextsums[j] = sums[j-1] + triangle[i][j];
                else nextsums[j] = min(sums[j-1], sums[j]) + triangle[i][j];
            }
            sums = nextsums;
            nextsums.resize(0); nextsums.resize(rows);
        }
        return *min_element(sums.begin(), sums.end());
    }
};