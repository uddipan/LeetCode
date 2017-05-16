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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>V;
        if(root == NULL)return V;
        queue<TreeNode*>Q1,Q2;
        bool status = true;
        Q1.push(root);
        while(!Q1.empty() || !Q2.empty())
        {
            vector<int>tmp;
            if(status)
            {
                while(!Q1.empty())
                {
                    auto fr = Q1.front();
                    tmp.push_back(fr->val);
                    Q1.pop();
                    if(fr->left)
                    {
                        Q2.push(fr->left);
                    }
                    if(fr->right)
                    {
                        Q2.push(fr->right);
                    }
                }
            }
            else
            {
                while(!Q2.empty())
                {
                    auto fr = Q2.front();
                    tmp.push_back(fr->val);
                    Q2.pop();
                    if(fr->left)
                    {
                        Q1.push(fr->left);
                    }
                    if(fr->right)
                    {
                        Q1.push(fr->right);
                    }
                }
            }
            status = !status;
            V.insert(V.begin(),tmp);
        }
        return V;
    }
};