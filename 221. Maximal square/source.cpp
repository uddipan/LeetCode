class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())return 0;
        vector<int>tmp(matrix[0].size(),0);
        vector<vector<int>>cache(matrix.size(),tmp);
        
        int len = 0;
        for(int i=0; i<matrix[0].size(); i++)
        {
            cache[0][i] = int(matrix[0][i] - '0');
            len = max(len, cache[0][i]);
        }
        for(int j=0; j<matrix.size(); j++)
        {
            cache[j][0] = int(matrix[j][0] - '0');
            len = max(len, cache[j][0]);
        }
        
        
        for(int i=1; i<matrix.size(); i++)
        {
            for(int j=1; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == '1')
                {
                    cache[i][j] = 1 + min(min(cache[i][j-1], cache[i-1][j]), cache[i-1][j-1]);
                    len = max(len, cache[i][j]);
                }
            }
        }
        
        return len*len;
    }
};