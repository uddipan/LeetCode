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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> V;
        if(root == NULL)return V;
        queue<TreeNode*>Q1, Q2;
        bool status = true;
        Q1.push(root);
        while(!Q1.empty() || !Q2.empty())
        {
            if(status)
            {
                V.push_back(Q1.front()->val);
                while(!Q1.empty())
                {
                    TreeNode* fr = Q1.front();
                    Q1.pop();
                    if(fr->right)Q2.push(fr->right);
                    if(fr->left)Q2.push(fr->left);
                }
            }
            else
            {
                V.push_back(Q2.front()->val);
                while(!Q2.empty())
                {
                    TreeNode* fr = Q2.front();
                    Q2.pop();
                    if(fr->right)Q1.push(fr->right);
                    if(fr->left)Q1.push(fr->left);
                }
            }
            status = !status;
        }
        return V;
    }
};