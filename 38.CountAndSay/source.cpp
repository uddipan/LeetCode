class Solution {
public:
    string toString(int a)
    {
        string s;
        while(a)
        {
            s.insert(s.begin(),char(a%10) + '0');
            a/=10;
        }
        return s;
    }
    
    string countAndSay(int n) {
        string s ;
        s.push_back('1');
        if(n == 1)return s;
        for(int i = 2; i<=n; i++)
        {
            int cnt = 1;
            string t;
            for(auto u=1; u<s.size(); u++)
            {
                if(s[u] == s[u-1])
                {
                    cnt++;
                }
                else
                {
                    t.append(toString(cnt));
                    t.push_back(s[u-1]);
                    cnt = 1;
                }
            }
            t.append(toString(cnt));
            t.push_back(s[s.size()-1]);
            s = t;
        }
        return s;
    }
};