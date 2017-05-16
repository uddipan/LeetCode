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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>V;
        if(root == NULL)return V;
        queue<TreeNode*>Q1,Q2;
        Q1.push(root);
        bool toggle = true;
        while(!Q1.empty() || !Q2.empty())
        {
            vector<int>tmp;
            if(toggle)
            {
                while(!Q1.empty())
                {
                    TreeNode* fr = Q1.front();
                    Q1.pop();
                    tmp.push_back(fr->val);
                    if(fr->left)Q2.push(fr->left);
                    if(fr->right)Q2.push(fr->right);
                }
            }
            else
            {
                while(!Q2.empty())
                {
                    TreeNode* fr = Q2.front();
                    Q2.pop();
                    tmp.push_back(fr->val);
                    if(fr->left)Q1.push(fr->left);
                    if(fr->right)Q1.push(fr->right);
                }
            }
            toggle = !toggle;
            V.push_back(tmp);
        }
        
        return V;
    }
};