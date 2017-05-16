class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())return false;
        int x = 0, y = matrix[0].size() -1;
        while(x < matrix.size() && y >= 0)
        {
            if(matrix[x][y] == target)return true;
            if(matrix[x][y] > target) y--;
            else x ++;
        }
        return false;
    }
};