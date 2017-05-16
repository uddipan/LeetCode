class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string>S;
        if(n == 0)return S;
        if(n%2)
        {
            S.push_back("0");
            S.push_back("1");
            S.push_back("8");
            
            for(int j=3; j<=n; j+=2)
            {
                vector<string> T;
                for(int i=0; i<S.size(); i++)
                {
                    if(j != n)T.push_back("0" + S[i] + "0");
                    T.push_back("1" + S[i] + "1");
                    T.push_back("6" + S[i] + "9");
                    T.push_back("8" + S[i] + "8");
                    T.push_back("9" + S[i] + "6");
                }
                S = T;
            }
        }
        else
        {
            if(n > 2)S.push_back("00");
            S.push_back("11");S.push_back("69");
            S.push_back("88");S.push_back("96");
            for(int j=4; j<=n; j+=2)
            {
                vector<string> T;
                for(int i=0; i<S.size(); i++)
                {
                    if(j != n)T.push_back("0" + S[i] + "0");
                    T.push_back("1" + S[i] + "1");
                    T.push_back("6" + S[i] + "9");
                    T.push_back("8" + S[i] + "8");
                    T.push_back("9" + S[i] + "6");
                }
                S = T;
            }
        }
        return S;
    }
};