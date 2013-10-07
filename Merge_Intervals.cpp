/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool intervalComp (const Interval &i, const Interval &j) {
    return (i.start < j.start);
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<Interval> merged;
        int i = 0, n = intervals.size();
        if (n <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), intervalComp);
        while (i < n) {
            if (merged.empty()) merged.push_back(intervals[i++]);
            else {
                if (merged[merged.size() - 1].end >= intervals[i].start) {
                    Interval prev = merged[merged.size() - 1];
                    merged.resize(merged.size() - 1);
                    Interval *now = new Interval(prev.start, max(intervals[i].end, prev.end));
                    merged.push_back(*now);
                    i++;
                } else {
                    merged.push_back(intervals[i++]);
                }
            }
        }
        return merged;
    }
};