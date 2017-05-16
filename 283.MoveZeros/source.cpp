class Solution {
public:
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void moveZeroes(vector<int>& nums) {
        //find first 0;
        int idx0 = 0;
        while(idx0 < nums.size() && nums[idx0] != 0)idx0++;
        if(idx0 == nums.size())return;
        
        int idxN = idx0+1;
        while(idxN < nums.size() && nums[idxN] == 0)idxN++;
        if(idxN == nums.size())return;
        
        while(idxN < nums.size())
        {
            swap(nums[idx0], nums[idxN]);
            idx0++;
            while(idxN < nums.size() && nums[idxN] == 0)idxN++;
        }
    }
};