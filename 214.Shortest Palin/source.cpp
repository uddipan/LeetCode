class Solution {
public:
    string shortestPalindrome(string s) {
        long base = 29, k = 1000000007;
        long H = 0, RH = 0;
        long pos = -1, pow = 1;
        for(int i=0; i<s.size(); i++)
        {
            H = (H*base + s[i] - 'a' + 1)%k;
            RH = (RH + pow*(s[i]- 'a' +1))%k;
            pow = (pow*base)%k;
            if(H == RH)pos = i;
        }
        if(pos >= s.size())return s;
        string tmp = s.substr(pos+1);
        reverse(tmp.begin(), tmp.end());
        return tmp + s;
    }
};