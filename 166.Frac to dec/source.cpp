class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        long A = long(numerator), B = long(denominator);
        if((A >= 0)^(B >= 0))res +='-';
        
        res += to_string(A/B);
        if(A%B == 0)return res;
        res += ".";
        int sz = res.size();
        
        map<int,int>M;
        
        int cnt = res.size();
        int x = 10*(A/B), k = 10;
        while(x == 0){res += "0";k *= 10;x = (k*A)/B; M[0] = sz;}
        k /= 10;
        int y = (k*A)%B;
        while(y)
        {
            int x = 10*y/B;
            if(M.find(x) != M.end())
            {
                res.insert(res.begin()+M[x], '(');
                res.push_back(')');
                return res;
            }
            M[x] = cnt++;
            res += to_string(x);
            y = (10*y)%B;
        }
        
        return res;
    }
};