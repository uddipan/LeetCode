class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)return false;
        int a = nums[0], b=nums[0];
        for(unsigned u=1; u<nums.size(); u++){
            if ((a < b) && (b < nums[u])) return true;
            if(a < nums[u]){
                b = nums[u];
            }
            else{
                if(a==b)b = nums[u];
                
                a = nums[u];
            }
        }
        return false;
    }
};