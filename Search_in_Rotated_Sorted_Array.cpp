class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pivot = findPivot(A, 0, n-1);
        if (pivot == -1) return binSearch(A, 0, n-1, target);
        if (target < A[0]) {
            return binSearch(A, pivot+1, n-1, target);
        } else {
            return binSearch(A, 0, pivot, target);
        }
    }
    int findPivot(int A[], int start, int end) {
        // return index of pivot
        if (end <= start) return -1;
        int mid = (start + end) / 2;
        if (A[mid] > A[mid+1]) return mid;
        if (A[start] > A[mid]) return findPivot(A, start, mid);
        else return findPivot(A, mid+1, end);
    }
    int binSearch(int A[], int start, int end, int target) {
        if (end < start) return -1;
        if (end == start) {
            if (A[end] == target) return end;
            else return -1;
        }
        int mid = (start + end) / 2;
        if (A[mid] == target) return mid;
        if (A[mid] < target) return binSearch(A, mid+1, end, target);
        else return binSearch(A, start, mid, target);
    }
};