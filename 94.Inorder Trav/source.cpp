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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>S;
        TreeNode* curr = root;
        vector<int>V;
        while(curr || !S.empty())
        {
            if(curr)
            {
                S.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = S.top();
                S.pop();
                V.push_back(curr->val);
                curr = curr->right;
            }
        }
        return V;
    }
};