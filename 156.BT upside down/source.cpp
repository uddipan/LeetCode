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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == NULL)return root;
        stack<pair<TreeNode*, TreeNode*>>S;
        pair<TreeNode*, TreeNode*> curr = {root, NULL};
        S.push(curr);
        while(curr.first)
        {
            S.push({curr.first->left,curr.first->right});
            curr = {curr.first->left, NULL};
        }
        S.pop();
        TreeNode* T = S.top().first, *prev = NULL;
        while(!S.empty())
        {
            auto top = S.top();
            S.pop();
            top.first->left = top.second;
            top.first->right = NULL;
            if(prev)prev->right = top.first;
            prev = top.first;
        }
        return T;
    }
};