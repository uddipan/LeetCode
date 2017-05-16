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
    int sumNumbers(TreeNode* root) {
        if(root == NULL)return 0;
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root,root->val));
        int sum = 0;
        while(!Q.empty())
        {
            pair<TreeNode*, int> fr = Q.front();
            Q.pop();
            if(fr.first->left == NULL  &&  fr.first->right == NULL)
            {
                sum += fr.second;
            }
            if(fr.first->left)
            {
                Q.push(make_pair(fr.first->left, 10*fr.second + fr.first->left->val));
            }
            if(fr.first->right)
            {
                Q.push(make_pair(fr.first->right, 10*fr.second + fr.first->right->val));
            }
        }
        return sum;
    }
};