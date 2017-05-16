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
    bool mirror(TreeNode*p, TreeNode*q)
    {
        if((p == NULL) && (q == NULL))return true;
        if((p == NULL) || (q == NULL))return false;
        return ((p->val == q->val)
                &&(mirror(p->left,q->right))
                &&(mirror(q->left,p->right)));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)return true;
        return mirror(root->left, root->right);
    }
};