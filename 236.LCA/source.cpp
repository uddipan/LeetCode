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
    pair<int, TreeNode*> lca(TreeNode* t, TreeNode* p, TreeNode* q)
    {
        if(t == NULL)return {0,NULL};
        
        auto L = lca(t->left,p,q);
        auto R = lca(t->right,p,q);
        
        if(L.first == 2)return L;
        if(R.first == 2)return R;
        
        int num_nodes = L.first + R.first + (p == t) + (q ==t);
        return {num_nodes, num_nodes == 2 ? t:NULL};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)return root;
        return lca(root,p,q).second;
    }
};