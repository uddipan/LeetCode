/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    double slope(Point a, Point b)
    {
        if(a.x == b.x)
        {
            return std::numeric_limits<double>::max();
        }
        return double(a.y - b.y)/(a.x - b.x);
    }
    static bool sortpts(Point a, Point b)
    {
        if(a.x <= b.x)return true;
        if(a.x == b.x  && a.y <= b.y) return true;
        return false;
    }
    
    int maxPoints(vector<Point>& points) {
        if(points.empty())return 0;
        map<double,vector<set<int>>> M;
        if(points.size() == 1)return 1;
        int maxcnt = INT_MIN;
        sort(points.begin(), points.end(),sortpts);
        for(int i=0; i<points.size()-1; i++)
        {
            for(int j=i+1; j<points.size(); j++)
            {
                double sl = slope(points[i], points[j]);
                auto it = M.find(sl);
                if(it == M.end())
                {
                    set<int>tmpset;
                    tmpset.insert(i);
                    tmpset.insert(j);
                    M[sl].push_back(tmpset);
                    maxcnt = max(maxcnt, 2);
                }
                else
                {
                    bool b = true;
                    for(unsigned u=0; u<M[sl].size(); u++)
                    {
                        int idx = *(M[sl][u].rbegin());
                        double sl2 = slope(points[i], points[idx]);
                        if(sl == sl2)
                        {
                            M[sl][u].insert(i);
                            M[sl][u].insert(j);
                            b = false;
                            int sx = int(M[sl][u].size());
                            maxcnt = max(maxcnt,sx);
                            break;
                        }
                    }
                    if(b)
                    {
                        set<int>tmpset;
                        tmpset.insert(i);
                        tmpset.insert(j);
                        M[sl].push_back(tmpset);
                        maxcnt = max(maxcnt, 2);
                    }
                }
            }
        }
        
        
        return maxcnt;
    }
};