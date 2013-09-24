// O(n^2) solution -> TLE for large inputs

class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector <int> minJumps; minJumps.resize(n, -1);
        minJumps[n-1] = 0;
        int i = n-2;
        int last = n-1;
        while(i >= 0) {
            int least = n+1;
            for (int j = i+1; j <= i+A[i]; j++) {
                if (minJumps[j] >= 0 && minJumps[j] < least) {
                    least = minJumps[j];
                }
            }
            if (least < n+1) minJumps[i] = least+1;
            else minJumps[i] = -1;
            i--;
        }
        return minJumps[0];
    }
};
