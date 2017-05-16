class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty())return;
        
        int sz = matrix.size() - 1;
        for(int i=0; i<matrix.size()/2; i++)
        {
            for(int j=i; j<sz - i; j++)
            {
                int a = matrix[i][j];
                int b = matrix[sz - j][i];
                int c = matrix[sz - i][sz - j];
                int d = matrix[j][sz - i];
                matrix[i][j] = b;
                matrix[sz - j][i] = c;
                matrix[sz - i][sz - j] = d;
                matrix[j][sz - i] = a;
            }
        }
    }
};