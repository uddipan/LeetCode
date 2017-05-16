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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> V;
        if(root == NULL)return V;
        stack<TreeNode*>S;
        S.push(root);
        while(!S.empty())
        {
            TreeNode *t = S.top();
            if(t->left || t->right)
            {
                S.pop();
                S.push(new TreeNode(t->val));
                if(t->right)S.push(t->right);
                if(t->left)S.push(t->left);
            }
            else
            {
                V.push_back(t->val);
                S.pop();
            }
        }
    }
};