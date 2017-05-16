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
    map<int,int>M;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int InStart,int InEnd, int PreStart, int PreEnd)
    {
        if(InStart >= InEnd  ||  PreStart >= PreEnd)
        {
            return NULL;
        }
        
        TreeNode *root = new TreeNode(preorder[PreStart]);
        int pos = M[preorder[PreStart]];// of root in inorder
        int sz = pos - InStart + 1;
        TreeNode *left = build(preorder,inorder,InStart, pos-1, PreStart+1,PreStart+sz);
        TreeNode *right = build(preorder, inorder, pos, InEnd, PreStart+sz, PreEnd);
        root->left = left;
        root->right = right;
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())return NULL;
        if(preorder.size() != inorder.size())return NULL;
        
        for(auto i=0; i<inorder.size(); i++)
        {
            M[inorder[i]] = i;
        }
        
        return build(preorder,inorder,0, inorder.size(), 0, preorder.size());
    }
};