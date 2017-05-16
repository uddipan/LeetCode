/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if(root == NULL)return s;
        queue<TreeNode*>Q;
        Q.push(root);
        s.append(to_string(root->val));
        while(!Q.empty())
        {
            auto fr = Q.front();
            Q.pop();
            
            if(fr->left)
            {
                Q.push(fr->left);
                s.append("," + to_string(fr->left->val));
            }
            else
            {
                s.append(",#");
            }
            if(fr->right)
            {
                Q.push(fr->right);
                s.append("," + to_string(fr->right->val));
            }
            else
            {
                s.append(",#");
            }
        }
        return s;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return NULL;
        int idx = 0;
        queue<TreeNode*>Q;
        while(data[idx] != ',' && idx <data.size())
        {
            idx++;
        }
        TreeNode * root = new TreeNode(atoi((data.substr(0,idx)).c_str()));
        idx++;
        Q.push(root);
        while(idx < data.size())
        {
            auto fr = Q.front();
            Q.pop();
            int cidx = idx;
            while(data[idx] != ',' && idx <data.size())
            {
                idx++;
            }
            string tmp = data.substr(cidx,idx - cidx);
            
            if(tmp != "#")
            {
                fr->left = new TreeNode(atoi(tmp.c_str()));
                Q.push(fr->left);
            }
            idx++;
            cidx = idx;
            while(data[idx] != ',' && idx <data.size())
            {
                idx++;
            }
            tmp = data.substr(cidx,idx - cidx);
            
            if(tmp != "#")
            {
                fr->right = new TreeNode(atoi(tmp.c_str()));
                Q.push(fr->right);
            }
            idx++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));