class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> braces;
        for (int i = 0; i < s.length(); i++) {
            if (isOpening(s[i])) braces.push(s[i]);
            else {
                if (braces.empty()) return false;
                if (braces.top() != complement(s[i])) return false;
                braces.pop();
            }
        }
        if (braces.empty()) return true;
        return false;
    }
    bool isOpening(char s) {
        return (s == '(' || s == '[' || s == '{') ? true : false;
    }
    char complement(char s) {
        if (s == ')') return '(';
        if (s == '}') return '{';
        if (s == ']') return '[';
        return ' ';
    }
};