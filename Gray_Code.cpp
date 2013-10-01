class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        if (n == 0) {
            res.push_back(0);
            return res;
        }
        if (n == 1) {
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        vector<int> prev = grayCode(n-1);
        for (int i = 0; i < prev.size(); i++) {
            res.push_back(prev[i]);
        }
        reverse(prev.begin(), prev.end());
        for (int i = 0; i < prev.size(); i++) {
            res.push_back(pow(2,n-1) + prev[i]);
        }
        return res;
    }
};