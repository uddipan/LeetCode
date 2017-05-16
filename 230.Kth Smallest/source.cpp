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
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)return 0;
        TreeNode *curr = root;
        stack<TreeNode*>S;
        
        while(curr || !S.empty())
        {
            if(curr)
            {
                S.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = S.top();
                S.pop();
                k--;
                if(k == 0)return curr->val;
                curr = curr->right;
            }
        }
        return root->val;
    }
};