class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        set<vector<int>>tmpres;
        if(nums.size() < 4)return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-3; i++)
        {
            for(int j=i+3; j<nums.size(); j++)
            {
                int l = i+1, r = j-1;
                while(l < r)
                {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum == target)
                    {
                        vector<int>tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[l]);
                        tmp.push_back(nums[r]);
                        tmp.push_back(nums[j]);
                        tmpres.insert(tmp);
                        l++;r--;
                    }
                    else if(sum < target)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
        }
        for(auto it=tmpres.begin(); it!= tmpres.end(); ++it)
        {
            res.push_back(*it);
        }
        return res;
    }
};