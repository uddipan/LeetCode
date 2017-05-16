class Solution {
public:
    int totalCnt;
    static bool is_valid(vector<int> &comb)
    {
        int sz = comb.size()-1;
        for(int i=0; i<sz; i++)
        {
            int diff = abs(comb[i] - comb[sz]);
            if(diff == 0 || diff == sz-i)return false;
        }
        return true;
    }
    
    void helper(int n, int idx, vector<int> &comb)
    {
        if(idx == n)
        {
            totalCnt++;
            return;
        }
        for(int i=0; i<n; i++)
        {
            comb.push_back(i);
            if(is_valid(comb))
            {
                helper(n,idx+1,comb);
            }
            comb.pop_back();
        }
    }
    int totalNQueens(int n) {
        totalCnt = 0;
        if(n == 0)return totalCnt;
        vector<int>comb;
        helper(n,0,comb);
        return totalCnt;
    }
};