class Solution {
public:
    int sz;
    map<string,int>dict;
    bool check(string s)
    {
        //if(s.size() != sz*dict.size())return false;
        map<string,int>tmp;
        for(int i=0; i<s.size(); i +=sz)
        {
            string t = s.substr(i,sz);
            if(dict.find(t) == dict.end())return false;
            if(tmp.find(t) != tmp.end())
            {
                if(tmp[t] >= dict[t])return false;
                else tmp[t]++;
            }
            else
            {
                tmp[t] = 1;
            }
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res;
        if(s.empty() || words.empty())return res;
        sz = words[0].size();
        if(s.size() < sz*words.size())return res;
        for(int i=0; i<words.size(); i++)
        {
            if(dict.find(words[i]) != dict.end())
            {
                dict[words[i]]++;
            }
            else
            {
                dict[words[i]] = 1;
            }
        }
        
        for(int i=0; i<=s.size()-sz*words.size(); i++)
        {
            if(check(s.substr(i,sz*words.size())))
            {
                res.push_back(i);
            }
        }
        return res;
    }
};