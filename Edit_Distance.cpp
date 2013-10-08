class Solution {
public:
    string s1, s2;
    int n1, n2;
    int minDistance(string word1, string word2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        s1 = word1; s2 = word2;
        n1 = s1.length(); n2 = s2.length();
        vector<vector<int> > matrix;
        matrix.resize(n1);
        vector<int> empty(n2, -1);
        for (int i = 0; i < n1; i++) matrix[i] = empty;
        return minDist(0, 0, matrix);
    }
    int minDist(int i, int j, vector<vector<int> > &matrix) {
        if (i == n1 && j == n2) return 0;
        if (i == n1) return n2 - j;
        if (j == n2) return n1 - i;
        
        if (matrix[i][j] != -1) return matrix[i][j];
        if (s1[i] == s2[j]) {
            matrix[i][j] = minDist(i+1, j+1, matrix);
        }
        else {
            int a = minDist(i, j+1, matrix);
            int b = minDist(i+1, j, matrix);
            int c = minDist(i+1, j+1, matrix);
            matrix[i][j] = min(a, min(b,c)) + 1;
        }
        return matrix[i][j];
    }
};