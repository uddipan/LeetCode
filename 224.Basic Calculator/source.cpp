class Solution {
public:
    int calculate(string s) {
        if(s.empty())return 0;
        int res = 0;
        stack<int>S;
        int sign = 1;
        int start = 0;
        while(start < s.size())
        {
            if(s[start] >= '0' && s[start] <= '9')
            {
                int j = 0;
                while(s[start+j] >= '0' && s[start+j] <= '9')
                {
                    j++;
                }
                res += sign*atoi(s.substr(start,j).c_str());
                start += j-1;
            }
            else if(s[start] == '(')
            {
                S.push(res);
                S.push(sign);
                res = 0;
                sign = 1;
            }
            else if(s[start] == ')')
            {
                res = res*S.top();
                S.pop();
                res += S.top();
                S.pop();
            }
            else if(s[start] == '+')
            {
                sign = 1;
            }
            else if(s[start] == '-')
            {
                sign = -1;
            }
            start++;
        }
        return res;
    }
    
};