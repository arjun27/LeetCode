class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int,int> hash;
        vector<int> res;
        for (int i = 0; i < numbers.size(); i++) {
            hash[numbers[i]] = i+1;
        }
        for (int i = 0; i < numbers.size(); i++) {
            if (hash.find(target-numbers[i]) != hash.end()) {
                if (i+1 < hash[target-numbers[i]]) {
                    res.push_back(i+1); res.push_back(hash[target-numbers[i]]);
                } else {
                    res.push_back(hash[target-numbers[i]]); res.push_back(i+1);
                }
            }
        }
        return res;
    }
};