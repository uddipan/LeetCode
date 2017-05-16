class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty())return 0;
        priority_queue<int, std::vector<int>, std::greater<int> > my_min_heap;
        for(int i=0; i<k; i++)
        {
            my_min_heap.push(nums[i]);
        }
        for(int i=k; i<nums.size(); i++)
        {
            if(my_min_heap.top() < nums[i])
            {
                my_min_heap.pop();
                my_min_heap.push(nums[i]);
            }
        }
        return my_min_heap.top();
    }
};