class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        for (int i = num.size() - 1; i >= 0; i--) {
            if (i-1 >= 0) {
                if (num[i-1] < num[i]) {
                    // can swap
                    int first = i;
                    for (int j = i; j < num.size(); j++) {
                        if (num[j] > num[i-1]) first = j;
                        else break;
                    }
                    swap(num[first], num[i-1]);
                    sort(num.begin()+i, num.end());
                    return;
                }
            } else {
                reverse(num.begin(), num.end());
                return;
            }
        }
    }
};