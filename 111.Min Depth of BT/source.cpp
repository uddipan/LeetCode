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
    int minDepth(TreeNode* root) {
        if(root == NULL)return 0;
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root,1));
        
        while(!Q.empty())
        {
            pair<TreeNode*,int> fr = Q.front();
            Q.pop();
            if(fr.first->left == NULL && fr.first->right == NULL)
            {
                return fr.second;
            }
            if(fr.first->left)Q.push(make_pair(fr.first->left,fr.second+1));
            if(fr.first->right)Q.push(make_pair(fr.first->right,fr.second+1));
        }
        return 0;
    }
};