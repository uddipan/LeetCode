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
    double closest, delta;
    void trav(TreeNode* n, double target)
    {
        if(n == NULL)return;
        if(delta > abs(double(n->val) - target))
        {
            delta = abs(double(n->val) - target);
            closest = n->val;
        }
        if(n->val == target)
        {
            return ;
        }
        if(n->val < target)
        {
            trav(n->right, target);
        }
        else
        {
            trav(n->left, target);
        }
    }
    int closestValue(TreeNode* root, double target) {
        if(root == NULL)return 0;
        closest = root->val;
        delta = abs(double(target) - root->val);
        trav(root, target);
        return int(closest);
    }
};