class Solution {
public:
    set<string>S;
    void helper(string word, string comb)
    {
        if(word.empty())
        {
            S.insert(comb);
            return;
        }
        
        for(int i=0; i<word.size(); i++)
        {
            string x, y(comb);
            y.append(to_string(i+1));
            if(i + 1 < word.size())
            {
                y.push_back(word[i+1]);
                x = word.substr(i+2);
            }
            helper(x,y);
            x = word.substr(i+1);
            y = comb;
            y.append(word.substr(0,i+1));
            helper(x,y);
        }
    }
    vector<string> generateAbbreviations(string word) {
        vector<string>V;
        if(word.empty()){V.push_back(word);return V;}
        
        helper(word, string());
        V = vector<string>(S.begin(), S.end());
        return V;
    }
};