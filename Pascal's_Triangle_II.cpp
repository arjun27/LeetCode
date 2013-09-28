class Solution {
public:
    vector<int> getRow(int r) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> row;
        if (r == 0 || r == 1) row.push_back(1);
        if (r == 1) row.push_back(1);
        if (r > 1) {
            vector<int> prev = getRow(r-1);
            row.push_back(1);
            for (int j = 1; j <= r-1; j++) {
                row.push_back(prev[j-1] + prev[j]);
            }
            row.push_back(1);
        }
        return row;
    }
};