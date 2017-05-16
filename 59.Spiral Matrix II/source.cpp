class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>fact(n+1,1);
        k--;
        for(int i=1; i<=n; i++)
        {
            fact[i] = i*fact[i-1];
        }
        if(k > fact[n])return "";
        
        string s = "123456789";
        string res;
        int cnt = n-1, K = k;
        while(cnt >= 0)
        {
            int idx = K/fact[cnt];
            res.push_back(s[idx]);
            s.erase(s.begin()+idx);
            K = K%fact[cnt];
            cnt--;
        }
        return res;
    }
};