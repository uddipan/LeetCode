class Solution {
public:
    int myAtoi(string str) {
        int idx = 0;
        while(str[idx] == ' ')idx++;
        if(str[idx] != '+' && str[idx] != '-' && (str[idx] < '0' || str[idx] > '9') )
            return 0;
        
        int sgn = 1;
        if(str[idx] == '-')sgn = -1;
        if(str[idx] == '-' || str[idx] == '+')idx++;
        
        str = str.substr(idx);
        while(!str.empty() && (str[str.size()-1] < '0' || str[str.size()-1] > '9'))
            str.pop_back();
        
        long num = 0;
        idx = 0;
        while(idx < str.size())
        {
            if(str[idx] < '0' || str[idx] > '9')break;
            num = 10*num + int(str[idx] - '0');
            if(num > INT_MAX){num = -1;break;}
            idx++;
        }
        if(num == -1 && sgn == 1)return INT_MAX;
        if(num == -1 && sgn == -1)return INT_MIN;
        num *= sgn;
        return num < INT_MIN ? INT_MIN:(num > INT_MAX? INT_MAX : num);
        
    }
};