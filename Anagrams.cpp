class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map<string, vector<string> > classes;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (classes.find(s) == classes.end()) {
                vector<string> row(1, strs[i]);
                classes[s] = row;
            } else {
                classes[s].push_back(strs[i]);
            }
        }
        vector<string> res;
        map<string, vector<string> >::iterator it = classes.begin();
        while (it != classes.end()) {
            if (it->second.size() > 1) {
                res.insert(res.end(), it->second.begin(), it->second.end());
            }
            it++;
        }
        return res;
    }
};