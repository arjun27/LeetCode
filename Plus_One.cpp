class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return plusOne(digits, digits.size()-1);
    }
    vector<int> plusOne(vector<int> &digits, int i) {
        if (i < 0) {
            vector<int> res; res.push_back(1);
            for (int j = 0; j < digits.size(); j++) {
                res.push_back(digits[j]);
            }
            return res; 
        } else {
            if (digits[i] + 1 < 10) {
                digits[i] += 1;
                return digits;
            } else {
                digits[i] = 0;
                return plusOne(digits, i-1);
            }
        }
    }
};