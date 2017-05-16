class Solution {
public:
    
    bool isOneEditDistance(string s, string t) {
        if(s.empty() && t.empty())return false;
        int sz1 = s.length(), sz2 = t.length();
        if(abs(sz1 - sz2) > 1)return false;
        if(s.size() == t.size())
        {
            int diff = 0;
            for(auto i=0; i<s.size(); i++)
            {
                if(s[i] != t[i])diff++;
                if(diff > 1)return false;
            }
            if(diff == 0)return false;
            else return true;
        }
        else
        {
            
            if(s.size() < t.size())
            {
                string tmp = s;
                s = t;
                t = tmp;
            }
            int diff = 0;
            int idx = 0, idx2 = 0;
            while(idx < t.size())
            {
                if(s[idx+idx2] != t[idx])
                {
                    diff++;
                    idx2++;
                }
                else idx++;
                if(diff > 1)return false;
                
            }
            return true;
        }
    }
};