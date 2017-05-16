class Solution {
public:
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n,vector<int>(n,0));
        pair<int,int>dir[] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        pair<int,int>start = {0,0},tmp;
        int status = 0;
        for(int i=0; i<n*n; i++)
        {
            res[start.first][start.second] = i+1;
            tmp = start;
            start = {start.first + dir[status].first, start.second + dir[status].second};
            if(start.first < 0 || start.first >= n
               || start.second < 0 || start.second >=n
               || res[start.first][start.second] != 0)
            {
                status = (status + 1)%4;
                start = {tmp.first + dir[status].first, tmp.second + dir[status].second};
            }
        }
        
        return res;
    }
};