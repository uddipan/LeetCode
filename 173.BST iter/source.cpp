/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> S;
    TreeNode *curr;
    BSTIterator(TreeNode *root) {
        curr = root;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (curr || !S.empty());
    }
    
    /** @return the next smallest number */
    int next() {
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
                TreeNode * res = curr;
                curr = curr->right;
                return res->val;
            }
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */