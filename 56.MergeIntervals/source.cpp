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
    static bool myfn(Interval a, Interval b)
    {
        return (a.start < b.start);
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), myfn);
        auto i = 1;
        while( i<intervals.size())
        {
            if(intervals[i-1].end >= intervals[i].start)
            {
                intervals[i-1].end = max(intervals[i-1].end, intervals[i].end);
                intervals.erase(intervals.begin() + i);
            }
            else i++;
        }
        return intervals;
    }
};