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
    int maxdepth(TreeNode *N)
    {
        if(N == NULL)return 0;
        int L = maxdepth(N->left);
        if( L == -1) return -1;
        int R = maxdepth(N->right);
        if( R == -1) return -1;
        if (abs(L - R) > 1)return -1;
        return max(L,R) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return (maxdepth(root) != -1);
    }
};