class Solution {
public:
    bool isNumber(string s) {
        if(s.empty())return 0;
        //leading space
        int i=0;
        while(i < s.size() && s[i] == ' ')i++;
        if(i == s.size())return false;
        if(s[i] == '+' || s[i] == '-')i++;
        
        int cnt = 0;
        while(i<s.size() && isdigit(s[i]))
        {
            cnt++;
            i++;
        }
        if(s[i] == '.')i++;
        while(i<s.size() && isdigit(s[i]))
        {
            cnt++;
            i++;
        }
        if(cnt == 0)return false;
        if(s[i]=='e')
        {
            i++;
            if(s[i] == '+' || s[i] == '-')i++;
            if(!isdigit(s[i]))return false;
            while(i<s.size() && isdigit(s[i]))i++;
        }
        while(i<s.size() && s[i] == ' ')i++;
        if(i==s.size())return true;
        return false;
    }
};