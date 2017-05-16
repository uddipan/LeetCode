class Solution {
public:
    int titleToNumber(string s) {
        if(s.empty())return 0;
        int ret = 0;
        for(int i=0; i<s.size();i++)
        {
            int x = int(s[i] - 'A') + 1;
            ret = ret*26 + x;
        }
        return ret;
    }
};