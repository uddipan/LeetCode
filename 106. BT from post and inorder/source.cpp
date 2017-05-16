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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int start, int end, int rootidx)
    {
        if(start > end)return NULL;
        TreeNode* root = new TreeNode(postorder[rootidx]);
        int pos = start;
        while( postorder[rootidx] != inorder[pos])
        {
            pos++;
        }
        root->left = helper(inorder, postorder, start, pos-1, rootidx-end+pos-1);
        root->right = helper(inorder, postorder, pos+1, end, rootidx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())return NULL;
        return helper(inorder,postorder,0,inorder.size()-1,inorder.size()-1);
    }
};