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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)return false;
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root,root->val));
        
        while(!Q.empty())
        {
            pair<TreeNode*, int> fr = Q.front();
            Q.pop();
            if((fr.first->left == NULL) && (fr.first->right == NULL) && fr.second == sum)
            {
                return true;
            }
            if(fr.first->left != NULL)
            {
                Q.push(make_pair(fr.first->left, fr.first->left->val + fr.second));
            }
            if(fr.first->right != NULL)
            {
                Q.push(make_pair(fr.first->right, fr.first->right->val + fr.second));
            }
        }
        return false;
    }
};