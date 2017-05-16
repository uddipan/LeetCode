class Solution {
public:
    bool isValidSerialization(string pre) {
        if(pre.empty())return true;
        stack<char>S;
        unsigned u = 1;
        string preorder;
        while(u <= pre.size())
        {
            if(pre[u] == ',' || u == pre.size())
            {
                if(pre[u-1] == '#')
                    preorder.push_back('#');
                else
                    preorder.push_back('1');
            }
            u++;
        }
        
        u=0;
        while(u < preorder.size())
        {
            if(preorder[u] == '#' && !S.empty() && S.top() == '#')
            {
                S.pop();
                if(S.empty() || S.top() == '#')return false;
                S.pop();
            }
            else
            {
                S.push(preorder[u]);
                u++;
            }
        }
        return (S.size() == 1 && S.top() == '#');
    }
};