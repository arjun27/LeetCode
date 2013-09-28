class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > pascal; pascal.resize(numRows);
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            if (i == 0 || i == 1) row.push_back(1);
            if (i == 1) row.push_back(1);
            if (i > 1) {
                row.push_back(1);
                for (int j = 1; j <= i - 1; j++) {
                    row.push_back(pascal[i-1][j-1] + pascal[i-1][j]);
                }
                row.push_back(1);
            }
            pascal[i] = row;
        }
        return pascal;
    }
};