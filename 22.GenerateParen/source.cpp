class Solution {
public:
    void genPar(int left, int right, string S, vector<string>&VV)
    {
        if((left == 0) && (right == 0))
        {
            VV.push_back(S);
        }
        if(left > 0)
        {
            genPar(left - 1, right, S+ '(', VV);
        }
        if(left < right)
        {
            genPar(left, right - 1, S + ')', VV);
        }
    }
    vector<string> generateParenthesis(int n) {
        if(n == 0)return vector<string>();
        vector<string> VV;
        string S;
        genPar(n,n,S,VV);
        return VV;
    }
};