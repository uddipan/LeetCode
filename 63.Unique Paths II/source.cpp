class Solution {
public:
    vector<int> m = vector<int>(100,-1);
    vector<vector<int>> M = vector<vector<int>>(100,m);
    
    int FindPath(int m, int n)
    {
        if((m<0) || (n<0))return 0;
        if(M[m][n] != -1) return M[m][n];
        M[m][n] = FindPath(m-1,n) + FindPath(m,n-1);
        return M[m][n];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // M[0][0] = 1;
        for(auto i=0; i<obstacleGrid.size(); i++)
        {
            for(auto j=0; j<obstacleGrid[0].size(); j++)
            {
                M[i][j] += obstacleGrid[i][j];
            }
        }
        if(M[0][0] == -1)M[0][0]=1;
        FindPath(obstacleGrid.size()-1, obstacleGrid[0].size()-1);
    }
};