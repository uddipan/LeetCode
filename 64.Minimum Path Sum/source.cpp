class Solution {
public:
    vector<vector<int>>M;
    int path(vector<vector<int>>& grid, int m, int n)
    {
        /**
         * dp[i][j] denoting the minimum sum from (0,0) to (i,j)
         * dp[0][j] = dp[0][j-1]+grid[0][j]
         * dp[i][0] = dp[i-1][0]+grid[i][0]
         * otherwise dp[i][j]= min(dp[i][j-1],dp[i-1][j])+dp[i][j]
         * */
        if(M[m][n] != -1)return M[m][n];
        if(m == 0)
        {
            M[m][n] = path(grid,m,n-1) + grid[m][n];
        }
        else if(n == 0)
        {
            M[m][n] = path(grid,m-1,n) + grid[m][n];
        }
        else
        {
            M[m][n] = min(path(grid, m-1,n), path(grid,m,n-1)) + grid[m][n];
        }
        return M[m][n];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())return 0;
        vector<int>tmp(grid.size(),-1);
        M = vector<vector<int>>(grid[0].size(),tmp);
        M[0][0]= grid[0][0];
        return path(grid, grid.size()-1, grid[0].size()-1);
    }
};