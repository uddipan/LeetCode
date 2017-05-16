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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> V;
        if(root == NULL)return V;
        map<int, vector<int>>M;
        queue<pair<TreeNode*,int>>Q;
        Q.push({root,0});
        while(!Q.empty())
        {
            auto fr = Q.front();
            Q.pop();
            M[fr.second].push_back(fr.first->val);
            if(fr.first->left)Q.push({fr.first->left, fr.second-1});
            if(fr.first->right)Q.push({fr.first->right, fr.second+1});
        }
        
        for(auto it = M.begin(); it != M.end(); ++it)
        {
            V.push_back(it->second);
        }
        return V;
    }
};