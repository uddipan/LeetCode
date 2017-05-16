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
    TreeNode* helper(TreeNode* n, TreeNode* p, TreeNode* q)
    {
        if(n == NULL || n == p || n == q)return n;
        if(n->val < p->val && n->val < q->val)return helper(n->right,p,q);
        if(n->val > p->val && n->val > q->val)return helper(n->left,p,q);
        if(n->val < p->val && n->val > q->val)return n;
        if(n->val > p->val && n->val < q->val)return n;
        return n;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }
};