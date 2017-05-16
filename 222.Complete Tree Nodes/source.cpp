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
    int diamL(TreeNode *N)
    {
        if(N == NULL)return 0;
        return diamL(N->left) + 1;
    }
    int diamR(TreeNode *N)
    {
        if(N == NULL)return 0;
        return diamR(N->right) + 1;
    }
    int span(TreeNode *N)
    {
        if(N == NULL)return 0;
        int L = diamL(N->left), R = diamR(N->right);
        if(L == R)
        {
            return pow(2,L+1) - 1;
        }
        return span(N->left) + span(N->right) + 1;
        
    }
    int countNodes(TreeNode* root) {
        return span(root);
    }
};