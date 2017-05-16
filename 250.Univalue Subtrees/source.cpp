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
    pair<int,bool> ust(TreeNode* n)
    {
        if(n == NULL)return {0,true};
        if(n->left == NULL && n->right == NULL)
        {
            return {1,true};
        }
        else if(n->left == NULL)
        {
            int ret = 0;
            auto r = ust(n->right);
            ret = r.first;
            if(r.second && n->val == n->right->val)
            {
                ret++;
                return {ret,true};
            }
            else
            {
                return {ret,false};
            }
            
        }
        else if(n->right == NULL)
        {
            int ret = 0;
            auto r = ust(n->left);
            ret = r.first;
            if(r.second && n->val == n->left->val)
            {
                ret++;
                return {ret,true};
            }
            else
            {
                return {ret,false};
            }
        }
        else
        {
            int ret = 0;
            auto l = ust(n->left), r = ust(n->right);
            ret = l.first+r.first;
            if(l.second && r.second && n->val == n->left->val && n->val == n->right->val)
            {
                ret++;
                return {ret,true};
            }
            else
            {
                return {ret,false};
            }
        }
        
    }
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL)return 0;
        auto p =  ust(root);
        return p.first;
    }
};