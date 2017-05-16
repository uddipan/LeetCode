class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>row,col;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for(auto it = row.begin(); it != row.end(); ++it)
        {
            int r = *it;
            for(int i=0; i<matrix[0].size(); i++)
            {
                matrix[r][i] = 0;
            }
        }
        
        for(auto it = col.begin(); it != col.end(); ++it)
        {
            int c = *it;
            for(int i=0; i<matrix.size(); i++)
            {
                matrix[i][c] = 0;
            }
        }
    }
};