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
    static bool myfn(pair<int,bool> a, pair<int, bool> b)
    {
        if (a.first < b.first)return true;
        else if (a.first == b.first)
        {
            return (a.second == false && b.second == true);
        }
        return false;
    }
    
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty())return 0;
        vector<pair<int,bool>>V;
        for(auto i=0; i<intervals.size(); i++)
        {
            V.push_back({intervals[i].start,true});
            V.push_back({intervals[i].end,false});
        }
        sort(V.begin(), V.end(), myfn);
        int cnt = 0;
        int maxcnt = INT_MIN;
        for(auto i=0; i<V.size(); i++)
        {
            if(V[i].second)
            {
                cnt++;
                maxcnt = max(maxcnt, cnt);
            }
            else
            {
                cnt --;
            }
        }
        return maxcnt;
    }
};