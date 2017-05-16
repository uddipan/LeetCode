class Solution {
public:
    bool isValid(string s) {
        stack<char>St;
        for(auto i=0; i<s.size(); i++)
        {
            if((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
            {
                St.push(s[i]);
            }
            else if(s[i] == ')')
            {
                if(St.empty())return false;
                char c = St.top();
                if(c != '(')return false;
                St.pop();
            }
            else if(s[i] == '}')
            {
                if(St.empty())return false;
                char c = St.top();
                if(c != '{')return false;
                St.pop();
            }
            else if(s[i] == ']')
            {
                if(St.empty())return false;
                char c = St.top();
                if(c != '[')return false;
                St.pop();
            }
            
        }
        return St.empty();
    }
};