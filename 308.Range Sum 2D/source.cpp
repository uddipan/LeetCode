class NumMatrix {
public:
    // store the sum of each row
    vector<vector<int>>sum_row;
    NumMatrix(vector<vector<int>> &matrix) {
        for(int i=0; i<matrix.size(); i++)
        {
            int sum = 0;
            vector<int>tmp;
            for(int j=0; j<matrix[0].size(); j++)
            {
                sum += matrix[i][j];
                tmp.push_back(sum);
            }
            sum_row.push_back(tmp);
        }
    }
    
    void update(int row, int col, int val) {
        int delta = val - sum_row[row][col] + sum_row[row][col-1];
        for(int i=col; i<sum_row[0].size(); i++)
        {
            sum_row[row][i] += delta;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        for(int i=row1; i<=row2; i++)
        {
            ret += sum_row[i][col2];
            if(col1)ret -=sum_row[i][col1-1];
        }
        return ret;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);