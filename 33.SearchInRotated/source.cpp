class Solution {
public:
    int binSearch(vector<int>& nums, int target, int L, int R)
    {
        if( L > R)return -1;
        int mid = (L + R)/2;
        if(nums[mid] == target)return mid;
        else if (nums[mid] > target)
        {
            return binSearch(nums, target, L, mid-1);
        }
        else
        {
            return binSearch(nums, target, mid+1, R);
        }
    }
    
    int modBinSearch(vector<int>& nums, int target, int L, int R)
    {
        if( L > R)return -1;
        int mid = (L + R)/2;
        if(nums[mid] == target)return mid;
        if(nums[mid] >= nums[L])
        {
            // pivot on the right
            if(target > nums[mid])
            {
                return modBinSearch(nums, target, mid+1, R);
            }
            else
            {
                return max(binSearch(nums, target, L, mid-1), modBinSearch(nums, target, mid+1,R));
            }
        }
        else
        {
            // pivot on left
            if(target > nums[mid])
            {
                return max(binSearch(nums, target, mid+1, R), modBinSearch(nums, target, L,mid-1));
            }
            else
            {
                return modBinSearch(nums, target, L, mid-1);
            }
        }
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.empty())return -1;
        return modBinSearch(nums, target, 0, nums.size()-1);
    }
};



////////////////////////////////////////
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        
        while(L <= R)
        {
            int mid = L + (R - L)/2;
            if(nums[mid] == target)return mid;
            if(nums[mid] < nums[L])
            {
                //pivot on left
                if(target > nums[R] || target < nums[mid])
                {
                    R = mid;
                }
                else
                {
                    L = mid + 1;
                }
            }
            else
            {
                //pivot on right
                if(target < nums[L] || target > nums[mid])
                {
                    L = mid + 1;
                }
                else
                {
                    R = mid;
                }
            }
        }
        return -1;
    }
};