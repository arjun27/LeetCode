class Solution {
public:
    string s1, s2, s3;
    vector<vector<int> > matrix;
    bool isInterleave(string str1, string str2, string str3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        s1 = str1;
        s2 = str2;
        s3 = str3;
        if (s1.length() == 0) return s2 == s3;
        if (s2.length() == 0) return s1 == s3;
        matrix.resize(s1.length());
        vector<int> row(s2.length(), -1);
        for (int i = 0; i < s1.length(); i++) 
            matrix[i] = row;
        return isInterleave(0, 0);
    }
    bool isInterleave(int i, int j) {
        if (i >= s1.length()) return (s2.substr(j) == s3.substr(i+j)) ? true : false;
        if (j >= s2.length()) return (s1.substr(i) == s3.substr(i+j)) ? true : false;
        
        if (matrix[i][j] != -1) {
            return (matrix[i][j] == 0) ? false : true;
        } else {
            bool res = false;
            if (s3[i+j] == s1[i]) res = res || isInterleave(i+1, j);
            if (s3[i+j] == s2[j]) res = res || isInterleave(i, j+1);
            matrix[i][j] = (res) ? 1 : 0;
            return res;
        }
        return false;
    }
};
