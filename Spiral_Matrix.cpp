class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        vector<int> res;
        if (m == 0) return res;
        int n = matrix[0].size();
        if (n == 0) return res;
        if (m == 1) return matrix[0];
        return ring(matrix, m, n, 0);
    }
    vector<int> ring(vector<vector<int> > &matrix, int m, int n, int i) {
        /*
        (i,i) ------------------ (i,n-1-i)
          |                          |
          |                          |
          |                          |
        (m-1-i,i) ---------- (m-1-i,n-1-i)  
        */
        vector<int> res; res.resize(0);
        if (n-1-i < i || m-1-i < i) return res;
        if (m-1-i == i) {
            for (int j = i; j <= n-1-i; j++) res.push_back(matrix[i][j]);
            return res;
        } else if (n-1-i == i) {
            for (int j = i; j <= m-1-i; j++) res.push_back(matrix[j][i]);
            return res;
        } else {
            for (int j = i; j <= n-1-i; j++) res.push_back(matrix[i][j]);
            for (int j = i+1; j <= m-1-i; j++) res.push_back(matrix[j][n-1-i]);
            for (int j = n-2-i; j >= i; j--) res.push_back(matrix[m-1-i][j]);
            for (int j = m-2-i; j >= i+1; j--) res.push_back(matrix[j][i]);
            vector<int> next = ring(matrix, m, n, i+1);
            res.insert(res.end(), next.begin(), next.end());
            return res;
        }
        return res;
    }
};