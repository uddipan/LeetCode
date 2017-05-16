/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)return ;
        bool toggle = true;
        TreeLinkNode * prev = NULL;
        queue<TreeLinkNode*>Q1,Q2;
        Q1.push(root);
        
        while(!Q1.empty() || !Q2.empty())
        {
            if(toggle)
            {
                while(!Q1.empty())
                {
                    TreeLinkNode* fr = Q1.front();
                    Q1.pop();
                    if(fr->left)
                    {
                        if(prev)prev->next = fr->left;
                        prev = fr->left;
                        Q2.push(fr->left);
                    }
                    if(fr->right)
                    {
                        if(prev)prev->next = fr->right;
                        prev = fr->right;
                        Q2.push(fr->right);
                    }
                }
            }
            else
            {
                while(!Q2.empty()){
                    TreeLinkNode* fr = Q2.front();
                    Q2.pop();
                    if(fr->left)
                    {
                        if(prev)prev->next = fr->left;
                        prev = fr->left;
                        Q1.push(fr->left);
                    }
                    if(fr->right)
                    {
                        if(prev)prev->next = fr->right;
                        prev = fr->right;
                        Q1.push(fr->right);
                    }
                }
            }
            prev = NULL;
            toggle = !toggle;
        }
    }
};