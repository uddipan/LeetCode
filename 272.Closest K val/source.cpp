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
    multimap<double, TreeNode*>M;
    void InOrder(TreeNode* n, double target, int k)
    {
        if(n == NULL)return;
        InOrder(n->left, target, k);
        double tmp = abs(target - double(n->val));
        if(M.size() < k)
        {
            M.insert({tmp,n});
        }
        else
        {
            auto it = M.rbegin();
            if(it->first > tmp)
            {
                auto itr = M.end();
                itr--;
                M.erase(itr);
                M.insert({tmp,n});
            }
        }
        InOrder(n->right,target,k);
    }
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int>res;
        InOrder(root,target,k);
        for(auto it = M.begin(); it != M.end(); ++it)
        {
            auto n = it->second;
            res.push_back(n->val);
        }
        return res;
    }
};