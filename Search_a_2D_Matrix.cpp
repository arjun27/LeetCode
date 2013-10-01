class Solution {
public:
    int m, n, t;
    vector<vector<int> > grid;
    vector<int> iRow;
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        m = matrix.size();
        if (m == 0) return false;
        n = matrix[0].size();
        if (n == 0) return false;
        grid = matrix;
        t = target;
        int row = vertical(0, m);
        if (row == -1) return false;
        else {
            iRow = grid[row];
            return horizontal(0, n);
        }
    }
    bool horizontal(int start, int end) {
        if (end <= start) return false;
        int mid = (start+end) / 2;
        if (iRow[mid] == t) return true;
        if (iRow[mid] > t) return horizontal(start, mid);
        else return horizontal(mid+1, end);
    }
    int vertical(int start, int end) {
        if (end <= start) return -1;
        int mid = (start+end) / 2;
        int in = inRow(grid[mid]);
        if (in == 0) return mid;
        if (in == 1) return vertical(mid+1, end);
        else return vertical(start,mid);
    }
    int inRow(vector<int> &row) {
        if (row[0] <= t && row[n-1] >= t) return 0;
        if (row[0] >= t) return -1;
        if (row[n-1] <= t) return 1;
    }
};