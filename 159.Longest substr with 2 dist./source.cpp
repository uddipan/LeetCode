class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty())return 0;
        int maxCnt = 0, cnt = 0;
        map<char,int> M;
        
        int idx1 = 0, idx2 = 0;
        while(idx2 < s.size())
        {
            auto it = M.find(s[idx2]);
            if(it != M.end() || M.size() < 2)
            {
                if(it != M.end())
                {
                    M[s[idx2]]++;
                }
                else
                {
                    M[s[idx2]] = 1;
                }
                cnt ++;
                idx2++;
            }
            else
            {
                maxCnt = max(maxCnt, cnt);
                while(idx1 < idx2)
                {
                    auto it2 = M.find(s[idx1]);
                    M[s[idx1]]--;
                    if(M[s[idx1]] == 0)
                    {
                        M.erase(it2);
                        idx1++;
                        break;
                    }
                    else idx1++;
                }
                cnt = idx2-idx1;
            }
        }
        maxCnt = max(maxCnt, cnt);
        return maxCnt;
    }
};