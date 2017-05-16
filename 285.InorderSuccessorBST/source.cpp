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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == NULL)return NULL;
        if(p->right)
        {
            TreeNode *q = p->right, *tmp = q;
            while(q)
            {
                tmp = q;
                q = q->left;
            }
            return tmp;
        }
        else
        {
            TreeNode* q = root, *tmp = NULL;
            while(q != p)
            {
                if(q->val < p->val)
                {
                    q = q->right;
                }
                else
                {
                    tmp = q;
                    q = q->left;
                }
            }
            return tmp;
        }
    }
};