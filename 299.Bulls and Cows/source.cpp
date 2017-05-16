class Solution {
public:
    string itoaM(long n)
    {
        string s;
        if(n == 0)return "0";
        bool b = false;
        if(n < 0)
        {
            b = true;
            n = -n;
        }
        while(n)
        {
            s.insert(s.begin(),char(n%10) + '0');
            n/=10;
        }
        if(b) s.insert(s.begin(), '-');
        return s;
    }
    string getHint(string secret, string guess) {
        map<int,int>M;
        int cow = 0, bull = 0;
        for(int i=0; i<secret.size(); i++)
        {
            if(M.find(secret[i]) == M.end())
            {
                M[secret[i]] = 1;
            }
            else
            {
                M[secret[i]]++;
            }
            
        }
        
        for(int i=0; i<guess.size(); i++)
        {
            if(i < secret.size() && secret[i] == guess[i])
            {
                cow++;
                M[secret[i]]--;
                if(M[secret[i]] == 0)M.erase(secret[i]);
                guess[i] = '#';
            }
        }
        for(int i=0; i<guess.size(); i++)
        {
            if(M.find(guess[i]) != M.end())
            {
                bull++;
                M[guess[i]]--;
                if(M[guess[i]] == 0)M.erase(guess[i]);
            }
        }
        string ret;
        ret.append(itoaM(cow));
        ret.push_back('A');
        ret.append(itoaM(bull));
        ret.push_back('B');
        return ret;
    }
};