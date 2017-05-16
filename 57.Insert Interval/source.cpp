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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int L=0, R = int(intervals.size()) -1;
        int mid;
        int starting = 0;
        while(L <= R)
        {
            mid = (L + R)/2;
            if(intervals[mid].start < newInterval.start)
            {
                L = mid + 1;
            }
            else
            {
                R = mid - 1;
            }
        }
        
        if(L == intervals.size())
        {
            intervals.push_back(newInterval);
        }
        else
        {
            intervals.insert(intervals.begin()+L,newInterval);
        }
        
        auto i = 0;
        while( i<intervals.size()-1)
        {
            if(intervals[i].end >= intervals[i+1].start)
            {
                intervals[i].end = max(intervals[i].end, intervals[i+1].end);
                intervals.erase(intervals.begin() + i + 1);
            }
            else i++;
        }
        return intervals;
        
    }
};