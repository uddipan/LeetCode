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
        TreeNode* curr;
        modNode *parent;
        int sum;
        modNode(TreeNode* c, modNode *p, int s)
        {
            curr = c;
            parent = p;
            sum = s;
        }
    };
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>V;
        if(root == NULL)return V;
        queue<modNode*> Q;
        Q.push(new modNode(root,NULL,root->val));
        
        while(!Q.empty())
        {
            modNode *fr = Q.front();
            Q.pop();
            if((fr->curr->left == NULL) && (fr->curr->right == NULL) && fr->sum == sum)
            {
                vector<int>tmp;
                modNode *tn = fr;
                while(tn)
                {
                    tmp.insert(tmp.begin(),tn->curr->val);
                    tn = tn->parent;
                }
                
                V.push_back(tmp);
            }
            if(fr->curr->left != NULL)
            {
                Q.push(new modNode(fr->curr->left, fr,fr->curr->left->val + fr->sum));
            }
            if(fr->curr->right != NULL)
            {
                Q.push(new modNode(fr->curr->right, fr, fr->curr->right->val + fr->sum));
            }
        }
        return V;
    }
};