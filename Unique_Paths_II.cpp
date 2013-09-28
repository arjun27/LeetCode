class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &og) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int paths[101][101] = { 0 };
        int m = og.size();
        int n = og[0].size();

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (og[i][j] == 1) paths[i][j] = 0;
                else {
                    if (i == m-1 && j == n-1) paths[i][j] = 1;
                    else if (i == m-1) {
                        paths[i][j] = paths[i][j+1];
                    } else if (j == n-1) {
                        paths[i][j] = paths[i+1][j];
                    } else {
                        paths[i][j] = paths[i+1][j] + paths[i][j+1];
                    }
                }
            }
        }
        
        return paths[0][0];
    }
};