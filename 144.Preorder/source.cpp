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
    void preOrd(vector<int> &A, TreeNode* n)
    {
        if(n == NULL)return;
        A.push_back(n->val);
        preOrd(A,n->left);
        preOrd(A, n->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>A;
        if(root == NULL)return A;
        //preOrd(A,root);// recursive
        
        //iterative
        stack<TreeNode*>S;
        S.push(root);
        while(!S.empty())
        {
            TreeNode* fr = S.top();
            S.pop();
            A.push_back(fr->val);
            if(fr->right)S.push(fr->right);
            if(fr->left)S.push(fr->left);
        }
        
        return A;
    }
};