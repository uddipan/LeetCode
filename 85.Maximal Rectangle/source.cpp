class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())return 0;
        stack<int> S;
        int maxArea = 0;
        for(int i=0; i<=heights.size(); i++)
        {
            while(!S.empty() && (i == heights.size() || heights[i] < heights[S.top()]))
            {
                int ht = heights[S.top()];
                S.pop();
                maxArea = max(maxArea, ht*(S.empty()?i:i-S.top()-1));
            }
            S.push(i);
        }
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())return 0;
        int maxArea = 0;
        vector<int>tmp(matrix[0].size(),0);
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == '1')
                {
                    tmp[j] ++;
                }
                else tmp[j] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(tmp));
        }
        return maxArea;
    }
};