class Solution {
public:
    void sortColors(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i = 0;
        int a = -1, b = -1;
        while (i < n) {
            switch(A[i]) {
                case 0:
                    if (a != -1) swap(A[a++], A[i--]);
                    else if (b != -1) swap(A[b++], A[i]);
                    break;
                case 1:
                    if (b != -1) swap(A[b++], A[i]);
                    if (a == -1) a = (b != -1) ? b-1 : i;
                    break;
                case 2:
                    if (b == -1) b = i;
                    break;
            }
            i++;
        }
    }
};