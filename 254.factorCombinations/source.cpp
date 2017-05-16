class Solution {
public:
    set<vector<int>>V;
    void getComb(int n, vector<int> &comb)
    {
        if(n <= 0)return;
        
        bool b = true;
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i == 0)
            {
                vector<int>inter(comb);
                inter.push_back(i);
                inter.push_back(n/i);
                sort(inter.begin(), inter.end());
                V.insert(inter);
                vector<int>tmp(comb);
                tmp.push_back(i);
                getComb(n/i, tmp);
                b = false;
            }
        }
    }
    vector<vector<int>> getFactors(int n) {
        vector<int>tmp;
        getComb(n, tmp);
        vector<vector<int>>VV;
        for(auto it = V.begin(); it !=V.end(); ++it)
        {
            VV.push_back(*it);
        }
        return VV;
    }
};