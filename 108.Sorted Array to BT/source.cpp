/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int> &nums, int start, int end)
    {
        if(start > end)return NULL;
        int mid = start + (end - start)/2;
        TreeNode *left = helper(nums, start, mid - 1);
        TreeNode * right = helper(nums, mid+1, end);
        TreeNode *head = new TreeNode(nums[mid]);
        head->left = left;
        head->right=right;
        return head;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};