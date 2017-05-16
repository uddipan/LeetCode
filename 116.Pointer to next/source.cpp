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
        queue<TreeLinkNode*>Q1,Q2;
        Q1.push(root);
        bool status = true;
        while(!Q1.empty() || !Q2.empty())
        {
            if(status)
            {
                TreeLinkNode* prev = NULL;
                while(!Q1.empty())
                {
                    auto fr = Q1.front();
                    Q1.pop();
                    if(prev != NULL)prev->next = fr;
                    prev = fr;
                    if(fr->left)Q2.push(fr->left);
                    if(fr->right)Q2.push(fr->right);
                }
            }
            else
            {
                TreeLinkNode* prev = NULL;
                while(!Q2.empty())
                {
                    auto fr = Q2.front();
                    Q2.pop();
                    if(prev != NULL)prev->next = fr;
                    prev = fr;
                    if(fr->left)Q1.push(fr->left);
                    if(fr->right)Q1.push(fr->right);
                }
            }
            status = !status;
        }
    }
};