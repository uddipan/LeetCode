class Solution {
public:
    static bool spl(int a, int b)
    {
        string A = to_string(a), B = to_string(b);
        return (A+B > B+A);
    }
    string largestNumber(vector<int>& nums) {
        if(nums.empty())return "";
        sort(nums.begin(), nums.end(),spl);
        while(nums.size()>1 && nums[nums.size()-1] == 0 && nums[0] == 0)
        {
            nums.pop_back();
        }
        string res;
        for(int i=0; i<nums.size(); i++)
        {
            res += to_string(nums[i]);
        }
        return res;
    }
};