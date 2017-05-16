class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        // best meeting point is at median
        if(grid.empty())return 0;
        vector<int>hor,ver;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j])
                {
                    hor.push_back(j);
                    ver.push_back(i);
                }
            }
        }
        sort(hor.begin(), hor.end());
        sort(ver.begin(), ver.end());
        int hi = hor[hor.size()/2];
        int vi = ver[ver.size()/2];
        
        int res = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size();j++)
            {
                if(grid[i][j])
                {
                    res += abs(i-vi) + abs(j-hi);
                }
            }
        }
        return res;
    }
};