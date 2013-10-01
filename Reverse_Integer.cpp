class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = -1*x;
        }
        int y = 0;
        while (x > 0) {
            int unit = x % 10;
            y = (10*y) + unit;
            x = x / 10;
        }
        return sign*y;
    }
};