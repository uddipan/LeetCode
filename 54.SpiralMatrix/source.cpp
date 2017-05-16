class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>spiral;
        if(matrix.empty())return spiral;
        vector<pair<int,int>> step  = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int dir = 0;
        int x = 0, y = 0, next_x = 0, next_y = 0;
        
        for(int i = 0; i<matrix.size()*matrix[0].size(); i++)
        {
            spiral.push_back(matrix[x][y]);
            matrix[x][y] = 0;
            next_x = x + step[dir].first;
            next_y = y + step[dir].second;
            if((next_x < 0) || (next_x >= matrix.size()) ||
               (next_y < 0) || (next_y >= matrix[0].size()) || (matrix[next_x][next_y] == 0))
            {
                dir = (dir + 1)%4;
                next_x = x + step[dir].first;
                next_y = y + step[dir].second;
            }
            x = next_x;
            y = next_y;
        }
        return spiral;
    }
};