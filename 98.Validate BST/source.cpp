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
    struct modNode
    {
        TreeNode *curr;
        long min, max;
        modNode(TreeNode *c, long m, long n)
        {
            curr = c;
            min = m;
            max = n;
        }
    };
    bool isValidBST(TreeNode* root) {
        if(root == NULL)return true;
        queue<modNode*>Q;
        Q.push(new modNode(root, LONG_MIN, LONG_MAX));
        
        while(!Q.empty())
        {
            modNode* fr = Q.front();
            Q.pop();
            pair<int,int> range;
            int valC = fr->curr->val;
            if(valC <= fr->min || valC >= fr->max)return false;
            
            if(fr->curr->left)
            {
                Q.push(new modNode(fr->curr->left,fr->min, valC));
            }
            if(fr->curr->right)
            {
                Q.push(new modNode(fr->curr->right,valC, fr->max));
            }
        }
        return true;
    }
};