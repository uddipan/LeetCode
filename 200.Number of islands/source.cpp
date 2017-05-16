class Solution {
public:
    
    vector<vector<bool>>visited;
    
    void spill(int x, int y, vector<vector<char>>& grid)
    {
        if(visited[x][y])return;
        if(grid[x][y] == '0')return;
        
        visited[x][y] = true;
        if(x > 0)spill(x-1,y,grid);
        if(y > 0)spill(x,y-1,grid);
        if(x < grid.size() -1)spill(x+1,y,grid);
        if(y < grid[0].size() - 1)spill(x,y+1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        if(grid.empty())return cnt;
        vector<bool>tmpb(grid[0].size(), false);
        visited = vector<vector<bool>>(grid.size(),tmpb);
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == '0' || visited[i][j])continue;
                spill(i,j,grid);
                cnt++;
            }
        }
        return cnt;
    }
    
};