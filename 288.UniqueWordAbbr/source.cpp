class ValidWordAbbr {
public:
    map<string,set<string>>M;
    string itoaM(int n)
    {
        string s;
        if(n == 0)return "0";
        while(n)
        {
            s.insert(s.begin(),char(n%10) + '0');
            n/=10;
        }
        return s;
    }
    
    string abbr(string s)
    {
        if(s.size() < 3)return s;
        int cnt = 0;
        for(int i=1; i<s.size() - 1; i++)
        {
            cnt++;
        }
        string t;
        t.push_back(s[0]);
        t += itoaM(cnt);
        t.push_back(s[s.size()-1]);
        return t;
    }
    ValidWordAbbr(vector<string> &dictionary) {
        for(auto i=0; i<dictionary.size(); i++)
        {
            string s = abbr(dictionary[i]);
            if(M.find(s) == M.end())
            {
                M[s] = set<string>();
            }
            M[s].insert(dictionary[i]);
        }
    }
    
    bool isUnique(string word) {
        string s = abbr(word);
        if(M.find(s) == M.end())return true;
        else
        {
            return(M[s].size() == 1 && *M[s].begin() == word);
        }
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");