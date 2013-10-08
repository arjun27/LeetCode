class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i = 0, maxArea = 0, n = height.size();
        stack<int> s;
        while (i < n) {
            if (s.empty() || height[s.top()] < height[i]) {
                s.push(i++);
            } else if (height[i] < height[s.top()]) {
                int now = s.top();
                s.pop();
                int right = i;
                int left = (!s.empty()) ? s.top() + 1: 0;
                maxArea = max(maxArea, height[now] * (right-left));
            } else {
                s.pop(); s.push(i++);
            }
        }
        while (!s.empty()) {
            int now = s.top();
            s.pop();
            int right = i;
            int left = (!s.empty()) ? s.top() + 1: 0;
            maxArea = max(maxArea, height[now] * (right-left));
        }
        return maxArea;
    }
};