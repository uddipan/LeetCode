class Solution {
public:
    set<string>res;
    void helper(string word, string comb, int depth)
    {
        if(depth == 0)
        {
            res.insert(comb);
            return;
        }
        for(int i=0; i<word.size(); i++)
        {
            string x(word), y(comb);
            x.erase(x.begin()+i);
            y.push_back(word[i]);
            helper(x,y,depth-1);
        }
    }
    
    vector<string> generatePalindromes(string s) {
        vector<string> op;
        if(s.empty())return op;
        
        map<char,int>M;
        for(int i=0; i<s.size(); i++)
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
        
        string tmp;
        int cnt = 0;char c;
        for(auto it=M.begin(); it != M.end(); ++it)
        {
            if(it->second % 2 != 0)
            {
                cnt++;
                c = it->first;
            }
            if(cnt > 1)return op;
            for(int i=0; i< it->second/2; i++)
            {
                tmp.push_back(it->first);
            }
        }
        
        string comb;
        helper(tmp, comb, tmp.size());
        
        if(res.empty() && cnt)
        {
            string y;
            y.push_back(c);
            op.push_back(y);
            return op;
        }
        for(auto it = res.begin(); it != res.end(); ++it)
        {
            string z = *it, y = z;
            reverse(z.begin(), z.end());
            if(cnt)
            {
                y.push_back(c);
            }
            y.append(z);
            op.push_back(y);
        }
        return op;
    }
};