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
    struct aux
    {
        pair<int,int> range;
        bool status;
        int len;
        aux(int l, bool b, pair<int,int> p)
        {
            range = p;
            len = l;
            status = b;
        }
    };
    aux DP(TreeNode *p)
    {
        if(p == NULL)
        {
            return aux(0,true,{INT_MAX,INT_MIN});
        }
        
        aux L = DP(p->left);
        aux R = DP(p->right);
        
        int left = L.range.first, right = R.range.second;
        if(p->left == NULL)left = p->val;
        if(p->right == NULL)right = p->val;
        
        if(L.status && R.status && p->val > L.range.second && p->val < R.range.first )
        {
            return aux((L.len + R.len) + 1, true, {left,right});
        }
        
        else
        {
            return aux(max(L.len, R.len), false, {INT_MAX,INT_MIN});
        }
    }
    
    int largestBSTSubtree(TreeNode* root) {
        if(root == NULL)return 0;
        aux A = DP(root);
        return A.len;
    }
    
};