#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = triangle.size();
        vector <int> scores ((n*(n+1))/2);
        scores[0] = triangle[0][0];
        // number of rows is n
        for (int i = 1; i < n; i++) {
        	// ith row computation
        	// elements [0..i]
        	for (int j = 0; j <= i; j++) {
        		scores[j] = 
        	}
        }
    }
};

int main() {
	Solution sol;
	vector<vector<int> > t (4);
	int vv[2] = { 12,43 };
	vector<int> r1(&vv[0], &vv[0]+2);	
	t.push_back(r1);
	cout<<sol.minimumTotal(t);
	return 0;
}