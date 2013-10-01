class Solution {
public:
    vector<vector<int> > mins;
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size(); 
        int n = 0;
        if (m > 0) n = grid[0].size();
        else return 0;
        if (n == 0) return 0;
        
        mins.resize(0);
        vector<int> row(n, -1);
        for (int i = 0; i < m; i++) 
            mins.push_back(row);
        
        mins[m-1][n-1] = grid[m-1][n-1];
        for (int i = n-2; i >= 0; i--) {
            mins[m-1][i] = grid[m-1][i] + mins[m-1][i+1];
        }
        for (int i = m-2; i >= 0; i--) {
            mins[i][n-1] = grid[i][n-1] + mins[i+1][n-1];
        }
        
        return minPath(grid, m, n, 0, 0);
    }
    int minPath(vector<vector<int> > &grid, int m, int n, int i, int j) {
        if (mins[i][j] >= 0)
            return mins[i][j];
        int minSum = grid[i][j] + min(minPath(grid, m, n, i, j+1), minPath(grid, m, n, i+1, j));
        return mins[i][j] = minSum;
    }
};