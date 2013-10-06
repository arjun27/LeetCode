class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map<char, string> letters;
        letters['2'] = "abc";
        letters['3'] = "def";
        letters['4'] = "ghi";
        letters['5'] = "jkl";
        letters['6'] = "mno";
        letters['7'] = "pqrs";
        letters['8'] = "tuv";
        letters['9'] = "wxyz";
        vector<string> empty;
        return builder(digits, 0, letters, empty);
    }
    vector<string> builder(string digits, int now, map<char, string> &letters, vector<string> &old) {
        vector<string> res;
        if (now >= digits.length()) {
            if (old.size() == 0) {
                res.push_back("");
                return res;    
            }
            return old;
        }
        if (old.size() == 0) {
            for (int i = 0; i < letters[digits[now]].length(); i++) {
                stringstream ss;
                ss<<letters[digits[now]][i];
                res.push_back(ss.str());
            }
            return builder(digits, now+1, letters, res);
        }
        for (int i = 0; i < old.size(); i++) {
            for (int j = 0; j < letters[digits[now]].length(); j++) {
                stringstream ss;
                ss<<old[i];
                ss<<letters[digits[now]][j];
                res.push_back(ss.str());
            }
        }
        return builder(digits, now+1, letters, res);
    }
};