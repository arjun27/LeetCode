class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > grid;
        if (n == 0) return grid;
        vector<int> row(n, 1);
        for (int i = 0; i < n; i++) {
            grid.push_back(row);
        }
        fillGrid(grid, n, 0, 1);
        return grid;
    }
    void fillGrid(vector<vector<int> > &grid, int n, int i, int start) {
        /*
        (i,i) ------------------ (i,n-1-i)
          |                          |
          |                          |
          |                          |
        (n-1-i,i) ---------- (n-1-i,n-1-i)  
        */
        if (n-1-i < i) return;
        if (n-1-i == i) grid[i][i] = start;
        else {
            for (int j = i; j <= n-1-i; j++) grid[i][j] = start++;
            for (int j = i+1; j <= n-1-i; j++) grid[j][n-1-i] = start++;
            for (int j = n-2-i; j >= i; j--) grid[n-1-i][j] = start++;
            for (int j = n-2-i; j >= i+1; j--) grid[j][i] = start++;
            fillGrid(grid, n, i+1, start);
        }
    }
};