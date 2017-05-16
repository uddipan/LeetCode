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
    int SUM = INT_MIN;
    int PathSum(TreeNode* N)
    {
        if(N == NULL)return 0;
        int l = PathSum(N->left);
        int r = PathSum(N->right);
        SUM = max(SUM, l+r+N->val);
        return max(0,max(l,r) + N->val);
    }
    int maxPathSum(TreeNode* root) {
        int i =  PathSum(root);
        return SUM;
    }
};