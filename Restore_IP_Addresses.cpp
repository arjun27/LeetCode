class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> vec = restoreIp(s, 0, 4);
        set<string> const uniques(vec.begin(), vec.end());
        vec.assign(uniques.begin(), uniques.end());
        return vec;
    }
    vector<string> restoreIp(string s, int i, int n) {
        vector<string> res; res.resize(0);
        if (i < s.length()) {
            if (n == 0) return res;
            if (n == 1) {
                if (s[i] == '0') {
                    if (i+1 != s.length()) return res;
                    stringstream ss;
                    ss<<s[i];
                    string n = ss.str();
                    res.push_back(n);
                    return res;
                }
                int now = 0;
                int j = i;
                while (i < s.length()) {
                    now = 10*now + (s[i++] - '0');
                }
                if (0 <= now && now <= 255) {
                    stringstream ss;
                    ss<<s.substr(j);
                    string n = ss.str();
                    res.push_back(n);
                }
                return res;
            }
            int now = 0, j = 1, p = i;
            if (s[i] == '0') {
                vector<string> later = restoreIp(s, i+1, n-1);
                if (later.size() > 0) {
                    for (int k = 0; k < later.size(); k++) {
                        string l = later[k];
                        stringstream ss;
                        ss << s[i] << "." << l;
                        res.push_back(ss.str());
                    }
                }
                return res;
            }
            while (j <= 3) {
                now = 10*now + (s[i++] - '0');
                if (0 <= now && now <= 255) {
                    vector<string> later = restoreIp(s, i, n-1);
                    if (later.size() > 0) {
                        for (int k = 0; k < later.size(); k++) {
                            string l = later[k];
                            stringstream ss;
                            ss << s.substr(p,j) << "." << l;
                            res.push_back(ss.str());
                        }
                    }
                }
                j++;
            }
            return res;
        } else return res;
    }
};
