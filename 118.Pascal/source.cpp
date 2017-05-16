class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        if(numRows == 0)return res;
        res.push_back(vector<int>(1,1));
        for(int i=1; i<numRows; i++)
        {
            vector<int>tmp(1,1);
            for(int j=1; j<res[res.size()-1].size(); j++)
            {
                tmp.push_back(res[res.size()-1][j] + res[res.size()-1][j-1]);
            }
            tmp.push_back(1);
            res.push_back(tmp);
        }
        return res;
    }
};