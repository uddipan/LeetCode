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
    vector<TreeNode*> helper(vector<int>nums)
    {
        if(nums.empty())return vector<TreeNode*>();
        vector<TreeNode*>ret;
        for(int i=0; i<nums.size(); i++)
        {
            vector<int>n1,n2;
            if(i != 0)n1 = vector<int>(nums.begin(),nums.begin()+i);
            if(i != nums.size()-1)n2 = vector<int>(nums.begin()+i+1,nums.end());
            vector<TreeNode*>res1 = helper(n1), res2 = helper(n2);
            if(res1.empty() && res2.empty())
            {
                ret.push_back(new TreeNode(nums[i]));
            }
            else if(res1.empty())
            {
                for(int u=0; u<res2.size(); u++)
                {
                    TreeNode* root = new TreeNode(nums[i]);
                    root->right = res2[u];
                    ret.push_back(root);
                }
            }
            else if(res2.empty())
            {
                for(int u=0; u<res1.size(); u++)
                {
                    TreeNode* root = new TreeNode(nums[i]);
                    root->left = res1[u];
                    ret.push_back(root);
                }
            }
            else
            {
                for(auto u=0; u<res1.size(); u++)
                {
                    for(auto v=0; v<res2.size(); v++)
                    {
                        TreeNode* root = new TreeNode(nums[i]);
                        root->left = res1[u];
                        root->right = res2[v];
                        ret.push_back(root);
                    }
                }
            }
        }
        return ret;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)return vector<TreeNode*>();
        vector<int>N;
        for(int i=1; i<=n; i++)N.push_back(i);
        return helper(N);
    }
};