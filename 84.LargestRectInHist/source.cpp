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
};