class Solution {
public:
    string addBinary(string a, string b) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string added = addBinary(a, b, 0, 0);
        reverse(added.begin(), added.end());
        return added;
    }
    string addBinary(string a, string b, int i, int carry) {
        if (i >= a.length() && i >= b.length()) {
            return (carry == 1) ? "1" : "";
        }
        int ai, bi;
        if (i >= a.length()) ai = 0;
        else ai = a[i] - '0';
        if (i >= b.length()) bi = 0;
        else bi = b[i] - '0';
        int added = ai + bi + carry;
        if (added == 0) return "0" + addBinary(a, b, i+1, 0);
        if (added == 1) return "1" + addBinary(a, b, i+1, 0);
        if (added == 2) return "0" + addBinary(a, b, i+1, 1);
        if (added == 3) return "1" + addBinary(a, b, i+1, 1);
        return "";
    }
};