class Solution {
public:
    vector<vector<int>>V;
    void allcomb(vector<int>&num, vector<int> comb)
    {
        if(num.empty())
        {
            V.push_back(comb);
            return;
        }
        
        for(int i=0; i<num.size();i++)
        {
            vector<int>A(num);
            A.erase(A.begin()+i);
            vector<int>B(comb);
            B.push_back(num[i]);
            allcomb(A,B);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())return V;
        allcomb(nums, vector<int>());
        return V;
    }
};