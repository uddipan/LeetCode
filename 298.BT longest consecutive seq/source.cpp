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
    int longestConsecutive(TreeNode* root) {
        if(root == NULL)return 0;
        int cnt = 1;
        queue<pair<TreeNode*, int>> Q;
        Q.push({root,1});
        while(!Q.empty())
        {
            pair<TreeNode*, int>fr = Q.front();
            Q.pop();
            if(fr.first->left)
            {
                if(fr.first->left->val == 1 + fr.first->val)
                {
                    Q.push({fr.first->left, fr.second + 1});
                    cnt = max(cnt, fr.second + 1);
                }
                else
                {
                    Q.push({fr.first->left,1});
                }
            }
            if(fr.first->right)
            {
                if(fr.first->right->val == 1 + fr.first->val)
                {
                    Q.push({fr.first->right, fr.second + 1});
                    cnt = max(cnt, fr.second + 1);
                }
                else
                {
                    Q.push({fr.first->right,1});
                }
            }
        }
        return cnt;
    }
};