class Solution {
public:
    void DP(int x, int y, vector<vector<int>>& rooms, int depth)
    {
        if(x < 0 || x >= rooms.size() || y < 0 || y >= rooms[0].size())return;
        if(rooms[x][y] == -1)return;
        if(rooms[x][y] == 0)return;
        if(rooms[x][y] < depth)return;
        if(rooms[x][y] > depth || rooms[x][y] < INT_MAX) rooms[x][y] = depth;
        DP(x-1,y,rooms,depth+1);
        DP(x+1,y,rooms,depth+1);
        DP(x,y-1,rooms,depth+1);
        DP(x,y+1,rooms,depth+1);
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        for(auto i=0; i<rooms.size(); i++)
        {
            for(auto j=0; j<rooms[0].size(); j++)
            {
                if(rooms[i][j] == 0)
                {
                    DP(i-1,j,rooms,1);
                    DP(i+1,j,rooms,1);
                    DP(i,j-1,rooms,1);
                    DP(i,j+1,rooms,1);
                }
            }
        }
    }
};