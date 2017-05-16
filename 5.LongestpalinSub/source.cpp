class Solution {
public:
    string longestPalindrome(string s) {
        int i,j;
        int len = 1;
        int locallen = 1;
        string palin;
        for(auto u=0; u<s.size(); u++)
        {
            i = u;
            j = u+1;
            locallen = 0;
            while((i>=0) && (j<s.size()) &&(s[i] == s[j]))
            {
                i--;
                j++;
                locallen+=2;
            }
            if(locallen > len)
            {
                len = locallen;
                palin = s.substr(i+1,len);
            }
            
            i = u-1;
            j = u+1;
            locallen = 1;
            while((i>=0) && (j<s.size()) &&(s[i] == s[j]))
            {
                i--;
                j++;
                locallen+=2;
            }
            if(locallen >= len)
            {
                len = locallen;
                palin = s.substr(i+1,len);
            }
        }
        return palin;
    }
};