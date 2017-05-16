class Solution {
public:
    int helper(string s)
    {
        if(s.empty())return 0;
        int idx = 0;
        int prevSymbol = 1, currSymbol = 1;
        int prevToken = 0, currToken = 0;
        while(idx < s.size())
        {
            if(s[idx] == '+' || s[idx] == '-')
            {
                if(currSymbol == 1)
                {
                    currToken += prevToken;
                }
                if(currSymbol == 2)
                {
                    currToken = prevToken-currToken;
                }
                prevSymbol = currSymbol;
                if(s[idx] == '+')currSymbol = 1;
                else currSymbol = 2;
                
            }
            
            else if(s[idx] == '*')
            {
                prevSymbol = currSymbol;
                currSymbol = 3;
            }
            else if(s[idx] == '/')
            {
                prevSymbol = currSymbol;
                currSymbol = 4;
            }
            else if (s[idx] >='0' && s[idx] <='9')
            {
                int j = 0;
                while(s[idx+j] >='0' && s[idx+j] <='9')
                {
                    j++;
                }
                int tmp = atoi(s.substr(idx, j).c_str());
                if(currSymbol == 3)
                {
                    currToken *= tmp;
                    currSymbol = prevSymbol;
                }
                else if(currSymbol == 4)
                {
                    currToken /= tmp;
                    currSymbol = prevSymbol;
                }
                else
                {
                    prevToken = currToken;
                    currToken = tmp;
                }
                
                idx +=j-1;
            }
            idx++;
        }
        
        if(currSymbol == 1)return prevToken + currToken;
        else return prevToken - currToken;
    }
    int calculate(string s) {
        return helper(s);
    }
};