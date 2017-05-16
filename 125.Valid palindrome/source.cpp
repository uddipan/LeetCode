class Solution {
public:
    void convert(char &c)
    {
        if(c >= 'A' && c<='Z')
        {
            c = c-'A'+'a';
        }
    }
    bool status(char c)
    {
        if(c >= '0' && c<='9')return true;
        if(c >= 'a' && c<='z')return true;
        return false;
    }
    bool isPalindrome(string s) {
        if(s.empty())return true;
        int idx1 = 0, idx2 = s.size() -1;
        while(idx1 < idx2)
        {
            convert(s[idx1]);
            convert(s[idx2]);
            if(!status(s[idx1]))
            {
                idx1++;
                continue;
            }
            if(!status(s[idx2]))
            {
                idx2--;
                continue;
            }
            if(s[idx1] != s[idx2])return false;
            idx1++;
            idx2--;
        }
        return true;
    }
};