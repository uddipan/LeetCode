class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.empty())return true;
        stack<int>S;
        vector<int>inorder;
        for(int i=0; i<preorder.size(); i++)
        {
            while(!S.empty() && S.top() < preorder[i])
            {
                inorder.push_back(S.top());
                S.pop();
            }
            S.push(preorder[i]);
        }
        while(!S.empty())
        {
            inorder.push_back(S.top());
            S.pop();
        }
        for(int i=1; i<inorder.size(); i++)
        {
            if(inorder[i] < inorder[i-1])return false;
        }
        return true;
    }
};