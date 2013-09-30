class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // if (n < 0) return pow(1.0/x, -1*n);
        if (n == 0) return 1;
        if (n == 1) return x;
        double res = pow(x, abs(n)/2);
        res *= res;
        if (abs(n) % 2 != 0) {
            res *= x;
        }
        if (n < 0) return 1.0/res;
        return res;
    }
};