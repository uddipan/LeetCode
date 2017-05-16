class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char,int>M;
        for(auto i=0; i<s.size(); i++)
        {
            if(M.find(s[i]) == M.end())
            {
                M[s[i]] = 1;
            }
            else
            {
                M[s[i]]++;
            }
        }
        int cnt = 0;
        for(auto it = M.begin(); it !=M.end(); ++it)
        {
            if(it->second % 2 ==1)cnt++;
        }
        return (cnt <= 1);
    }
};