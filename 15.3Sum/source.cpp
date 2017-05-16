class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>V;
        if(nums.empty())return V;
        sort(nums.begin(), nums.end());
        for(int i=0; i<int(nums.size())-2; i++)
        {
            if(i != 0 && nums[i] == nums[i-1])continue;
            int left = i+1, right = nums.size()-1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] == 0)
                {
                    vector<int>tmp(1,nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    V.push_back(tmp);
                    right--;
                }
                else if(nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        auto it = unique(V.begin(), V.end());
        V.resize( distance(V.begin(),it) );
        return V;
    }
};