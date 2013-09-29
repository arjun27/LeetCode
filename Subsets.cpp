// interesting solution

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        vector<vector<int> > v(1);
        for (int i = 0; i < S.size(); i++) {
            int j = v.size() - 1;
            while (j >= 0) {
                v.push_back(v[j]);
                v.back().push_back(S[i]);
                j--;
            }
        }
        return v;
    }
};