class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        set<int>S(nums.begin(), nums.end());
        int cnt = 1, maxCnt = 1;
        int prev = *(S.begin());
        for(auto it = next(S.begin(),1); it != S.end(); ++it)
        {
            if(*it - prev == 1)cnt++;
            else
            {
                maxCnt = max(maxCnt, cnt);
                cnt = 1;
            }
            prev = *it;
        }
        maxCnt = max(maxCnt, cnt);
        return maxCnt;
    }
};