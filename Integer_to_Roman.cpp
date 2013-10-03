class Solution {
public:
    string intToRoman(int num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        string res = "";
        if (num == 0) return res;
        char r[] = { 'I','V','X','L','C','D','M' };
        vector<char> romans(r, r+7);
        map<char,int> val;
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
        for (int i = 6; i >= 1; i--) {
            for (int j = 0; j < 4; j++) {
                res += handle(romans, val, &num, i);
            }
        }
        if (num >= 1) res += "I";
        if (num >= 2) res += "I";
        if (num == 3) res += "I";
        return res;
    }
    string handle(vector<char> &romans, map<char,int> &val, int* num, int i) {
        char now = romans[i];
        char prev;
        if (i % 2 == 0) prev = romans[i-2];
        else prev = romans[i-1];
        
        int thresh = val[now] - val[prev];
        
        if (*num >= thresh) {
            if (*num >= val[now]) {
                *num = *num - val[now];
                string res(1, now);
                return res; 
            } else {
                *num = *num - thresh;
                string res1(1, now);
                string res2(1, prev);
                return res2 + res1;
            }
        }
        return "";
    }
};