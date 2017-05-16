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
    
    int uniquePaths(int m, int n) {
        M[0][0] = 1;
        return FindPath(m-1,n-1);
    }
};