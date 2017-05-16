class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty())return 0;
        vector<vector<int>>cache(dungeon.size()+1,vector<int>(dungeon[0].size()+1,INT_MAX));
        cache[dungeon.size()][dungeon[0].size()-1] = 1;
        cache[dungeon.size()-1][dungeon[0].size()] = 1;
        for(int i=dungeon.size()-1; i>=0; i--)
        {
            for(int j=dungeon[0].size()-1; j>=0; j--)
            {
                cache[i][j] = min(cache[i+1][j], cache[i][j+1]) - dungeon[i][j];
                if(cache[i][j] <= 0)cache[i][j] = 1;
            }
        }
        return cache[0][0];
    }
};