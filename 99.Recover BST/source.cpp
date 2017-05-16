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
    void recoverTree(TreeNode* root) {
        if(root == NULL)return ;
        int elem[2] = {INT_MIN,INT_MIN};
        vector<TreeNode*>n;
        TreeNode *curr=root, *final;
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
                int d = curr->val;
                if((elem[0] > elem[1]) && (d > elem[1]))
                {
                    n.push_back(final);
                }
                if((elem[0] < elem[1]) && (d < elem[1]))
                {
                    n.push_back(final);
                }
                elem[0] = elem[1];
                elem[1] = d;
                final = curr;
                curr = curr->right;
            }
        }
        if(n.size() == 2)
        {
            int d = n[0]->val;
            n[0]->val = n[1]->val;
            n[1]->val = d;
        }
        else
        {
            int d = n[0]->val;
            n[0]->val = final->val;
            final->val = d;
        }
        
    }
};