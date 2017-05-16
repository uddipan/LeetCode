class Solution {
public:
    vector<vector<int>>V;
    void comb(vector<int> &num, vector<int> res, int target)
    {
        if(target < 0)return;
        if(target == 0)
        {
            sort(res.begin(), res.end());
            V.push_back(res);
            return;
        }
        for(int i=0; i<num.size(); i++)
        {
            vector<int>A(num.begin()+i, num.end());
            vector<int>B(res);
            B.push_back(num[i]);
            comb(A,B,target - num[i]);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty())return V;
        comb(candidates, vector<int>(), target);
        return V;
    }
};