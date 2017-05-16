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
    map<TreeNode*, int>M;
    int DP(TreeNode* n)
    {
        if(n == NULL)return 0;
        auto it = M.find(n);
        if(it != M.end())
        {
            return it->second;
        }
        int a = 0, b = 0;
        if(n->left)
        {
            a = DP(n->left->left) + DP(n->left->right);
        }
        if(n->right)
        {
            b = DP(n->right->left) + DP(n->right->right);
        }
        M[n] = max(n->val + a + b, DP(n->left) + DP(n->right));
        return M[n];
    }
    int rob(TreeNode* root) {
        if(root == NULL)return 0;
        return DP(root);
    }
};