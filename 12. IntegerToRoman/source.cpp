class Solution {
public:
    string intToRoman(int num) {
        map<int,string>M;
        M[1] = "I"; M[4] = "IV"; M[5] = "V"; M[9] = "IX"; M[10] = "X";
        M[40] = "XL"; M[50] = "L"; M[90] = "XC"; M[100] = "C";
        M[400] = "CD"; M[500] = "D"; M[900] = "CM"; M[1000] = "M";
        string ret;
        
        while(num)
        {
            auto it = M.lower_bound(num);
            if(it == M.end())
            {
                it = prev(it);
            }
            else if(it->first > num)
            {
                it = prev(it);
            }
            ret += it->second;
            num -= it->first;
        }
        return ret;
    }
};