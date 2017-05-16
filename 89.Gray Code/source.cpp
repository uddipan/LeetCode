class Solution {
public:
    vector<string>gray(int n)
    {
        vector<string> ret;
        if(n == 1)
        {
            ret.push_back("0");
            ret.push_back("1");
            return ret;
        }
        ret = gray(n-1);
        int sz = ret.size();
        for(int i=sz-1; i>=0; i--)
        {
            ret.push_back("1" + ret[i]);
            ret[i] = "0" + ret[i];
        }
        return ret;
    }
    
    int toDec(string &s)
    {
        int sum = 0;
        for(auto i=0; i<s.size(); i++)
        {
            sum = sum*2 + int(s[i] - '0');
        }
        return sum;
    }
    
    vector<int> grayCode(int n) {
        vector<int>ret;
        if(n == 0)return vector<int>(1,0);
        vector<string> V = gray(n);
        for(int i=0; i<V.size(); i++)
        {
            ret.push_back(toDec(V[i]));
        }
        return ret;
    }
};