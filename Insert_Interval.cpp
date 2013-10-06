/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<Interval> afterInsert;
        int start = -1, possibleEnd = -1;
        bool inside = false, inserted = false;
        if (intervals.size() == 0) {
            afterInsert.push_back(newInterval);
            return afterInsert;
        }
        for (int i = 0; i < intervals.size(); i++) {
            if (!inside) {
                if (intervals[i].end < newInterval.start || inserted) {
                    afterInsert.push_back(intervals[i]);
                } else if (intervals[i].start > newInterval.end && !inserted) {
                    Interval *latest = new Interval(newInterval.start, newInterval.end);
                    afterInsert.push_back(*latest);
                    afterInsert.push_back(intervals[i]);
                    inserted = true;
                } else {
                    // what is the end point?
                    start = min(newInterval.start, intervals[i].start);
                    possibleEnd = max(newInterval.end, intervals[i].end);
                    inside = true;
                }
            } else {
                if (possibleEnd >= intervals[i].start) {
                    possibleEnd = max(possibleEnd, intervals[i].end);
                } else {
                    Interval *latest = new Interval(start, possibleEnd);
                    afterInsert.push_back(*latest);
                    inside = false;
                    inserted = true;
                    afterInsert.push_back(intervals[i]);
                }
            }
        }
        if (inside) {
            Interval *latest = new Interval(start, possibleEnd);
            afterInsert.push_back(*latest);
            inside = false;
            inserted = true;
        }
        if (!inserted) {
            Interval *latest = new Interval(newInterval.start, newInterval.end);
            afterInsert.push_back(*latest);
        }
        return afterInsert;
    }
};