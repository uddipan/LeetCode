class Solution {
public:
    map<char,string>keypad;
    vector<string>V;
    
    void generate(string S, string T)
    {
        if(S.empty())
        {
            V.push_back(T);
            return;
        }
        
        char c = S[0];
        string comb = keypad[S[0]];
        
        for(auto i=0; i<comb.size();i++)
        {
            string t = T;
            t.push_back(comb[i]);
            string s;
            if(S.size() > 1)s = S.substr(1);
            generate(s,t);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return vector<string>();
        keypad['2'] = "abc";
        keypad['3'] = "def";
        keypad['4'] = "ghi";
        keypad['5'] = "jkl";
        keypad['6'] = "mno";
        keypad['7'] = "pqrs";
        keypad['8'] = "tuv";
        keypad['9'] = "wxyz";
        
        generate(digits,string());
        return V;
    }
};