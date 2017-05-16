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
    pair<TreeNode*, TreeNode*> flat(TreeNode* root)
    {
        if(root == NULL)
        {
            TreeNode* t = NULL;
            return make_pair(t,t);
        }
        
        pair<TreeNode*, TreeNode*>L = flat(root->left);
        pair<TreeNode*, TreeNode*>R = flat(root->right);
        
        root->left = NULL;
        if(L.first != NULL)
        {
            root->right = L.first;
            L.second->right = R.first;
        }
        else
        {
            root->right = R.first;
        }
        
        if(R.first != NULL)
        {
            return make_pair(root, R.second);
        }
        else if(L.first != NULL)
        {
            return make_pair(root,L.second);
        }
        else
        {
            return make_pair(root,root);
        }
    }
    
    void flatten(TreeNode* root) {
        if(root == NULL)return ;
        pair<TreeNode*, TreeNode*>P = flat(root);
    }
};