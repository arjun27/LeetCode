class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int l = lsearch(A, 0, n, target);
        int r = rsearch(A, n, 0, n, target);
        vector<int> res;
        res.push_back(l); res.push_back(r);
        return res;
    }
    int lsearch(int A[], int start, int end, int t) {
        if (start >= end) return -1;
        if (start+1 == end) return (A[start] == t) ? start : -1;  
        
        int mid = (start + end) / 2;
        
        if (A[mid] < t) return lsearch(A, mid+1, end, t);
        else if (A[mid] > t) return lsearch(A, start, mid, t);
        
        // A[mid] == t
        if (mid == 0) return mid;
        int l = lsearch(A, start, mid, t);
        return (l == -1) ? mid : l;
    }
    int rsearch(int A[], int n, int start, int end, int t) {
        if (start >= end) return -1;
        if (start+1 == end) return (A[start] == t) ? start : -1;  
        
        int mid = (start + end) / 2;
        
        if (A[mid] < t) return rsearch(A, n, mid+1, end, t);
        else if (A[mid] > t) return rsearch(A, n, start, mid, t);
        
        // A[mid] == t
        if (mid == n-1) return mid;
        int r = rsearch(A, n, mid+1, end, t);
        return (r == -1) ? mid : r;
    }
};