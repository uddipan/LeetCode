class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.empty())return 0;
        int i=0, j=height.size()-1;
        int maxWater = 0;
        
        while(i < j)
        {
            int Mi = height[i], Mj = height[j];
            maxWater = max(maxWater, (j-i)*min(Mi, Mj));
            if(Mi < Mj)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxWater;
    }
};