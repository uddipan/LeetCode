class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())return 0;
        if(triangle.size() == 1)
        {
            if(triangle[0].empty())return 0;
            sort(triangle[0].begin(), triangle[0].end());
            return triangle[0][0];
        }
        else
        {
            for(int i = triangle.size()-2; i>=0; i--)
            {
                for(auto u=0; u<triangle[i].size(); u++)
                {
                    //if(u == 0)
                    {
                        triangle[i][u] += min(triangle[i+1][u],triangle[i+1][u+1]);
                    }
                    // else
                    // {
                    //     triangle[i][u] += min(min(triangle[i+1][u],triangle[i+1][u+1]),triangle[i+1][u-1]);
                    // }
                }
            }
            return triangle[0][0];
        }
    }
};